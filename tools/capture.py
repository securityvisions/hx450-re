#!/usr/bin/env python3
"""capture.py -- normalize Linux usbmon text dumps into JSONL and diff captures.

The HX-KEG450 vendor tool talks to the keyboard over the 0xFF13 control
interface with 64-byte FEATURE reports (65 bytes on the wire: a 0x00 report id
plus the payload). In usbmon text format those show up as control transfers
with a setup packet:

    21 09 0300 0003 0041    SET_REPORT  (feature, interface 3, 65 bytes)
    a1 01 0300 0003 0041    GET_REPORT  (feature, interface 3, 65 bytes)

This tool turns a `cat /sys/kernel/debug/usb/usbmon/3u` dump into one JSON
object per *completed* control transfer (submission matched to callback by URB
tag), so two captures of the vendor app can be compared mechanically:

    capture.py vendor-start.mon -o start.jsonl
    capture.py vendor-light.mon  -o light.jsonl
    capture.py --diff start.jsonl light.jsonl

It never touches hardware: it only reads text files (and stdin).

usbmon format references (text API, '1t' and '1u'):
    <tag> <timestamp> S <type><dir>:<bus>:<dev>:<ep> s <bmRequestType> <bRequest>
          <wValue> <wIndex> <wLength> <dataLength> <dataTag> [data...]
    <tag> <timestamp> C <type><dir>:<bus>:<dev>:<ep> <status> <dataLength>
          <dataTag> [data...]

Only control transfers (type 'C') are emitted; bulk/interrupt/isoc lines and
non-matching setup packets are skipped. The default filter keeps vendor-class
SET_REPORT (0x21 0x09) and GET_REPORT (0xa1 0x01) transfers; --all-control keeps
everything (e.g. standard GET_DESCRIPTOR, other devices on the bus).

JSONL record schema (stable field names, one object per line)::

    line             source line number in the dump
    tag              usbmon URB tag
    ts_us            usbmon timestamp (microseconds)
    t_ms             milliseconds since the first emitted transfer
    addr             usbmon address word, e.g. "Ci:3:002:0"
    bus, device, endpoint   integers (bus is null for old '1t' dumps)
    direction        "out" (host->device) or "in" (device->host)
    setup            {"bmRequestType": "21", "bRequest": "09",
                      "wValue": "0300", "wIndex": "0003", "wLength": "0041"}
    request_type     "standard" | "class" | "vendor" | "reserved"
    recipient        "device" | "interface" | "endpoint" | "other"
    frame_kind       "feature" | "output" | "input" | "other" (from wValue high byte)
    interface        integer wIndex when it fits in a byte, else null
    status           URB status from the callback (0 = success, negative = error/ENODEV etc.)
    length           data length reported by the callback
    captured         number of data bytes actually present in the dump
    report_id        first byte when length is 65/4097 and it is 0x00, else null
    payload_hex      data with the report-id byte stripped (truncated to --max-data)
    payload_truncated  true when payload_hex is shorter than the full payload
    data_hex         raw data incl. report id (truncated to --max-data)
    data_sha256      SHA-256 of the FULL raw data (always present when data exists)
    opcode           "04 18" for outgoing payloads starting 04 xx, else null
    kind_label       "command" (04 xx), "continuation" (data block), "reply", ...
    status_byte      reply payload byte 3 for inbound GET_REPORT replies, else null
    status_name      ok / rejected / no-verdict / null

stdlib only. Python 3.7+.
"""
from __future__ import annotations

import argparse
import difflib
import hashlib
import json
import re
import sys
from dataclasses import dataclass, field
from typing import Any, Iterable, Optional, Sequence

__version__ = "1.0.0"

EXIT_OK = 0
EXIT_DIFFERENT = 1
EXIT_ERROR = 2

#: setup packets that carry the HX-KEG450 vendor control traffic
VENDOR_SETUPS = {(0x21, 0x09), (0xA1, 0x01)}

