#!/usr/bin/env python3
"""probe.py -- safe opcode probe harness for the HISKA HX-KEG450 keyboard.

The HX-KEG450 exposes two vendor HID interfaces:

    0xFF13  64-byte FEATURE reports   control channel: `04 xx` commands + status
    0xFF68  4096-byte OUTPUT reports  image channel: screen pages + per-page ACK

This tool only ever *talks to the control channel*. It exists so a hardware
owner can probe the unknown `04 xx` opcode family (lighting, keymaps, macros,
clock, ...) without hand-writing inline python for every try.

SAFETY MODEL
------------
1. Nothing is opened unless the command line contains ``--i-understand``.
   Discovery alone (``discover``, and the first lines of every other command)
   reads *sysfs report descriptors only* and never opens /dev/hidraw*.
2. Opcodes that can change device state are refused unless ``--allow-writes``
   is also passed (risk levels: read-only | cosmetic | state-changing |
   dangerous, see opcodes.yaml).
3. ``dangerous`` opcodes and the hard-deny list are refused **outright**,
   even with every flag, even in --dry-run. There is no override.
4. Opcodes that are not classified in opcodes.yaml are refused on hardware
   (they are "unknown risk"); pass ``--allow-unknown --allow-writes`` only
   when you really mean to probe an unclassified byte.
5. ``--dry-run`` never opens anything. It prints the exact 65-byte frame it
   would hand to ioctl(HIDIOCSFEATURE) and the intended read operations.
6. ``--replay`` re-applies a captured/labelled sequence, but re-checks every
   frame against the policy first; dangerous frames abort the replay.

Framing rules implemented here (verified on hardware, see
../hiska-keg450-lcd/docs/PROTOCOL.md):

    SET:  ioctl(fd, HIDIOCSFEATURE(65), b"\\x00" + payload_64)
    GET:  ioctl(fd, HIDIOCGFEATURE(65), buf_65) -> strip buf[0] -> 64-byte reply
    reply byte 3: 0x01 accepted, 0xFF rejected, 0x00 no verdict / ignored
    commands >= 35 ms apart; >= 1 ms between a SET and its GET.

Library use::

    from probe import Probe, Policy, SafetyError

    policy = Policy.load("opcodes.yaml")
    with Probe.connect(i_understand=True, policy=policy) as pr:
        reply = pr.send(b"\\x04\\x18")                 # begin
        print(reply.status_name, reply.hexdump())
        info = pr.query(b"\\x04\\xF5", packets=9)      # read key colours

Exit codes: 0 ok, 1 status/expectation mismatch, 2 safety gate / usage,
3 hard-denied or unclassified opcode, 4 device/transport error.

stdlib only. Python 3.7+.
"""
from __future__ import annotations

import argparse
import fcntl
import glob
import json
import os
import re
import select
import sys
import time
from dataclasses import dataclass, field
from typing import Any, Callable, Iterable, Optional, Sequence

__version__ = "1.0.0"

# --------------------------------------------------------------------------- #
# constants
# --------------------------------------------------------------------------- #
VENDOR_ID = 0x05AC
PRODUCT_ID = 0x024F

USAGE_IMAGE = 0xFF68
USAGE_CONTROL = 0xFF13
IMAGE_PREFIX = b"\x06\x68\xff"       # report descriptor starts with Usage Page 0xFF68
CONTROL_PREFIX = b"\x06\x13\xff"     # report descriptor starts with Usage Page 0xFF13

REPORT_ID = 0x00
PAYLOAD_LEN = 64                      # report payload the firmware sees
BUF_LEN = 65                          # what the kernel wants (report id + payload)
SET_GET_DELAY = 0.002                 # >= 1 ms between SET and GET (read-too-fast = phantom ACK)
CMD_DELAY = 0.035                     # vendor cmd_delaytime = 35 ms
DRAIN_TIMEOUT = 0.02
DRAIN_LIMIT = 32
DEFAULT_TIMEOUT = 0.30

STATUS_NAMES = {0x01: "ok", 0xFF: "rejected", 0x00: "no-verdict"}
RISK_LEVELS = ("read-only", "cosmetic", "state-changing", "dangerous")
WRITE_RISKS = ("cosmetic", "state-changing")

EXIT_OK = 0
EXIT_MISMATCH = 1
EXIT_GATE = 2
EXIT_DENIED = 3
EXIT_DEVICE = 4

DEFAULT_OPCODES = os.path.join(os.path.dirname(os.path.abspath(__file__)), "opcodes.yaml")

#: Defence in depth: these are refused even if opcodes.yaml is edited to say
#: otherwise. opcodes.yaml's hard_deny list can only *add* to this set.
BUILTIN_HARD_DENY = {
    (0x04, 0x0F): "factory reset / erase (dangerous; unverified on this model)",
    (0x04, 0x7F): "reserved / firmware-adjacent opcode (dangerous; semantics unknown)",
}

SAFETY_EPILOG = """\
safety:
  discover and --dry-run never open /dev/hidraw*. Every other command needs
  --i-understand before it will open the control node; state-changing opcodes
  additionally need --allow-writes. Dangerous opcodes are refused outright.
  Run --dry-run first.

examples:
  ./probe.py discover
  ./probe.py opcodes
  ./probe.py send "04 18" --dry-run
  ./probe.py send "04 18" --dry-run --payload ""
  ./probe.py poll --dry-run
  ./probe.py replay capture.jsonl --dry-run
  sudo ./probe.py poll --i-understand            # real read-only query
  sudo ./probe.py send "04 18" --i-understand --allow-writes
"""


# --------------------------------------------------------------------------- #
# errors
# --------------------------------------------------------------------------- #
class ProbeError(Exception):
    exit_code = EXIT_GATE


class SafetyError(ProbeError):
    exit_code = EXIT_GATE


class PolicyError(ProbeError):
    exit_code = EXIT_GATE


class DeviceNotFound(ProbeError):
    exit_code = EXIT_DEVICE


class TransportError(ProbeError):
    exit_code = EXIT_DEVICE


class PolicyDenied(ProbeError):
    def __init__(self, decision: "Decision"):
        self.decision = decision
        super().__init__("; ".join(decision.messages) or "refused by policy")
        self.exit_code = decision.exit_code


# --------------------------------------------------------------------------- #
# small utilities
# --------------------------------------------------------------------------- #
def fmt_bytes(data: bytes) -> str:
    """Uppercase space-separated hex."""
    return " ".join(f"{b:02X}" for b in data)


def fmt_opcode(opcode: bytes) -> str:
    return fmt_bytes(opcode)


def parse_hex_bytes(text: Any) -> bytes:
    """Parse user/CAPTURE hex into bytes.

    Accepts ``"04 18"``, ``"0418"``, ``"0x04,0x18"``, ``"04-18"`` and a JSON
    list of ints. Separators are whitespace, comma, semicolon, colon, dash and
    underscore. Raises ValueError on junk.
    """
    if isinstance(text, (bytes, bytearray)):
        return bytes(text)
    if isinstance(text, list):
        out = bytearray()
        for item in text:
            if not isinstance(item, int) or not 0 <= item <= 0xFF:
                raise ValueError(f"payload list must contain bytes 0-255, got {item!r}")
            out.append(item)
        return bytes(out)
    s = str(text).strip()
    if not s:
        return b""
    s = re.sub(r"(?i)0x", "", s)
    tokens = [t for t in re.split(r"[\s,;:_\-]+", s) if t]
    out = bytearray()
    for token in tokens:
        if len(token) == 1:
            token = "0" + token
        if len(token) % 2:
            raise ValueError(f"odd-length hex token {token!r} (bytes are 2 hex digits)")
        if not re.fullmatch(r"[0-9a-fA-F]+", token):
            raise ValueError(f"not hex: {token!r}")
        out += bytes.fromhex(token)
    return bytes(out)


def parse_opcode(text: Any) -> bytes:
    """Parse exactly two opcode bytes, e.g. ``"04 18"``."""
    raw = parse_hex_bytes(text)
    if len(raw) != 2:
        raise ValueError(f"opcode must be exactly 2 bytes (e.g. '04 18'), got {fmt_bytes(raw)}")
    return raw


def hexdump(data: bytes, width: int = 16) -> str:
    """xxd-style dump, 16 bytes per line."""
    if not data:
        return "(empty)"
    lines = []
    for offset in range(0, len(data), width):
        chunk = data[offset:offset + width]
        hexpart = " ".join(f"{b:02x}" for b in chunk)
        ascii_part = "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)
        lines.append(f"{offset:08x}  {hexpart:<{width * 3 - 1}}  |{ascii_part}|")
    return "\n".join(lines)


def make_frame(opcode: bytes, payload: bytes = b"") -> bytes:
    """Build the 64-byte report payload: ``opcode + payload`` zero-padded."""
    if len(opcode) != 2:
        raise ValueError("opcode must be 2 bytes")
    if len(payload) > PAYLOAD_LEN - 2:
        raise ValueError(
            f"payload too long: {len(payload)} bytes, max {PAYLOAD_LEN - 2} after the opcode")
    frame = bytearray(PAYLOAD_LEN)
    frame[0:2] = opcode
    frame[2:2 + len(payload)] = payload
    return bytes(frame)


def normalize_frame(raw: bytes) -> bytes:
    """Accept a 64-byte payload or a 65-byte wire buffer (report id + payload)."""
    raw = bytes(raw)
    if len(raw) == BUF_LEN:
        return raw[1:]
    if len(raw) == PAYLOAD_LEN:
        return raw
    raise ValueError(
        f"frame must be 64 bytes (payload) or 65 bytes (wire buffer), got {len(raw)}")


def status_of(reply: Optional[bytes]) -> Optional[int]:
    """Status byte 3 of a 64-byte reply payload, or None."""
    if reply is None or len(reply) < 4:
        return None
    return reply[3]


def status_name(code: Optional[int]) -> str:
    if code is None:
        return "no-reply"
    return STATUS_NAMES.get(code, f"0x{code:02x}")


def _status_for_expect(text: Optional[str]) -> Optional[int]:
    if text is None or str(text).strip().lower() in ("", "any", "*"):
        return None
    low = str(text).strip().lower()
    if low in STATUS_NAMES.values():
        for code, name in STATUS_NAMES.items():
            if name == low:
                return code
    if re.fullmatch(r"(?i)0x[0-9a-f]{1,2}", low):
        return int(low, 16)
    if re.fullmatch(r"\d+", low):
        return int(low)
    raise ValueError(f"unknown expected status {text!r} (use ok/rejected/no-verdict/any or a byte)")


# --------------------------------------------------------------------------- #
# stdlib-only YAML subset loader (enough for opcodes.yaml)
# --------------------------------------------------------------------------- #
class YamlError(ValueError):
    pass


def _strip_yaml_comment(line: str) -> str:
    out: list[str] = []
    quote: Optional[str] = None
    for ch in line:
        if quote:
            out.append(ch)
            if ch == quote:
                quote = None
        elif ch in ('"', "'"):
            quote = ch
            out.append(ch)
        elif ch == "#":
            break
        else:
            out.append(ch)
    return "".join(out)


def _split_yaml_kv(text: str, lineno: int) -> tuple[str, str]:
    quote: Optional[str] = None
    for index, ch in enumerate(text):
        if quote:
            if ch == quote:
                quote = None
        elif ch in ('"', "'"):
            quote = ch
        elif ch == ":":
            return text[:index].strip(), text[index + 1:].strip()
    raise YamlError(f"line {lineno}: expected 'key: value', got {text!r}")


def _parse_yaml_scalar(text: str) -> Any:
    text = text.strip()
    if text == "":
        return ""
    if len(text) >= 2 and text[0] == text[-1] and text[0] in ('"', "'"):
        return text[1:-1]
    low = text.lower()
    if low in ("true", "yes", "on"):
        return True
    if low in ("false", "no", "off"):
        return False
    if low in ("null", "~"):
        return None
    if re.fullmatch(r"[-+]?0x[0-9a-fA-F]+", text):
        return int(text, 16)
    if re.fullmatch(r"[-+]?[0-9]+", text):
        return int(text, 10)
    return text


def parse_yaml_subset(text: str) -> dict:
    """Parse the tiny YAML subset used by opcodes.yaml.

    Supported: top-level ``key: scalar`` and ``key:`` followed by a block list
    of ``- key: value`` mappings with further ``  key: value`` scalars.
    No anchors, no nested lists, no multi-line scalars. Anything else raises.
    """
    root: dict[str, Any] = {}
    current_key: Optional[str] = None
    current_list: Optional[list] = None
    current_item: Optional[dict] = None

    for lineno, raw in enumerate(text.splitlines(), 1):
        line = _strip_yaml_comment(raw).rstrip()
        if not line.strip():
            continue
        if line[:1].isspace():
            stripped = line.strip()
            if stripped.startswith("-"):
                if current_list is None:
                    raise YamlError(f"line {lineno}: list item outside a list")
                body = stripped[1:].strip()
                if not body:
                    current_item = {}
                else:
                    key, value = _split_yaml_kv(body, lineno)
                    current_item = {key: _parse_yaml_scalar(value)}
                current_list.append(current_item)
            else:
                if current_item is None:
                    raise YamlError(f"line {lineno}: indented key outside a list item")
                key, value = _split_yaml_kv(stripped, lineno)
                current_item[key] = _parse_yaml_scalar(value)
            continue
        # top level
        key, value = _split_yaml_kv(line.strip(), lineno)
        current_item = None
        if value:
            root[key] = _parse_yaml_scalar(value)
            current_key = None
            current_list = None
        else:
            current_key = key
            current_list = []
            root[key] = current_list
    return root


# --------------------------------------------------------------------------- #
# policy data
# --------------------------------------------------------------------------- #
@dataclass(frozen=True)
class OpcodeInfo:
    opcode: bytes
    name: str
    risk: str
    payload: bytes = b""
    expected: str = ""
    source: str = ""
    notes: str = ""
    one_shot_poison: bool = False

    @property
    def label(self) -> str:
        return fmt_opcode(self.opcode)


def _opcode_info_from_record(rec: dict, path: str, index: int) -> OpcodeInfo:
    where = f"{path}: opcodes[{index}]"
    for required in ("opcode", "name", "risk", "payload", "expected", "source"):
        if required not in rec:
            raise PolicyError(f"{where}: missing required field {required!r}")
    try:
        opcode = parse_opcode(rec["opcode"])
    except ValueError as exc:
        raise PolicyError(f"{where}: bad opcode: {exc}") from None
    risk = str(rec["risk"]).strip()
    if risk not in RISK_LEVELS:
        raise PolicyError(
            f"{where}: risk {risk!r} is not one of {', '.join(RISK_LEVELS)}")
    try:
        payload = parse_hex_bytes(rec["payload"])
    except ValueError as exc:
        raise PolicyError(f"{where}: bad payload: {exc}") from None
    if len(payload) > PAYLOAD_LEN - 2:
        raise PolicyError(f"{where}: payload longer than {PAYLOAD_LEN - 2} bytes")
    return OpcodeInfo(
        opcode=opcode,
        name=str(rec["name"]),
        risk=risk,
        payload=payload,
        expected=str(rec["expected"]),
        source=str(rec["source"]),
        notes=str(rec.get("notes", "")),
        one_shot_poison=bool(rec.get("one_shot_poison", False)),
    )


@dataclass
class Decision:
    allowed: bool
    risk: str
    name: str
    exit_code: int = EXIT_OK
    messages: list[str] = field(default_factory=list)

    def __bool__(self) -> bool:
        return self.allowed