REQUEST_TYPES = {0: "standard", 1: "class", 2: "vendor", 3: "reserved"}
RECIPIENTS = {0: "device", 1: "interface", 2: "endpoint", 3: "other"}
FRAME_KINDS = {0x01: "input", 0x02: "output", 0x03: "feature"}
STATUS_NAMES = {0x01: "ok", 0xFF: "rejected", 0x00: "no-verdict"}


# --------------------------------------------------------------------------- #
# helpers
# --------------------------------------------------------------------------- #
def fmt_bytes(data: bytes) -> str:
    return " ".join(f"{b:02X}" for b in data)


def parse_hex_bytes(text: Any) -> bytes:
    """Parse ``"04 18"`` / ``"0418"`` / ``"0x04,0x18"`` / a list of ints."""
    if isinstance(text, (bytes, bytearray)):
        return bytes(text)
    if isinstance(text, list):
        out = bytearray()
        for item in text:
            if not isinstance(item, int) or not 0 <= item <= 0xFF:
                raise ValueError(f"payload list must contain bytes 0-255, got {item!r}")
            out.append(item)
        return bytes(out)
    s = re.sub(r"(?i)0x", "", str(text).strip())
    tokens = [token for token in re.split(r"[\s,;:_\-]+", s) if token]
    out = bytearray()
    for token in tokens:
        if len(token) % 2:
            token = "0" + token
        if not re.fullmatch(r"[0-9a-fA-F]+", token):
            raise ValueError(f"not hex: {token!r}")
        out += bytes.fromhex(token)
    return bytes(out)


@dataclass
class Address:
    xfer_type: str       # C control, B bulk, I interrupt, Z isoc
    direction: str       # "in" / "out"
    bus: Optional[int]
    device: int
    endpoint: int
    raw: str


def parse_address(word: str) -> Optional[Address]:
    """Parse the usbmon address word, e.g. ``Ci:3:002:0`` (1u) or ``Ci:002:0`` (1t)."""
    parts = word.split(":")
    if len(parts) not in (3, 4):
        return None
    type_dir = parts[0]
    if len(type_dir) != 2:
        return None
    xfer_type = type_dir[0].upper()
    direction = "in" if type_dir[1].lower() == "i" else "out"
    numbers = parts[1:]
    try:
        if len(numbers) == 3:
            bus: Optional[int] = int(numbers[0], 10)
            device = int(numbers[1], 10)
            endpoint = int(numbers[2], 10)
        else:
            bus = None
            device = int(numbers[0], 10)
            endpoint = int(numbers[1], 10)
    except ValueError:
        return None
    return Address(xfer_type=xfer_type, direction=direction, bus=bus,
                   device=device, endpoint=endpoint, raw=word)


def _parse_setup(tokens: Sequence[str]) -> Optional[tuple[dict, Sequence[str]]]:
    """Parse ``s <bmRequestType> <bRequest> <wValue> <wIndex> <wLength> ...``.

    Returns ``(setup, remainder)`` where remainder is everything after the five
    setup words (data length / data tag / data words for OUT transfers).
    """
    if not tokens or tokens[0] != "s":
        return None
    if len(tokens) < 6:
        return None
    try:
        bm_request_type = int(tokens[1], 16)
        b_request = int(tokens[2], 16)
        w_value = int(tokens[3], 16)
        w_index = int(tokens[4], 16)
        w_length = int(tokens[5], 16)
    except ValueError:
        return None
    for value in (bm_request_type, b_request):
        if not 0 <= value <= 0xFF:
            return None
    for value in (w_value, w_index, w_length):
        if not 0 <= value <= 0xFFFF:
            return None
    setup = {
        "bmRequestType": bm_request_type,
        "bRequest": b_request,
        "wValue": w_value,
        "wIndex": w_index,
        "wLength": w_length,
    }
    return setup, tokens[6:]