class Policy:
    """Opcode risk table loaded from opcodes.yaml plus the built-in hard deny."""

    def __init__(self, opcodes: dict[bytes, OpcodeInfo],
                 hard_deny: dict[tuple[int, int], str],
                 path: str = DEFAULT_OPCODES):
        self.path = path
        self.opcodes = opcodes
        merged = dict(BUILTIN_HARD_DENY)
        merged.update(hard_deny)
        self.hard_deny = merged

    # -- loading -------------------------------------------------------- #
    @classmethod
    def load(cls, path: str = DEFAULT_OPCODES) -> "Policy":
        try:
            with open(path, "r", encoding="utf-8") as handle:
                text = handle.read()
        except OSError as exc:
            raise PolicyError(f"cannot read opcode policy {path}: {exc}") from None
        try:
            document = parse_yaml_subset(text)
        except YamlError as exc:
            raise PolicyError(f"{path}: {exc}") from None
        records = document.get("opcodes")
        if not isinstance(records, list) or not records:
            raise PolicyError(f"{path}: no 'opcodes:' list found")
        opcodes: dict[bytes, OpcodeInfo] = {}
        for index, record in enumerate(records):
            if not isinstance(record, dict):
                raise PolicyError(f"{path}: opcodes[{index}] is not a mapping")
            info = _opcode_info_from_record(record, path, index)
            if info.opcode in opcodes:
                raise PolicyError(
                    f"{path}: duplicate opcode {info.label} "
                    f"({opcodes[info.opcode].name!r} and {info.name!r})")
            opcodes[info.opcode] = info
        hard_deny: dict[tuple[int, int], str] = {}
        for index, record in enumerate(document.get("hard_deny") or []):
            if not isinstance(record, dict) or "opcode" not in record:
                raise PolicyError(f"{path}: hard_deny[{index}] needs an 'opcode'")
            try:
                opcode = parse_opcode(record["opcode"])
            except ValueError as exc:
                raise PolicyError(f"{path}: hard_deny[{index}]: {exc}") from None
            hard_deny[(opcode[0], opcode[1])] = str(record.get("reason", "hard-denied"))
        return cls(opcodes=opcodes, hard_deny=hard_deny, path=path)

    # -- lookup --------------------------------------------------------- #
    def lookup(self, opcode: bytes) -> Optional[OpcodeInfo]:
        return self.opcodes.get(bytes(opcode[:2]))

    def risk_of_frame(self, frame: bytes) -> tuple[str, str]:
        if len(frame) >= 2 and frame[0] == 0x04:
            info = self.lookup(frame[:2])
            if info is not None:
                return info.risk, info.name
            return "unknown", f"unclassified opcode 04 {frame[1]:02X}"
        return "state-changing", "continuation data block (no 04 xx header)"

    def hard_deny_reason(self, frame: bytes) -> Optional[str]:
        if len(frame) >= 2 and frame[0] == 0x04:
            return self.hard_deny.get((frame[0], frame[1]))
        return None

    # -- the single safety decision ------------------------------------- #
    def evaluate(self, frame: bytes, *, i_understand: bool,
                 allow_writes: bool, allow_unknown: bool,
                 dry_run: bool) -> Decision:
        frame = bytes(frame)
        risk, name = self.risk_of_frame(frame)
        opcode = frame[:2]
        label = fmt_opcode(opcode) if len(opcode) == 2 else "??"
        messages: list[str] = []

        denied = self.hard_deny_reason(frame)
        if denied is not None:
            return Decision(
                allowed=False, risk="dangerous", name=name, exit_code=EXIT_DENIED,
                messages=[f"HARD-DENIED {label} ({name}): {denied} -- never sent, no override"])

        if risk == "dangerous":
            return Decision(
                allowed=False, risk=risk, name=name, exit_code=EXIT_DENIED,
                messages=[f"REFUSED dangerous opcode {label} ({name}); see {self.path}"])

        info = self.lookup(opcode) if len(opcode) == 2 else None
        if info is not None and info.one_shot_poison:
            messages.append(
                f"WARNING: {label} ({name}) is one-shot: it poisons the open control "
                "connection (all later commands answer 0xFF) until the node is reopened. "
                "Run it last / on its own.")

        if dry_run:
            if risk in WRITE_RISKS:
                messages.append(
                    f"[dry-run] note: a real run of this '{risk}' opcode needs "
                    "--i-understand --allow-writes")
            else:
                messages.append("[dry-run] note: a real run needs --i-understand")
            if risk == "unknown":
                messages.append(
                    "[dry-run] note: opcode not classified in opcodes.yaml; a real run "
                    "would refuse it without --allow-unknown --allow-writes")
            messages.append("[dry-run] no /dev/hidraw* node was opened")
            return Decision(True, risk, name, EXIT_OK, messages)

        allowed = True
        exit_code = EXIT_OK
        if not i_understand:
            allowed = False
            exit_code = EXIT_GATE
            messages.append(
                "refusing to open any /dev/hidraw* node: pass --i-understand "
                "(or use --dry-run to preview the exact bytes for free)")
        if risk in WRITE_RISKS and not allow_writes:
            allowed = False
            exit_code = EXIT_GATE
            messages.append(
                f"opcode {label} is '{risk}' (it can change persisted device state): "
                "pass --allow-writes as well")
        if risk == "unknown" and not (allow_unknown and allow_writes):
            allowed = False
            exit_code = EXIT_DENIED
            messages.append(
                f"opcode {label} is not classified in {self.path} (unknown risk): add "
                "it there with an explicit risk, or force it with "
                "--allow-unknown --allow-writes")
        if allowed:
            messages.append(f"policy ok: {label} ({name}) risk={risk}")
        return Decision(allowed, risk, name, exit_code, messages)


# --------------------------------------------------------------------------- #
# device discovery (sysfs only -- never opens /dev)
# --------------------------------------------------------------------------- #
@dataclass
class HidNode:
    hidraw: str
    path: str
    role: str
    descriptor_prefix: str
    hid_id: str = ""
    vendor_id: Optional[int] = None
    product_id: Optional[int] = None
    name: str = ""
    phys: str = ""

    def to_dict(self) -> dict:
        return {
            "hidraw": self.hidraw,
            "path": self.path,
            "role": self.role,
            "descriptor_prefix": self.descriptor_prefix,
            "hid_id": self.hid_id,
            "vendor_id": None if self.vendor_id is None else f"0x{self.vendor_id:04x}",
            "product_id": None if self.product_id is None else f"0x{self.product_id:04x}",
            "name": self.name,
            "phys": self.phys,
        }


@dataclass
class Discovery:
    nodes: list[HidNode] = field(default_factory=list)
    image: Optional[HidNode] = None
    control: Optional[HidNode] = None

    def to_dict(self) -> dict:
        return {
            "nodes": [node.to_dict() for node in self.nodes],
            "image": None if self.image is None else self.image.to_dict(),
            "control": None if self.control is None else self.control.to_dict(),
        }


def _read_uevent(path: str) -> dict[str, str]:
    values: dict[str, str] = {}
    try:
        with open(path, "r", encoding="utf-8", errors="replace") as handle:
            for line in handle:
                line = line.strip()
                if "=" in line:
                    key, value = line.split("=", 1)
                    values[key] = value
    except OSError:
        pass
    return values


def _parse_hid_id(hid_id: str) -> tuple[Optional[int], Optional[int]]:
    parts = hid_id.split(":")
    if len(parts) < 3:
        return None, None
    try:
        return int(parts[1], 16), int(parts[2], 16)
    except ValueError:
        return None, None


def _pick_node(nodes: Iterable[HidNode], role: str) -> Optional[HidNode]:
    matching = [node for node in nodes if node.role == role]
    preferred = [
        node for node in matching
        if node.vendor_id == VENDOR_ID and node.product_id == PRODUCT_ID
    ]
    chosen = preferred or matching
    return chosen[0] if chosen else None


def discover() -> Discovery:
    """Find the HX-KEG450 hidraw nodes from sysfs report descriptors.

    Read-only: opens files under /sys, never /dev/hidraw*. The two vendor
    interfaces are identified by their report-descriptor prefix (the first
    item of a HID report descriptor is the Usage Page):

        b"\\x06\\x68\\xff"  -> usage page 0xFF68 -> image node
        b"\\x06\\x13\\xff"  -> usage page 0xFF13 -> control node
    """
    nodes: list[HidNode] = []
    pattern = "/sys/class/hidraw/hidraw*/device/report_descriptor"
    for descriptor_path in sorted(glob.glob(pattern)):
        hidraw_dir = os.path.dirname(os.path.dirname(descriptor_path))
        hidraw = os.path.basename(hidraw_dir)
        try:
            with open(descriptor_path, "rb") as handle:
                head = handle.read(4)
        except OSError:
            continue
        if head.startswith(IMAGE_PREFIX):
            role = "image"
        elif head.startswith(CONTROL_PREFIX):
            role = "control"
        else:
            role = "other"
        uevent = _read_uevent(os.path.join(hidraw_dir, "device", "uevent"))
        vendor, product = _parse_hid_id(uevent.get("HID_ID", ""))
        nodes.append(HidNode(
            hidraw=hidraw,
            path="/dev/" + hidraw,
            role=role,
            descriptor_prefix=fmt_bytes(head).lower(),
            hid_id=uevent.get("HID_ID", ""),
            vendor_id=vendor,
            product_id=product,
            name=uevent.get("HID_NAME", ""),
            phys=uevent.get("HID_PHYS", ""),
        ))
    return Discovery(
        nodes=nodes,
        image=_pick_node(nodes, "image"),
        control=_pick_node(nodes, "control"),
    )