def _parse_data_words(tokens: Sequence[str]) -> Optional[bytes]:
    """Parse the usbmon hex data words (a raw byte stream split into words)."""
    data = bytearray()
    for word in tokens:
        if not re.fullmatch(r"[0-9a-fA-F]+", word):
            return None
        if len(word) % 2:                # defensive: data words should be whole bytes
            word = "0" + word
        data += bytes.fromhex(word)
    return bytes(data)


def _parse_submit_data(remainder: Sequence[str]) -> bytes:
    """Parse ``<dataLength> <dataTag> [data...]`` after a control setup packet.

    The text API puts control OUT data on the *submission* line with '=', while
    control IN data only appears on the callback line. Both cases are handled.
    """
    if len(remainder) < 2:
        return b""
    try:
        int(remainder[0], 10)            # data length, informational
    except ValueError:
        return b""
    if remainder[1] != "=":
        return b""
    parsed = _parse_data_words(remainder[2:])
    return parsed or b""


def _parse_callback(tokens: Sequence[str]) -> Optional[tuple[int, int, bytes]]:
    """Parse ``<status> <dataLength> [<dataTag> <data...>]`` for a C event."""
    if len(tokens) < 2:
        return None
    try:
        status = int(tokens[0].split(":")[0], 10)
        length = int(tokens[1], 10)
    except ValueError:
        return None
    data = bytearray()
    if len(tokens) >= 3 and tokens[2] == "=":
        parsed = _parse_data_words(tokens[3:])
        if parsed is None:
            return None
        data += parsed
    return status, length, bytes(data)


@dataclass
class RawTransfer:
    """A completed control transfer (submit matched to callback)."""
    line: int
    tag: str
    ts_us: int
    address: Address
    setup: dict
    status: int
    length: int
    data: bytes
    data_source: str = "callback"      # "callback" | "submit" | "none"


def parse_usbmon(text: str, *, all_control: bool = False,
                 bus: Optional[int] = None, device: Optional[int] = None,
                 interface: Optional[int] = None) -> tuple[list[RawTransfer], dict]:
    """Parse a usbmon text dump into completed control transfers.

    Returns ``(transfers, stats)``; stats counts skipped lines for the summary.
    """
    submissions: dict[str, dict] = {}
    transfers: list[RawTransfer] = []
    stats = {"lines": 0, "events": 0, "control_callbacks": 0,
             "no_setup": 0, "filtered": 0, "bad_lines": 0}

    for lineno, line in enumerate(text.splitlines(), 1):
        stats["lines"] += 1
        stripped = line.strip()
        if not stripped or stripped.startswith("#") or stripped.startswith("//"):
            continue
        tokens = stripped.split()
        if len(tokens) < 4:
            continue
        if tokens[2] not in ("S", "C", "E"):
            continue
        stats["events"] += 1
        tag = tokens[0]
        address = parse_address(tokens[3])
        if address is None:
            stats["bad_lines"] += 1
            continue
        if address.xfer_type != "C":
            continue
        event = tokens[2]
        if event == "S":
            parsed = _parse_setup(tokens[4:])
            if parsed is None:
                continue
            setup, remainder = parsed
            submissions[tag] = {
                "setup": setup,
                "address": address,
                "ts_us": _timestamp(tokens[1]),
                "data": _parse_submit_data(remainder),
            }
            continue
        if event == "E":
            submissions.pop(tag, None)
            continue
        callback = _parse_callback(tokens[4:])
        if callback is None:
            stats["bad_lines"] += 1
            continue
        submit = submissions.pop(tag, None)
        if submit is None:
            stats["no_setup"] += 1
            continue
        setup = submit["setup"]
        stats["control_callbacks"] += 1
        if not _keep(setup, all_control, bus, device, interface, address):
            stats["filtered"] += 1
            continue
        status, length, data = callback
        if data:
            data_source = "callback"
        elif submit["data"]:
            data = submit["data"]
            data_source = "submit"
        else:
            data_source = "none"
        transfer = RawTransfer(
            line=lineno,
            tag=tag,
            ts_us=submit["ts_us"],
            address=address,
            setup=setup,
            status=status,
            length=length,
            data=data,
            data_source=data_source,
        )
        transfers.append(transfer)
    return transfers, stats


def _timestamp(word: str) -> int:
    try:
        return int(word, 10)
    except ValueError:
        return 0


def _keep(setup: dict, all_control: bool, bus: Optional[int],
          device: Optional[int], interface: Optional[int],
          address: Address) -> bool:
    if bus is not None and address.bus != bus:
        return False
    if device is not None and address.device != device:
        return False
    if interface is not None and setup["wIndex"] != interface:
        return False
    if all_control:
        return True
    return (setup["bmRequestType"], setup["bRequest"]) in VENDOR_SETUPS


# --------------------------------------------------------------------------- #
# JSONL conversion
# --------------------------------------------------------------------------- #
def _request_type_name(bm_request_type: int) -> str:
    return REQUEST_TYPES.get((bm_request_type >> 5) & 0x03, "reserved")


def _recipient_name(bm_request_type: int) -> str:
    return RECIPIENTS.get(bm_request_type & 0x1F, "other")


def _frame_kind(b_request: int, w_value: int) -> str:
    # SET_REPORT (0x09) / GET_REPORT (0x01) are the only transfers whose wValue
    # names a HID report; anything else (SET_IDLE, GET_DESCRIPTOR, ...) is "other".
    if b_request not in (0x09, 0x01):
        return "other"
    return FRAME_KINDS.get((w_value >> 8) & 0xFF, "other")


def transfer_to_record(transfer: RawTransfer, *, first_ts: Optional[int],
                       max_data: int) -> dict:
    """Turn a RawTransfer into the stable JSONL record described in the docstring."""
    setup = transfer.setup
    address = transfer.address
    raw = transfer.data
    report_id: Optional[int] = None
    payload = raw
    if len(raw) in (65, 4097) and raw[0] == 0x00:
        report_id = raw[0]
        payload = raw[1:]
    elif len(raw) in (65, 4097) and raw[0] != 0x00:
        # unusual: numbered report id that is not zero; strip whatever it is
        report_id = raw[0]
        payload = raw[1:]

    payload_hex = fmt_bytes(payload)
    data_hex = fmt_bytes(raw)
    truncated = False
    if max_data >= 0:
        if len(payload) > max_data:
            payload_hex = fmt_bytes(payload[:max_data])
            truncated = True
        if len(raw) > max_data:
            data_hex = fmt_bytes(raw[:max_data])

    record: dict[str, Any] = {
        "line": transfer.line,
        "tag": transfer.tag,
        "ts_us": transfer.ts_us,
        "t_ms": round((transfer.ts_us - first_ts) / 1000.0, 3) if first_ts is not None else 0.0,
        "addr": address.raw,
        "bus": address.bus,
        "device": address.device,
        "endpoint": address.endpoint,
        "direction": address.direction,
        "request_type": _request_type_name(setup["bmRequestType"]),
        "recipient": _recipient_name(setup["bmRequestType"]),
        "setup": {
            "bmRequestType": f"{setup['bmRequestType']:02x}",
            "bRequest": f"{setup['bRequest']:02x}",
            "wValue": f"{setup['wValue']:04x}",
            "wIndex": f"{setup['wIndex']:04x}",
            "wLength": f"{setup['wLength']:04x}",
        },
        "frame_kind": _frame_kind(setup["bRequest"], setup["wValue"]),
        "interface": setup["wIndex"] if setup["wIndex"] <= 0xFF else None,
        "status": transfer.status,
        "length": transfer.length,
        "captured": len(raw),
        "data_source": transfer.data_source,
        "report_id": report_id,
        "payload_hex": payload_hex,
        "payload_truncated": truncated,
        "data_hex": data_hex,
        "data_sha256": hashlib.sha256(raw).hexdigest() if raw else None,
        "opcode": None,
        "kind_label": None,
        "status_byte": None,
        "status_name": None,
    }

    if address.direction == "out":
        if len(payload) >= 2 and payload[0] == 0x04:
            record["opcode"] = fmt_bytes(payload[:2])
            record["kind_label"] = "command"
        else:
            record["kind_label"] = "continuation"
    else:
        record["kind_label"] = "reply"
        if len(payload) >= 4:
            status_byte = payload[3]
            record["status_byte"] = status_byte
            record["status_name"] = STATUS_NAMES.get(status_byte, f"0x{status_byte:02x}")
    return record