def find_nodes() -> tuple[str, str]:
    """Return ``(image_node, control_node)`` or raise DeviceNotFound."""
    found = discover()
    if found.image is None or found.control is None:
        raise DeviceNotFound(
            "HX-KEG450 vendor interfaces not found "
            f"(image={found.image and found.image.path!r}, "
            f"control={found.control and found.control.path!r}).\n"
            "  * connect the keyboard with the USB-C cable (screen is cable-only)\n"
            "  * install the udev rule / join the 'input' group for hidraw access")
    return found.image.path, found.control.path


# --------------------------------------------------------------------------- #
# transports: the only code that may touch /dev/hidraw*
# --------------------------------------------------------------------------- #
def _ioc(direction: int, type_char: str, nr: int, size: int) -> int:
    return (direction << 30) | (size << 16) | (ord(type_char) << 8) | nr


def hid_set_feature(size: int) -> int:
    """HIDIOCSFEATURE(len) = _IOC(_IOC_WRITE|_IOC_READ, 'H', 0x06, len)."""
    return _ioc(3, "H", 0x06, size)


def hid_get_feature(size: int) -> int:
    """HIDIOCGFEATURE(len) = _IOC(_IOC_WRITE|_IOC_READ, 'H', 0x07, len)."""
    return _ioc(3, "H", 0x07, size)


class ControlTransport:
    """Real control-channel session (0xFF13, 64-byte FEATURE reports)."""

    dry_run = False

    def __init__(self, path: str, timeout: float = DEFAULT_TIMEOUT):
        self.path = path
        self.timeout = timeout
        self.fd: Optional[int] = None

    # context manager ---------------------------------------------------- #
    def __enter__(self) -> "ControlTransport":
        self.open()
        return self

    def __exit__(self, *exc_info) -> None:
        self.close()

    def open(self) -> None:
        try:
            self.fd = os.open(self.path, os.O_RDWR | os.O_NONBLOCK)
        except OSError as exc:
            raise DeviceNotFound(f"cannot open {self.path}: {exc}") from None

    def close(self) -> None:
        if self.fd is not None:
            try:
                os.close(self.fd)
            except OSError:
                pass
            self.fd = None

    # operations --------------------------------------------------------- #
    def sleep(self, seconds: float) -> None:
        if seconds > 0:
            time.sleep(seconds)

    def drain(self, limit: int = DRAIN_LIMIT, timeout: float = DRAIN_TIMEOUT) -> int:
        """Discard stale replies queued on the node (the firmware reply lags)."""
        if self.fd is None:
            return 0
        count = 0
        for _ in range(limit):
            try:
                ready, _, _ = select.select([self.fd], [], [], timeout)
            except InterruptedError:
                continue
            if not ready:
                break
            try:
                data = os.read(self.fd, PAYLOAD_LEN)
            except (BlockingIOError, InterruptedError):
                break
            except OSError:
                break
            if not data:
                break
            count += 1
        return count

    def set_feature(self, frame: bytes) -> None:
        """ioctl(HIDIOCSFEATURE(65), b'\\x00' + payload_64)."""
        if self.fd is None:
            raise TransportError("control transport is not open")
        frame = normalize_frame(frame)
        buf = bytearray(BUF_LEN)
        buf[0] = REPORT_ID
        buf[1:] = frame
        try:
            fcntl.ioctl(self.fd, hid_set_feature(BUF_LEN), buf, True)
        except OSError as exc:
            raise TransportError(f"HIDIOCSFEATURE(65) failed on {self.path}: {exc}") from None

    def get_feature(self) -> Optional[bytes]:
        """ioctl(HIDIOCGFEATURE(65)) -> strip leading report id -> 64-byte reply."""
        if self.fd is None:
            raise TransportError("control transport is not open")
        buf = bytearray(BUF_LEN)
        try:
            fcntl.ioctl(self.fd, hid_get_feature(BUF_LEN), buf, True)
        except OSError:
            return None
        return bytes(buf[1:]) or None

    # live page reads are intentionally NOT implemented here -- probe.py is
    # control-channel-only. Screen page writes + ACKs live in keg450.py.


class DryRunTransport:
    """Prints the exact operations that would hit the device; opens nothing."""

    dry_run = True

    def __init__(self, path: str, log: Callable[[str], None] = print,
                 verbose: bool = False, timeout: float = DEFAULT_TIMEOUT):
        self.path = path
        self.timeout = timeout
        self._log = log
        self.verbose = verbose

    def __enter__(self) -> "DryRunTransport":
        return self

    def __exit__(self, *exc_info) -> None:
        return None

    def open(self) -> None:
        self._log(f"[dry-run] would open {self.path} with O_RDWR|O_NONBLOCK -- NOT opened")

    def close(self) -> None:
        return None

    def sleep(self, seconds: float) -> None:
        if self.verbose and seconds > 0:
            self._log(f"[dry-run] sleep {seconds * 1000:.1f} ms")

    def drain(self) -> int:
        self._log("[dry-run] drain: read stale replies until 20 ms of silence (up to 32 reads)")
        return 0

    def set_feature(self, frame: bytes) -> None:
        frame = normalize_frame(frame)
        wire = bytes([REPORT_ID]) + frame
        self._log(
            f"[dry-run] SET_FEATURE  ioctl(fd, HIDIOCSFEATURE({BUF_LEN}), buf) -- "
            f"{len(wire)} bytes on the wire (0x00 report id + 64-byte payload):")
        for line in hexdump(wire).splitlines():
            self._log("[dry-run]   " + line)

    def get_feature(self) -> Optional[bytes]:
        self._log(
            f"[dry-run] GET_FEATURE  ioctl(fd, HIDIOCGFEATURE({BUF_LEN}), buf=65) -- "
            "would yield a 65-byte buffer, strip buf[0], return the 64-byte reply")
        return None


# --------------------------------------------------------------------------- #
# reply objects
# --------------------------------------------------------------------------- #
@dataclass
class Reply:
    request: bytes                       # 64-byte report payload that was sent
    data: Optional[bytes]                # 64-byte reply payload (None = no reply / dry-run)
    name: str = ""
    risk: str = ""
    retried: bool = False
    dry_run: bool = False
    expected: Optional[str] = None

    @property
    def opcode(self) -> bytes:
        return self.request[:2]

    @property
    def status(self) -> Optional[int]:
        return status_of(self.data)

    @property
    def status_name(self) -> str:
        return status_name(self.status)

    @property
    def echo_ok(self) -> Optional[bool]:
        if self.data is None:
            return None
        return self.data[:2] == self.request[:2]

    def matches_expectation(self, expect: Optional[int]) -> Optional[bool]:
        if expect is None or self.data is None:
            return None
        return self.status == expect

    def hexdump(self) -> str:
        parts = ["request payload (64 B; wire frame = 00 + this = 65 B):",
                 hexdump(self.request)]
        if self.data is not None:
            parts += ["reply payload (64 B):", hexdump(self.data)]
        elif self.dry_run:
            parts += ["reply payload: (dry-run: no hardware reply read)"]
        else:
            parts += ["reply payload: (no reply / timeout)"]
        return "\n".join(parts)

    def human(self) -> str:
        lines = [f"opcode   : {fmt_opcode(self.opcode)}  ({self.name})   risk={self.risk}"]
        if self.data is not None:
            lines.append(
                f"reply    : status byte 3 = 0x{self.status:02x} ({self.status_name}); "
                f"echo={self.echo_ok}")
        elif self.dry_run:
            lines.append("reply    : (dry-run: no hardware reply read)")
        else:
            lines.append("reply    : none (timeout / no GET_FEATURE answer)")
        if self.retried:
            lines.append("retried  : yes (first-command-after-open spurious reject)")
        lines.append(self.hexdump())
        if self.expected is not None and not self.dry_run:
            matched = self.matches_expectation(self.expected)
            lines.append(f"expected : status == 0x{self.expected:02x} "
                         f"({status_name(self.expected)}) -> {'MATCH' if matched else 'MISMATCH'}")
        return "\n".join(lines)

    def to_dict(self) -> dict:
        return {
            "opcode": fmt_opcode(self.opcode),
            "name": self.name,
            "risk": self.risk,
            "status": self.status,
            "status_hex": None if self.status is None else f"0x{self.status:02x}",
            "status_name": self.status_name,
            "echo_ok": self.echo_ok,
            "retried": self.retried,
            "dry_run": self.dry_run,
            "expected": None if self.expected is None else status_name(self.expected),
            "matched": self.matches_expectation(self.expected),
            "request_hex": fmt_bytes(self.request),
            "reply_hex": None if self.data is None else fmt_bytes(self.data),
        }


@dataclass
class QueryResult:
    request: bytes
    ack: Optional[bytes]
    packets: list[bytes] = field(default_factory=list)
    requested: int = 0
    name: str = ""
    risk: str = ""
    dry_run: bool = False

    @property
    def opcode(self) -> bytes:
        return self.request[:2]

    @property
    def ack_status(self) -> Optional[int]:
        return status_of(self.ack)

    @property
    def ack_status_name(self) -> str:
        return status_name(self.ack_status)

    def human(self) -> str:
        lines = [f"opcode   : {fmt_opcode(self.opcode)}  ({self.name})   risk={self.risk}",
                 f"packets  : wanted {self.requested}, got {len(self.packets)}"]
        if self.ack is not None:
            lines.append(
                f"ack      : status byte 3 = 0x{self.ack_status:02x} ({self.ack_status_name}); "
                f"echo={self.ack[:2] == self.request[:2]}")
        elif self.dry_run:
            lines.append("ack      : (dry-run: no hardware reply read)")
        else:
            lines.append("ack      : none (timeout)")
        lines.append("request payload (64 B; wire frame = 00 + this = 65 B):")
        lines.append(hexdump(self.request))
        for index, packet in enumerate(self.packets):
            lines.append(f"packet[{index}] ({len(packet)} B):")
            lines.append(hexdump(packet))
        if self.dry_run:
            lines.append("[dry-run] would issue "
                         f"1 ACK read + up to {self.requested} data GET_FEATURE reads")
        return "\n".join(lines)

    def to_dict(self) -> dict:
        return {
            "opcode": fmt_opcode(self.opcode),
            "name": self.name,
            "risk": self.risk,
            "dry_run": self.dry_run,
            "requested_packets": self.requested,
            "received_packets": len(self.packets),
            "ack_status": self.ack_status,
            "ack_status_hex": None if self.ack_status is None else f"0x{self.ack_status:02x}",
            "ack_status_name": self.ack_status_name,
            "request_hex": fmt_bytes(self.request),
            "ack_hex": None if self.ack is None else fmt_bytes(self.ack),
            "packets_hex": [fmt_bytes(packet) for packet in self.packets],
        }


# --------------------------------------------------------------------------- #
# probe / library entry point
# --------------------------------------------------------------------------- #
class Probe:
    """A live (or dry-run) control-channel session with policy enforcement."""

    def __init__(self, transport, policy: Policy, *, i_understand: bool = False,
                 allow_writes: bool = False, allow_unknown: bool = False,
                 discovery: Optional[Discovery] = None, timeout: float = DEFAULT_TIMEOUT,
                 verbose: bool = False, retries: int = 1,
                 log: Callable[[str], None] = print):
        self.transport = transport
        self.policy = policy
        self.i_understand = i_understand
        self.allow_writes = allow_writes
        self.allow_unknown = allow_unknown
        self.discovery = discovery or Discovery()
        self.timeout = timeout
        self.verbose = verbose
        self.retries = max(0, int(retries))
        self._log = log
        self._first = True
        self.control_path = getattr(transport, "path", "?")
        self.image_path = (
            self.discovery.image.path if self.discovery.image is not None else None)

    # -- construction ---------------------------------------------------- #
    @classmethod
    def connect(cls, *, i_understand: bool = False, allow_writes: bool = False,
                allow_unknown: bool = False, dry_run: bool = False,
                control_node: Optional[str] = None, policy: Optional[Policy] = None,
                opcodes_path: str = DEFAULT_OPCODES, timeout: float = DEFAULT_TIMEOUT,
                verbose: bool = False, retries: int = 1,
                log: Callable[[str], None] = print) -> "Probe":
        """Open the control node, or build a dry-run session that opens nothing."""
        if policy is None:
            policy = Policy.load(opcodes_path)
        if not dry_run and not i_understand:
            raise SafetyError(
                "refusing to open any /dev/hidraw* node without --i-understand. "
                "Use --dry-run to preview the exact bytes without touching hardware.")
        discovery = discover()
        if control_node:
            control_path: Optional[str] = control_node
        elif discovery.control is not None:
            control_path = discovery.control.path
        else:
            control_path = None
        if control_path is None:
            if not dry_run:
                raise DeviceNotFound(
                    "HX-KEG450 control interface (usage page 0xFF13) not found in "
                    "/sys/class/hidraw. Connect the keyboard with the USB-C cable.")
            control_path = "/dev/hidraw? (no HX-KEG450 control node found)"
        if dry_run:
            transport = DryRunTransport(control_path, log=log, verbose=verbose,
                                        timeout=timeout)
        else:
            transport = ControlTransport(control_path, timeout=timeout)
            transport.open()
        return cls(transport, policy, i_understand=i_understand,
                   allow_writes=allow_writes, allow_unknown=allow_unknown,
                   discovery=discovery, timeout=timeout, verbose=verbose,
                   retries=retries, log=log)

    def __enter__(self) -> "Probe":
        return self

    def __exit__(self, *exc_info) -> None:
        self.close()

    def close(self) -> None:
        self.transport.close()

    # -- policy ---------------------------------------------------------- #
    def decide(self, frame: bytes) -> Decision:
        frame = normalize_frame(frame)
        return self.policy.evaluate(
            frame,
            i_understand=self.i_understand,
            allow_writes=self.allow_writes,
            allow_unknown=self.allow_unknown,
            dry_run=bool(self.transport.dry_run),
        )

    def _check(self, frame: bytes) -> Decision:
        decision = self.decide(frame)
        if not decision.allowed:
            raise PolicyDenied(decision)
        return decision

    # -- core send ------------------------------------------------------- #
    def send(self, opcode: bytes, payload: bytes = b"",
             *, expect: Optional[str] = None) -> Reply:
        """Send one command; return the decoded Reply (status byte 3 + hexdump).

        ``opcode`` is the two opcode bytes; ``payload`` is what follows them in
        the 64-byte report (both are zero-padded). Raises PolicyDenied when the
        opcode is not permitted for this session's flags.
        """
        frame = make_frame(parse_opcode(opcode), bytes(payload))
        reply = self.send_frame(frame, expect=expect)
        return reply

    def send_frame(self, frame: bytes, *, name: Optional[str] = None,
                   expect: Optional[str] = None) -> Reply:
        """Send an exact 64-byte report payload (65-byte wire form)."""
        frame = normalize_frame(frame)
        decision = self._check(frame)
        for message in decision.messages:
            if message.startswith(("WARNING", "[dry-run]")):
                self._log(message)
        reply = self._transact(frame)
        reply.name = name or decision.name
        reply.risk = decision.risk
        reply.expected = _status_for_expect(expect)
        return reply

    def _read_echo(self, frame: bytes, attempts: Optional[int] = None) -> Optional[bytes]:
        """GET_FEATURE until the reply echoes the command we sent (or we time out).

        The firmware's reply queue lags: a fast GET can return the previous
        command's report, which would look like a phantom ACK. We therefore
        match the first two reply bytes against the request and keep polling
        until ``--timeout`` expires (or ``attempts`` GETs, when given).
        """
        transport = self.transport
        if transport.dry_run:
            return transport.get_feature()
        deadline = time.monotonic() + max(float(self.timeout or DEFAULT_TIMEOUT), 0.02)
        data: Optional[bytes] = None
        attempt = 0
        while True:
            attempt += 1
            data = transport.get_feature()
            if data is not None and len(data) >= 2 and data[:2] == frame[:2]:
                return data
            if attempts is not None and attempt >= attempts:
                return data
            if time.monotonic() >= deadline:
                if self.verbose:
                    self._log(f"[warn] no echoing reply after {attempt} GET_FEATURE "
                              f"attempt(s); giving up")
                return data
            transport.drain()
            transport.sleep(0.005)

    def _transact(self, frame: bytes) -> Reply:
        transport = self.transport
        if self.verbose:
            self._log(f"--> {fmt_bytes(frame[:10])} ...")
        transport.drain()
        transport.set_feature(frame)
        transport.sleep(SET_GET_DELAY)
        data = self._read_echo(frame)
        retried = False
        if (self._first and self.retries > 0 and not transport.dry_run
                and data is not None and status_of(data) == 0xFF):
            self._log(
                "[retry] first command after opening was rejected (known spurious "
                "first-reject quirk); draining and resending once")
            transport.drain()
            transport.set_feature(frame)
            transport.sleep(SET_GET_DELAY)
            data = self._read_echo(frame)
            retried = True
        self._first = False
        transport.sleep(CMD_DELAY)
        return Reply(request=frame, data=data, retried=retried,
                     dry_run=bool(transport.dry_run))

    # -- multi-packet read (FEAT_QUERY, e.g. 04 F5) ---------------------- #
    def query(self, opcode: bytes, payload: bytes = b"", *, packets: int = 9,
              name: Optional[str] = None) -> QueryResult:
        """FEAT_QUERY-style read: command, ACK, then N x 64-byte data reports."""
        frame = make_frame(parse_opcode(opcode), bytes(payload))
        decision = self._check(frame)
        packets = max(0, min(int(packets), 64))
        transport = self.transport
        transport.drain()
        transport.set_feature(frame)
        transport.sleep(0.005)
        ack = self._read_echo(frame, attempts=10)
        collected: list[bytes] = []
        if transport.dry_run:
            for _ in range(packets):
                transport.get_feature()
        elif ack is not None and status_of(ack) == 0x01:
            for _ in range(packets):
                data = transport.get_feature()
                if data is None:
                    break
                collected.append(data)
        transport.sleep(CMD_DELAY)
        for message in decision.messages:
            if message.startswith(("WARNING", "[dry-run]")):
                self._log(message)
        return QueryResult(
            request=frame, ack=ack, packets=collected, requested=packets,
            name=name or decision.name, risk=decision.risk,
            dry_run=bool(transport.dry_run))