def parse_file(path: str, *, all_control: bool = False, bus: Optional[int] = None,
               device: Optional[int] = None, interface: Optional[int] = None,
               max_data: int = 256) -> tuple[list[dict], dict]:
    if path == "-":
        text = sys.stdin.read()
    else:
        with open(path, "r", encoding="utf-8", errors="replace") as handle:
            text = handle.read()
    transfers, stats = parse_usbmon(text, all_control=all_control, bus=bus,
                                    device=device, interface=interface)
    first_ts = transfers[0].ts_us if transfers else None
    records = [transfer_to_record(transfer, first_ts=first_ts, max_data=max_data)
               for transfer in transfers]
    stats["emitted"] = len(records)
    stats["out"] = sum(1 for record in records if record["direction"] == "out")
    stats["in"] = sum(1 for record in records if record["direction"] == "in")
    return records, stats


def write_jsonl(records: Iterable[dict], destination: str) -> None:
    if destination == "-":
        handle = sys.stdout
        close = False
    else:
        handle = open(destination, "w", encoding="utf-8")
        close = True
    try:
        for record in records:
            handle.write(json.dumps(record, sort_keys=False))
            handle.write("\n")
    finally:
        if close:
            handle.close()


def load_jsonl(path: str) -> list[dict]:
    records: list[dict] = []
    with open(path, "r", encoding="utf-8") as handle:
        for lineno, line in enumerate(handle, 1):
            stripped = line.strip()
            if not stripped or stripped.startswith("#"):
                continue
            try:
                record = json.loads(stripped)
            except json.JSONDecodeError as exc:
                raise ValueError(f"{path}:{lineno}: not valid JSON: {exc}") from None
            if not isinstance(record, dict):
                raise ValueError(f"{path}:{lineno}: record is not a JSON object")
            records.append(record)
    return records


# --------------------------------------------------------------------------- #
# diff
# --------------------------------------------------------------------------- #
def _setup(record: dict) -> dict:
    setup = record.get("setup")
    return setup if isinstance(setup, dict) else {}


def _payload_key(record: dict) -> str:
    if record.get("data_sha256"):
        return str(record["data_sha256"])
    value = record.get("payload_hex")
    return "" if value is None else str(value)


def diff_key(record: dict) -> str:
    setup = _setup(record)
    return "|".join(str(part) for part in (
        record.get("direction"),
        setup.get("bmRequestType"),
        setup.get("bRequest"),
        setup.get("wValue"),
        setup.get("wIndex"),
        record.get("length"),
        record.get("status"),
        _payload_key(record),
    ))


def _brief(record: dict) -> str:
    setup = _setup(record)
    direction = record.get("direction", "?")
    frame = record.get("frame_kind", "?")
    setup_text = " ".join(str(setup.get(key, "??"))
                          for key in ("bmRequestType", "bRequest", "wValue", "wIndex"))
    opcode = record.get("opcode")
    label = f"opcode={opcode}" if opcode else f"kind={record.get('kind_label')}"
    payload = record.get("payload_hex") or ""
    status = record.get("status")
    status_byte = record.get("status_byte")
    extra = f"status_byte=0x{status_byte:02x}" if status_byte is not None else ""
    return (f"{direction} {setup_text} {frame} {label} len={record.get('length')} "
            f"urb_status={status} {extra} payload[{len(payload.split())}B]={payload[:47]}"
            .rstrip())


def _opcode_histogram(records: Iterable[dict], direction: Optional[str] = None) -> dict:
    histogram: dict[str, int] = {}
    for record in records:
        if direction is not None and record.get("direction") != direction:
            continue
        label = record.get("opcode") or f"({record.get('kind_label') or '?'})"
        histogram[label] = histogram.get(label, 0) + 1
    return histogram


def _field_diff(a: dict, b: dict) -> dict[str, tuple[Any, Any]]:
    fields = ("direction", "length", "status", "status_byte", "opcode",
              "frame_kind", "kind_label")
    changes: dict[str, tuple[Any, Any]] = {}
    for name in fields:
        if a.get(name) != b.get(name):
            changes[name] = (a.get(name), b.get(name))
    setup_a, setup_b = _setup(a), _setup(b)
    for name in ("bmRequestType", "bRequest", "wValue", "wIndex", "wLength"):
        if setup_a.get(name) != setup_b.get(name):
            changes[f"setup.{name}"] = (setup_a.get(name), setup_b.get(name))
    return changes


def _first_payload_diff(hex_a: Optional[str], hex_b: Optional[str]) -> Optional[dict]:
    if not hex_a or not hex_b:
        if hex_a == hex_b:
            return None
        return {"offset": 0, "a": hex_a, "b": hex_b}
    try:
        bytes_a = parse_hex_bytes(hex_a)
        bytes_b = parse_hex_bytes(hex_b)
    except ValueError:
        return None
    limit = min(len(bytes_a), len(bytes_b))
    for offset in range(limit):
        if bytes_a[offset] != bytes_b[offset]:
            context = 6
            lo = max(0, offset - context)
            return {
                "offset": offset,
                "a_byte": bytes_a[offset],
                "b_byte": bytes_b[offset],
                "a_context": fmt_bytes(bytes_a[lo:offset + context + 1]),
                "b_context": fmt_bytes(bytes_b[lo:offset + context + 1]),
                "a_len": len(bytes_a),
                "b_len": len(bytes_b),
            }
    if len(bytes_a) != len(bytes_b):
        return {"offset": limit, "a_byte": None, "b_byte": None,
                "a_len": len(bytes_a), "b_len": len(bytes_b)}
    return None


def diff_captures(records_a: list[dict], records_b: list[dict],
                  *, only_direction: Optional[str] = None) -> dict:
    """Compare two capture JSONL streams; returns a structured diff."""
    if only_direction is not None:
        records_a = [r for r in records_a if r.get("direction") == only_direction]
        records_b = [r for r in records_b if r.get("direction") == only_direction]

    keys_a = [diff_key(record) for record in records_a]
    keys_b = [diff_key(record) for record in records_b]
    matcher = difflib.SequenceMatcher(a=keys_a, b=keys_b, autojunk=False)

    result: dict[str, Any] = {
        "a_count": len(records_a),
        "b_count": len(records_b),
        "equal": False,
        "opcodes": {
            "a": _opcode_histogram(records_a),
            "b": _opcode_histogram(records_b),
            "direction": only_direction or "both",
        },
        "blocks": [],
        "only_in_a": [],
        "only_in_b": [],
        "changed": [],
        "equal_count": 0,
    }

    for operation, a_start, a_end, b_start, b_end in matcher.get_opcodes():
        if operation == "equal":
            result["equal_count"] += a_end - a_start
            result["blocks"].append({
                "op": "equal", "a": [a_start, a_end], "b": [b_start, b_end],
                "count": a_end - a_start,
            })
            continue
        if operation in ("delete", "replace"):
            for index in range(a_start, a_end):
                entry = {"a_index": index, "record": records_a[index],
                         "brief": _brief(records_a[index])}
                result["only_in_a"].append(entry)
        if operation in ("insert", "replace"):
            for index in range(b_start, b_end):
                entry = {"b_index": index, "record": records_b[index],
                         "brief": _brief(records_b[index])}
                result["only_in_b"].append(entry)
        if operation == "replace":
            pair_count = min(a_end - a_start, b_end - b_start)
            for offset in range(pair_count):
                index_a = a_start + offset
                index_b = b_start + offset
                record_a, record_b = records_a[index_a], records_b[index_b]
                changes = _field_diff(record_a, record_b)
                payload_diff = _first_payload_diff(
                    record_a.get("payload_hex"), record_b.get("payload_hex"))
                if not changes and payload_diff is None:
                    continue
                result["changed"].append({
                    "a_index": index_a,
                    "b_index": index_b,
                    "fields": changes,
                    "payload": payload_diff,
                    "a_brief": _brief(record_a),
                    "b_brief": _brief(record_b),
                })
        result["blocks"].append({
            "op": operation, "a": [a_start, a_end], "b": [b_start, b_end],
        })

    result["equal"] = (not result["only_in_a"] and not result["only_in_b"]
                       and not result["changed"])
    return result