# --------------------------------------------------------------------------- #
# replay: captured/labelled JSON sequences
# --------------------------------------------------------------------------- #
@dataclass
class ReplayStep:
    frame: bytes
    opcode: bytes
    name: str = ""
    expect: Optional[str] = None
    delay_ms: int = 35
    source: str = ""

    @property
    def label(self) -> str:
        return fmt_opcode(self.opcode)


def _normalize_replay_record(record: dict, index: int, source: str) -> ReplayStep:
    where = f"{source}: step {index}"
    opcode_raw = record.get("opcode")
    full_hex = record.get("payload_hex") or record.get("data_hex") or record.get("frame_hex")
    payload_field = record.get("payload")

    frame: bytes
    opcode: bytes
    if opcode_raw is not None:
        opcode = parse_opcode(opcode_raw)
        if opcode[0] != 0x04:
            raise ValueError(
                f"{where}: opcode {fmt_opcode(opcode)} is not a 04 xx command "
                "header (non-04 frames are data continuation blocks; give those "
                "as 'payload_hex' without an 'opcode' field)")
    elif full_hex is not None:
        raw = parse_hex_bytes(full_hex)
        if len(raw) < 2:
            raise ValueError(f"{where}: payload shorter than an opcode")
        opcode = raw[:2]
    else:
        raise ValueError(f"{where}: needs 'opcode' (and optional 'payload') or 'payload_hex'")

    if payload_field is not None:
        frame = make_frame(opcode, parse_hex_bytes(payload_field))
    elif full_hex is not None:
        raw = parse_hex_bytes(full_hex)
        if len(raw) == BUF_LEN:
            raw = raw[1:]
        if len(raw) == PAYLOAD_LEN:
            frame = raw
            if frame[:2] != opcode:
                raise ValueError(
                    f"{where}: payload_hex starts with {fmt_bytes(frame[:2])}, "
                    f"not opcode {fmt_opcode(opcode)}")
        elif len(raw) == PAYLOAD_LEN - 2:
            frame = make_frame(opcode, raw)
        else:
            raise ValueError(
                f"{where}: payload_hex must be 64 wire/payload bytes, 65 wire bytes, "
                f"or 62 post-opcode bytes; got {len(raw)}")
    else:
        frame = make_frame(opcode, b"")

    delay_ms = int(record.get("delay_ms", 35) or 35)
    delay_ms = max(35, min(delay_ms, 5000))
    return ReplayStep(
        frame=frame,
        opcode=opcode,
        name=str(record.get("name") or ""),
        expect=record.get("expect", record.get("expect_status")),
        delay_ms=delay_ms,
        source=f"{source}:{index}",
    )


def load_replay(path: str) -> tuple[list[ReplayStep], dict]:
    """Load a replay file: JSON list / {"steps"|"records"|"commands"} / JSONL.

    Also accepts capture.py JSONL directly (its outgoing records carry both an
    ``opcode`` and a 64-byte ``payload_hex``). Inbound *reply* records are not
    commands and are skipped; records probe.py cannot replay (4096-byte image
    page writes, truncated payloads) are reported as ``unsupported`` so the
    caller can refuse the whole sequence instead of sending a half transaction.

    Returns ``(steps, info)`` where info has ``inbound_skipped`` and
    ``unsupported`` (list of human-readable reasons).
    """
    try:
        with open(path, "r", encoding="utf-8") as handle:
            text = handle.read()
    except OSError as exc:
        raise ValueError(f"cannot read replay file {path}: {exc}") from None
    document: Any
    try:
        document = json.loads(text)
    except json.JSONDecodeError:
        items = []
        for lineno, line in enumerate(text.splitlines(), 1):
            stripped = line.strip()
            if not stripped or stripped.startswith("#"):
                continue
            try:
                items.append(json.loads(stripped))
            except json.JSONDecodeError as exc:
                raise ValueError(f"{path}:{lineno}: not valid JSON: {exc}") from None
        document = items
    if isinstance(document, dict):
        for key in ("steps", "records", "commands", "frames"):
            if key in document:
                document = document[key]
                break
        else:
            document = [document]
    if not isinstance(document, list) or not document:
        raise ValueError(f"{path}: replay file must be a non-empty list of steps")
    steps: list[ReplayStep] = []
    info: dict[str, Any] = {"inbound_skipped": 0, "unsupported": []}
    for index, record in enumerate(document, 1):
        if not isinstance(record, dict):
            raise ValueError(f"{path}: step {index} is not a JSON object")
        # capture.py inbound records are replies, never something to resend
        if record.get("direction") == "in" or record.get("kind_label") == "reply":
            info["inbound_skipped"] += 1
            continue
        length = record.get("length")
        if isinstance(length, int) and length not in (0, PAYLOAD_LEN, BUF_LEN):
            info["unsupported"].append(
                f"step {index}: data length {length} is not a 64-byte feature report "
                f"(image page writes are out of scope for probe.py)")
            continue
        try:
            steps.append(_normalize_replay_record(record, index, os.path.basename(path)))
        except ValueError as exc:
            raise ValueError(f"{path}: {exc}") from None
    if not steps:
        raise ValueError(f"{path}: no replayable control-feature steps found")
    return steps, info


# --------------------------------------------------------------------------- #
# CLI
# --------------------------------------------------------------------------- #
def _log_for(args: argparse.Namespace) -> Callable[[str], None]:
    stream = sys.stderr if getattr(args, "json", False) else sys.stdout
    return lambda message: print(message, file=stream)


def _add_global_flags(parser: argparse.ArgumentParser, *, suppress: bool) -> None:
    """Add the safety/transport flags. ``suppress`` keeps subparsers from
    clobbering values already parsed before the subcommand."""
    default: Any = argparse.SUPPRESS if suppress else False

    def default_for(value: Any = None) -> Any:
        return argparse.SUPPRESS if suppress else value

    parser.add_argument("--opcodes", default=default_for(DEFAULT_OPCODES),
                        metavar="PATH",
                        help=f"opcode risk policy file (default: {DEFAULT_OPCODES})")
    parser.add_argument("--dry-run", action="store_true", default=default,
                        help="print the exact bytes/ioctls; never open /dev/hidraw*")
    parser.add_argument("--i-understand", action="store_true", default=default,
                        help="REQUIRED to open any /dev/hidraw* node")
    parser.add_argument("--allow-writes", action="store_true", default=default,
                        help="allow cosmetic/state-changing opcodes (with --i-understand)")
    parser.add_argument("--allow-unknown", action="store_true", default=default,
                        help="allow opcodes missing from opcodes.yaml "
                             "(treated as unknown risk; also needs --allow-writes)")
    parser.add_argument("--control-node", metavar="NODE",
                        default=default_for(None),
                        help="override the auto-discovered control node, "
                             "e.g. /dev/hidraw7")
    parser.add_argument("--timeout", type=float, default=default_for(DEFAULT_TIMEOUT),
                        metavar="SEC", help="max time to wait for a matching GET_FEATURE reply in "
                             f"seconds (default {DEFAULT_TIMEOUT})")
    parser.add_argument("--retries", type=int, default=default_for(1), metavar="N",
                        help="extra attempt for the known spurious first-command "
                             "reject (default 1, 0 disables)")
    parser.add_argument("-v", "--verbose", action="store_true", default=default)
    parser.add_argument("--json", action="store_true", default=default,
                        help="machine-readable JSON on stdout (logs go to stderr)")