def render_diff_human(result: dict, name_a: str, name_b: str) -> str:
    lines = [
        f"diff A={name_a} ({result['a_count']} records)  "
        f"B={name_b} ({result['b_count']} records)",
        f"  equal: {'yes' if result['equal'] else 'NO'} "
        f"({result['equal_count']} records in identical runs)",
    ]
    histogram_a, histogram_b = result["opcodes"]["a"], result["opcodes"]["b"]
    labels = sorted(set(histogram_a) | set(histogram_b),
                    key=lambda label: (not label.startswith("04"), label))
    if labels:
        lines.append(f"  opcode histogram ({result['opcodes']['direction']}):")
        for label in labels:
            count_a = histogram_a.get(label, 0)
            count_b = histogram_b.get(label, 0)
            marker = "" if count_a == count_b else "   <-- differs"
            lines.append(f"    {label:<14s} A={count_a:4d}  B={count_b:4d}{marker}")
    if result["only_in_a"]:
        lines.append("  only in A:")
        for entry in result["only_in_a"]:
            lines.append(f"    A[{entry['a_index']:3d}] {entry['brief']}")
    if result["only_in_b"]:
        lines.append("  only in B:")
        for entry in result["only_in_b"]:
            lines.append(f"    B[{entry['b_index']:3d}] {entry['brief']}")
    if result["changed"]:
        lines.append("  same position, different content:")
        for entry in result["changed"]:
            lines.append(f"    A[{entry['a_index']:3d}] vs B[{entry['b_index']:3d}]")
            for field, (value_a, value_b) in entry["fields"].items():
                lines.append(f"      {field}: {value_a!r} -> {value_b!r}")
            payload = entry.get("payload")
            if payload:
                if payload.get("a_byte") is not None:
                    lines.append(
                        f"      payload first diff at byte {payload['offset']}: "
                        f"{payload['a_byte']:02X} -> {payload['b_byte']:02X}")
                    lines.append(f"        A[{payload['offset']}..]: {payload['a_context']}")
                    lines.append(f"        B[{payload['offset']}..]: {payload['b_context']}")
                else:
                    lines.append(
                        f"      payload length: {payload.get('a_len')} -> "
                        f"{payload.get('b_len')}")
    if result["equal"]:
        lines.append("  captures are identical")
    return "\n".join(lines)


# --------------------------------------------------------------------------- #
# CLI
# --------------------------------------------------------------------------- #
def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="capture.py",
        description="Normalize Linux usbmon text dumps of HX-KEG450 vendor HID "
                    "traffic into JSONL and diff captures. File-only: never opens "
                    "/dev/hidraw* or any USB device.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""\
examples:
  # capture (needs root + debugfs, then drive the vendor app under Wine):
  sudo modprobe usbmon
  sudo cat /sys/kernel/debug/usb/usbmon/3u > /tmp/vendor.mon
  ./capture.py /tmp/vendor.mon -o /tmp/vendor.jsonl
  ./capture.py --diff /tmp/start.jsonl /tmp/light.jsonl
  ./capture.py /tmp/vendor.mon --all-control -o /tmp/all.jsonl