def _sub_parser(sub: argparse._SubParsersAction, name: str, **kwargs: Any):
    """Create a subcommand parser that also accepts the global flags after it."""
    return sub.add_parser(name, parents=[_add_global_flags_parser()], **kwargs)


def _add_global_flags_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(add_help=False)
    _add_global_flags(parser, suppress=True)
    return parser


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="probe.py",
        description="Safe opcode probe harness for the HISKA HX-KEG450 "
                    "(0xFF13 control channel only; screen pages are out of scope).",
        epilog=SAFETY_EPILOG,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("--version", action="version", version=f"probe.py {__version__}")
    _add_global_flags(parser, suppress=False)

    sub = parser.add_subparsers(dest="command", required=True)

    _sub_parser(sub, "discover",
                help="list hidraw nodes by report-descriptor prefix "
                     "(sysfs only; opens nothing)")

    opcodes = _sub_parser(sub, "opcodes", help="list the opcode policy table")
    opcodes.add_argument("--risk", default="all",
                         choices=["all", *RISK_LEVELS],
                         help="filter by risk level (default all)")

    send = _sub_parser(sub, "send", help="send one opcode and decode the reply")
    send.add_argument("opcode", help="two opcode bytes, e.g. '04 18' or '0418'")
    send.add_argument("--payload", default=None,
                      help="bytes after the opcode (hex, e.g. '00 00 01'); "
                           "defaults to the opcodes.yaml template")
    send.add_argument("--expect", default=None,
                      help="assert the reply status: ok / rejected / no-verdict / any "
                           "or a byte value")
    send.add_argument("--name", default=None, help="override the label in the output")

    poll = _sub_parser(sub, "poll",
                       help="FEAT_QUERY-style read (default 04 F5 key colours)")
    poll.add_argument("--opcode", default="04 F5", help="query opcode (default '04 F5')")
    poll.add_argument("--packets", type=int, default=9,
                      help="number of 64-byte data reports to read (default 9)")
    poll.add_argument("--payload", default=None,
                      help="override bytes after the opcode (payload[6] is set to --packets)")
    poll.add_argument("--name", default=None)

    replay = _sub_parser(sub, "replay",
                         help="replay a captured/labelled JSON sequence")
    replay.add_argument("file", help="JSON (list or {steps:[...]}) or JSONL; "
                                     "capture.py output works directly")
    replay.add_argument("--skip-dangerous", action="store_true",
                        help="skip (never send) dangerous/hard-denied frames instead "
                             "of aborting the whole replay")
    replay.add_argument("--keep-going", action="store_true",
                        help="continue after a rejected/unexpected status instead of "
                             "stopping the replay")
    replay.add_argument("--save-sent", metavar="PATH", default=None,
                        help="write the sequence that was actually sent to PATH as JSON")
    return parser


def _announce(probe: Probe, args: argparse.Namespace) -> None:
    stream = sys.stderr if args.json else sys.stdout
    discovery = probe.discovery
    if probe.transport.dry_run:
        print(f"[dry-run] control node: {probe.control_path}  "
              "(0xFF13, from sysfs; NOT opened)", file=stream)
        if probe.image_path:
            print(f"[dry-run] image node  : {probe.image_path}  (0xFF68; located only, "
                  "never opened by probe.py)", file=stream)
        if discovery.control is not None:
            node = discovery.control
            print(f"[dry-run] device      : {node.name!r} {node.hid_id}", file=stream)
        else:
            print("[dry-run] device      : HX-KEG450 vendor interfaces not found; "
                  "printing bytes against a placeholder path", file=stream)
    else:
        print(f"control node: {probe.control_path}  (0xFF13, 64-byte FEATURE commands)",
              file=stream)
        if probe.image_path:
            print(f"image node  : {probe.image_path}  (0xFF68; located only)", file=stream)


def cmd_discover(args: argparse.Namespace) -> int:
    discovery = discover()
    if args.json:
        print(json.dumps(discovery.to_dict(), indent=2))
    else:
        print("HISKA HX-KEG450 hidraw discovery "
              "(sysfs report descriptors only; no /dev node opened)")
        if not discovery.nodes:
            print("  no /sys/class/hidraw nodes found")
        for node in discovery.nodes:
            marker = ""
            if node.role == "image":
                marker = "  <-- image / 0xFF68 / 4096-byte OUTPUT pages"
            elif node.role == "control":
                marker = "  <-- control / 0xFF13 / 64-byte FEATURE commands"
            print(f"  {node.path:22s} role={node.role:7s} "
                  f"prefix={node.descriptor_prefix:11s} "
                  f"id={node.hid_id or '?':18s} name={node.name!r}{marker}")
        if discovery.control is None:
            print("\ncontrol node: NOT FOUND - connect the keyboard with the USB-C cable")
            return EXIT_DEVICE
        print(f"\ncontrol node: {discovery.control.path}")
        if discovery.image is not None:
            print(f"image node  : {discovery.image.path}")
    if discovery.control is None:
        return EXIT_DEVICE
    return EXIT_OK


def cmd_opcodes(args: argparse.Namespace, policy: Policy) -> int:
    infos = sorted(policy.opcodes.values(), key=lambda info: info.opcode)
    if args.risk != "all":
        infos = [info for info in infos if info.risk == args.risk]
    if args.json:
        print(json.dumps({
            "policy_file": policy.path,
            "opcodes": [
                {
                    "opcode": info.label,
                    "name": info.name,
                    "risk": info.risk,
                    "payload_hex": fmt_bytes(info.payload),
                    "expected": info.expected,
                    "source": info.source,
                    "notes": info.notes,
                    "one_shot_poison": info.one_shot_poison,
                }
                for info in infos
            ],
            "hard_deny": [
                {"opcode": fmt_opcode(bytes((family, command))), "reason": reason}
                for (family, command), reason in sorted(policy.hard_deny.items())
            ],
        }, indent=2))
        return EXIT_OK

    print(f"policy file: {policy.path}")
    print(f"{'OPCODE':6s}  {'RISK':14s}  {'NAME':28s}  PAYLOAD (after opcode)")
    for info in infos:
        print(f"{info.label:6s}  {info.risk:14s}  {info.name:28s}  "
              f"{fmt_bytes(info.payload) or '(empty)'}")
        if args.verbose:
            print(f"          expected: {info.expected}")
            print(f"          source  : {info.source}")
            if info.notes:
                print(f"          notes   : {info.notes}")
            if info.one_shot_poison:
                print("          WARNING : one-shot -- poisons the open connection")
    print("\nhard-denied opcodes (never sent, no override):")
    for (family, command), reason in sorted(policy.hard_deny.items()):
        print(f"  {fmt_opcode(bytes((family, command)))}  {reason}")
    return EXIT_OK


def _connect(args: argparse.Namespace, policy: Policy) -> Probe:
    log = _log_for(args)
    probe = Probe.connect(
        i_understand=args.i_understand,
        allow_writes=args.allow_writes,
        allow_unknown=args.allow_unknown,
        dry_run=args.dry_run,
        control_node=args.control_node,
        policy=policy,
        timeout=args.timeout,
        verbose=args.verbose,
        retries=args.retries,
        log=log,
    )
    _announce(probe, args)
    return probe


def _preflight(args: argparse.Namespace, policy: Policy, frame: bytes) -> None:
    """Apply the risk policy before any /dev node is opened.

    A refused opcode (dangerous, hard-denied, unclassified, or missing
    --allow-writes) must not even open the hidraw node; otherwise the "refused"
    run would still touch the device.
    """
    decision = policy.evaluate(
        frame,
        i_understand=args.i_understand,
        allow_writes=args.allow_writes,
        allow_unknown=args.allow_unknown,
        dry_run=args.dry_run,
    )
    if not decision.allowed:
        raise PolicyDenied(decision)


def _require_command_opcode(opcode: bytes) -> None:
    if opcode[0] != 0x04:
        raise ValueError(
            f"opcode {fmt_opcode(opcode)} is not a 04 xx command header -- every "
            "HX-KEG450 control command starts 0x04; other frames are data "
            "continuation blocks, not commands")