""",
    )
    parser.add_argument("dump", nargs="?", metavar="DUMP",
                        help="usbmon text dump to normalize ('-' = stdin); "
                             "omit when using --diff")
    parser.add_argument("-o", "--output", default="-", metavar="PATH",
                        help="JSONL output file (default: stdout)")
    parser.add_argument("--all-control", action="store_true",
                        help="keep every control transfer, not only vendor-class "
                             "SET_REPORT/GET_REPORT (21 09 / a1 01)")
    parser.add_argument("--bus", type=int, default=None,
                        help="keep only this USB bus number")
    parser.add_argument("--device", type=int, default=None,
                        help="keep only this USB device address")
    parser.add_argument("--interface", type=int, default=None,
                        help="keep only transfers whose wIndex equals this interface")
    parser.add_argument("--max-data", type=int, default=256, metavar="BYTES",
                        help="cap hex bytes stored per record (default 256; the "
                             "SHA-256 always covers the full payload). -1 = no cap")
    parser.add_argument("--diff", nargs=2, metavar=("A.jsonl", "B.jsonl"),
                        default=None,
                        help="diff two capture JSONL files instead of parsing a dump")
    parser.add_argument("--only-direction", choices=["out", "in"], default=None,
                        help="diff only outgoing requests or only incoming replies")
    parser.add_argument("--json", action="store_true",
                        help="machine-readable output (parse summary / diff result)")
    parser.add_argument("--version", action="version", version=f"capture.py {__version__}")
    return parser


def cmd_diff(args: argparse.Namespace, parser: argparse.ArgumentParser) -> int:
    if args.dump is not None:
        parser.error("--diff takes two JSONL files; do not also pass a DUMP")
    try:
        records_a = load_jsonl(args.diff[0])
        records_b = load_jsonl(args.diff[1])
    except (OSError, ValueError) as exc:
        print(f"capture.py: {exc}", file=sys.stderr)
        return EXIT_ERROR
    result = diff_captures(records_a, records_b, only_direction=args.only_direction)
    if args.json:
        result["a_file"] = args.diff[0]
        result["b_file"] = args.diff[1]
        print(json.dumps(result, indent=2))
    else:
        print(render_diff_human(result, args.diff[0], args.diff[1]))
    return EXIT_OK if result["equal"] else EXIT_DIFFERENT


def cmd_parse(args: argparse.Namespace, parser: argparse.ArgumentParser) -> int:
    if args.dump is None:
        parser.error("a DUMP file is required (or use --diff A.jsonl B.jsonl)")
    try:
        records, stats = parse_file(
            args.dump,
            all_control=args.all_control,
            bus=args.bus,
            device=args.device,
            interface=args.interface,
            max_data=args.max_data,
        )
        write_jsonl(records, args.output)
    except (OSError, ValueError) as exc:
        print(f"capture.py: {exc}", file=sys.stderr)
        return EXIT_ERROR
    if args.json:
        print(json.dumps(stats, indent=2), file=sys.stderr)
    else:
        print(
            f"capture.py: {stats['emitted']} control transfers "
            f"(out {stats['out']}, in {stats['in']}) from {stats['lines']} lines; "
            f"skipped {stats['filtered']} filtered, {stats['no_setup']} without "
            f"submit, {stats['bad_lines']} malformed",
            file=sys.stderr)
    return EXIT_OK


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    if args.diff is not None:
        return cmd_diff(args, parser)
    return cmd_parse(args, parser)


if __name__ == "__main__":
    sys.exit(main())