def cmd_send(args: argparse.Namespace, policy: Policy) -> int:
    opcode = parse_opcode(args.opcode)
    _require_command_opcode(opcode)
    info = policy.lookup(opcode)
    if args.payload is None:
        payload = info.payload if info is not None else b""
    else:
        payload = parse_hex_bytes(args.payload)
    frame = make_frame(opcode, payload)
    _preflight(args, policy, frame)
    with _connect(args, policy) as probe:
        reply = probe.send_frame(frame, name=args.name, expect=args.expect)
    if args.json:
        print(json.dumps(reply.to_dict()))
    else:
        print(reply.human())
    if args.expect is not None and not reply.dry_run:
        expected = _status_for_expect(args.expect)
        if reply.matches_expectation(expected) is False:
            print(f"probe.py: expectation failed: wanted {args.expect!r}, "
                  f"got {reply.status_name}", file=sys.stderr)
            return EXIT_MISMATCH
    return EXIT_OK


def cmd_poll(args: argparse.Namespace, policy: Policy) -> int:
    opcode = parse_opcode(args.opcode)
    _require_command_opcode(opcode)
    info = policy.lookup(opcode)
    if args.payload is not None:
        payload = bytearray(parse_hex_bytes(args.payload))
    elif info is not None:
        payload = bytearray(info.payload)
    else:
        payload = bytearray()
    if len(payload) < 7:
        payload.extend(b"\x00" * (7 - len(payload)))
    payload[6] = max(0, min(args.packets, 255))      # wire byte 8 = packet count
    _preflight(args, policy, make_frame(opcode, bytes(payload)))
    with _connect(args, policy) as probe:
        result = probe.query(opcode, bytes(payload), packets=args.packets,
                             name=args.name)
    if args.json:
        print(json.dumps(result.to_dict()))
    else:
        print(result.human())
    return EXIT_OK


def _replay_preflight(steps: list[ReplayStep], args: argparse.Namespace,
                      policy: Policy) -> tuple[list[tuple[int, ReplayStep]], int,
                                              int, list[dict]]:
    """Refuse the whole replay before touching hardware if any step is blocked.

    Skipping a dangerous *middle* frame after already sending earlier frames
    could leave the firmware mid-transaction, so the decision is made up front,
    before the control node is even opened.
    """
    planned: list[tuple[int, ReplayStep]] = []
    skipped = 0
    skipped_results: list[dict] = []
    for index, step in enumerate(steps, 1):
        decision = policy.evaluate(
            step.frame,
            i_understand=args.i_understand,
            allow_writes=args.allow_writes,
            allow_unknown=args.allow_unknown,
            dry_run=args.dry_run,
        )
        if decision.allowed:
            info = policy.lookup(step.opcode)
            if info is not None and info.one_shot_poison and index != len(steps):
                print(f"probe.py: WARNING: replay step {index} ({step.label}) is "
                      "one-shot and poisons the open connection; the remaining "
                      f"{len(steps) - index} step(s) are expected to be rejected",
                      file=sys.stderr)
            planned.append((index, step))
            continue
        if decision.risk == "dangerous" and args.skip_dangerous:
            skipped += 1
            print(f"probe.py: replay step {index} ({step.label}) SKIPPED "
                  f"(dangerous, never sent): {'; '.join(decision.messages)}",
                  file=sys.stderr)
            skipped_results.append({
                "step": index, "opcode": step.label, "skipped": True,
                "reason": "dangerous", "messages": decision.messages,
            })
            continue
        denied = Decision(
            allowed=False, risk=decision.risk, name=decision.name,
            exit_code=decision.exit_code,
            messages=[f"replay step {index} ({step.label}) refused: "
                      f"{'; '.join(decision.messages)}"])
        raise PolicyDenied(denied)
    return planned, skipped, len(steps), skipped_results


def cmd_replay(args: argparse.Namespace, policy: Policy) -> int:
    steps, info = load_replay(args.file)
    if info["inbound_skipped"]:
        print(f"probe.py: note: skipped {info['inbound_skipped']} inbound reply "
              "record(s) from the capture (replies are read, never replayed)",
              file=sys.stderr)
    if info["unsupported"]:
        print("probe.py: refusing to replay: the sequence contains data that probe.py "
              "cannot send safely (control-feature-only tool):", file=sys.stderr)
        for reason in info["unsupported"]:
            print(f"  - {reason}", file=sys.stderr)
        print("  Replaying only the control half of an image/upload transaction would "
              "leave the firmware mid-transfer; use the full uploader in "
              "hiska-keg450-lcd/keg450.py for screen work.", file=sys.stderr)
        return EXIT_GATE
    planned, skipped, total, skipped_results = _replay_preflight(steps, args, policy)

    results: list[dict] = list(skipped_results)
    sent_steps: list[dict] = []
    sent = mismatches = 0
    aborted = False
    out = sys.stderr if args.json else sys.stdout
    with _connect(args, policy) as probe:
        for position, (index, step) in enumerate(planned, 1):
            prefix = f"[{position:3d}/{len(planned)}] {step.label} {step.name:<26s}"
            reply = probe.send_frame(step.frame, name=step.name, expect=step.expect)
            sent += 1
            matched: Optional[bool] = None
            if step.expect is not None and not reply.dry_run:
                matched = reply.matches_expectation(_status_for_expect(step.expect))
                if matched is False:
                    mismatches += 1
            elif not reply.dry_run and reply.status_name in ("rejected", "no-reply"):
                mismatches += 1
                matched = False

            if reply.dry_run:
                status = "(dry-run)"
            else:
                status = f"{reply.status_name} (0x{reply.status:02x})" \
                    if reply.status is not None else "no-reply"
            print(f"{prefix} -> {status}"
                  + ("  MISMATCH" if matched is False else ""), file=out)
            entry = reply.to_dict()
            entry["step"] = index
            entry["matched"] = matched
            results.append(entry)
            sent_steps.append({
                "opcode": step.label,
                "payload_hex": fmt_bytes(step.frame),
                "expect": step.expect,
                "delay_ms": step.delay_ms,
                "name": step.name,
            })
            if step.delay_ms > 35 and not reply.dry_run:
                probe.transport.sleep((step.delay_ms - 35) / 1000.0)
            if matched is False and not args.keep_going:
                print(f"{prefix} stopping replay after non-matching status "
                      f"(use --keep-going to continue); the firmware may be left "
                      "mid-transaction -- close/reopen the node before more writes",
                      file=sys.stderr)
                aborted = True
                break

    if args.save_sent:
        try:
            with open(args.save_sent, "w", encoding="utf-8") as handle:
                json.dump({"steps": sent_steps}, handle, indent=2)
                handle.write("\n")
        except OSError as exc:
            print(f"probe.py: cannot write --save-sent {args.save_sent}: {exc}",
                  file=sys.stderr)
            return EXIT_DEVICE

    summary = {
        "steps": total,
        "sent": sent,
        "skipped": skipped,
        "mismatched": mismatches,
        "aborted": aborted,
        "dry_run": args.dry_run,
    }
    if args.json:
        print(json.dumps({"results": results, "summary": summary}))
    else:
        print(f"replay: {sent} sent, {skipped} skipped, {mismatches} mismatched, "
              f"{total - sent - skipped} not attempted"
              + (" (aborted)" if aborted else ""))
    if mismatches:
        return EXIT_MISMATCH
    return EXIT_OK


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    try:
        if args.command == "discover":
            return cmd_discover(args)
        policy = Policy.load(args.opcodes)
        if args.command == "opcodes":
            return cmd_opcodes(args, policy)
        if args.command == "send":
            return cmd_send(args, policy)
        if args.command == "poll":
            return cmd_poll(args, policy)
        if args.command == "replay":
            return cmd_replay(args, policy)
        parser.error(f"unknown command {args.command!r}")
        return EXIT_GATE
    except PolicyDenied as exc:
        for message in exc.decision.messages:
            print(f"probe.py: {message}", file=sys.stderr)
        return exc.exit_code
    except ProbeError as exc:
        print(f"probe.py: {exc}", file=sys.stderr)
        return exc.exit_code
    except (ValueError, YamlError) as exc:
        print(f"probe.py: {exc}", file=sys.stderr)
        return EXIT_GATE
    except KeyboardInterrupt:
        print("probe.py: interrupted", file=sys.stderr)
        return 130


if __name__ == "__main__":
    sys.exit(main())
