# hx450-tools — safe opcode probe + usbmon capture harness

Tools for reverse-engineering the **HISKA HX-KEG450** keyboard's vendor HID
protocol without hand-writing inline python for every experiment.

* `probe.py` — control-channel (usage page `0xFF13`) opcode prober with a
  risk policy, a hard deny list, exact byte previews and replay.
* `opcodes.yaml` — the risk policy: every candidate `04 xx` opcode with its
  payload template, expected reply, risk level and source.
* `capture.py` — normalizes `usbmon` text dumps of the vendor tool into JSONL
  and diffs two captures mechanically.
* `README.md` — this file.

Everything is stdlib-only Python 3 (`python3 -m py_compile probe.py capture.py`).

> **Status:** written and verified **offline only** (dry-run, synthetic usbmon,
> in-memory fake device). No bytes were sent to the real keyboard while building
> it. The hardware owner runs the gated commands.

---

## 1. Ground truth this was built from

| Source | What it establishes |
|---|---|
| `../hiska-keg450-lcd/keg450.py` | working implementation: 65-byte `HIDIOCSFEATURE`/`HIDIOCGFEATURE` framing, 35 ms command spacing, status byte 3, page ACKs, lighting packet, clock sync |
| `../hiska-keg450-lcd/docs/PROTOCOL.md` | byte-level protocol recovered from usbmon + strace of the vendor MFC app under Wine |
| `../hx450-studio/src/hid.rs` | Rust re-implementation, same framing rules |
| `../research/hid-kb/AK820Pro_Protocol_Spec.md` | sibling-family opcode atlas (AK820 Pro, static RE) |
| `../research/hid-kb/REPORT.md`, `../research/hid-kb/repos/*` | cross-checks for `04 05`, `04 28`, page ACK, sibling quirks |

The two vendor interfaces are found by their **report-descriptor prefix**
(read-only sysfs, never by a hard-coded `hidrawN`):

```
06 68 FF ...   usage page 0xFF68  -> image node   4096-byte OUTPUT pages + page ACK
06 13 FF ...   usage page 0xFF13  -> control node 64-byte FEATURE commands + status
```

---

## 2. Safety model (read this first)

The keyboard is a real device with flash and user config. `probe.py` is built so
that a typo cannot silently send a destructive opcode.

### 2.1 Gates

| Flag | Meaning |
|---|---|
| `--dry-run` | Never opens anything. Prints the exact 65-byte ioctl buffer and the planned GET/ioctls. Works without any other flag. |
| `--i-understand` | **Required to open any `/dev/hidraw*` node.** Without it the tool exits 2 before even discovering the device. |
| `--allow-writes` | Required for opcodes whose risk is `cosmetic` or `state-changing`. Read-only probes (`04 F5`, `04 05`) only need `--i-understand`. |
| `--allow-unknown` | Required to send an opcode that is not classified in `opcodes.yaml` (also needs `--allow-writes`). |

* **Dangerous opcodes are refused outright**: risk `dangerous` in
  `opcodes.yaml`, or any opcode in the hard-deny list, is never sent — not with
  every flag, not in `--dry-run`, not through `--replay`. Exit code 3.
* The built-in hard-deny list (`04 0F` reset/erase, `04 7F` reserved /
  firmware-adjacent) **cannot be disabled**; `opcodes.yaml`'s `hard_deny:` list
  can only *add* to it.
* Unclassified opcodes are refused on hardware. Add them to `opcodes.yaml` with
  an explicit risk first, or force them with `--allow-unknown --allow-writes`.
* `--replay` is **all-or-nothing**: every frame is policy-checked *before* the
  device is opened. If any frame is refused the whole replay is aborted, so a
  sequence can never be half-sent. `--skip-dangerous` removes dangerous frames
  up front (they are never sent) and says so.
* `probe.py` is **control-channel only**. It never writes image pages. Replaying
  a capture that contains 4096-byte page writes is refused (replaying only the
  control half of an upload would leave the firmware mid-transfer).
* One-shot opcodes (`04 05`) print a loud warning: they poison the open
  connection until the node is reopened. Each CLI invocation opens its own
  connection, so run `04 05` last / on its own.

### 2.2 Never do this

* Do not run `probe.py` with `--i-understand` unless you are the hardware owner.
* Do not "sweep" unknown opcodes with `--allow-writes` on a device you care
  about; an unclassified `04 xx` can be a keymap reset or erase on some
  firmware revisions.
* Do not `--replay` a partial screen/keymap/macro transaction followed by a
  commit (`04 02`).

### 2.3 Exit codes

| Code | Meaning |
|---|---|
| `0` | success (assertions, if any, matched) |
| `1` | status/expectation mismatch, or captures differ (`capture.py --diff`) |
| `2` | safety gate / usage / policy-file error (nothing was sent) |
| `3` | opcode refused: dangerous, hard-denied, or unclassified |
| `4` | device/transport error (node missing, ioctl failure) |
| `130` | interrupted |

---

## 3. `probe.py`

### 3.1 Quick start

```bash
cd ~/Personal/hx450-tools
python3 -m py_compile probe.py capture.py      # sanity
./probe.py discover                            # sysfs only, opens nothing
./probe.py opcodes -v                          # risk table + sources
./probe.py send "04 18" --dry-run              # exact bytes, no hardware
./probe.py poll --dry-run                      # planned FEAT_QUERY reads
./probe.py replay my-sequence.json --dry-run   # whole sequence preview
```

Only after the dry-run looks right (and with the cable attached):

```bash
sudo ./probe.py poll --i-understand                        # read-only: 04 F5
sudo ./probe.py send "04 18" --i-understand --allow-writes # session begin
sudo ./probe.py replay my-sequence.json --i-understand --allow-writes
```

Access does not have to be root if the udev rule from `../hiska-keg450-lcd/udev`
is installed and your user is in the `input` group.

### 3.2 Commands

#### `discover` — locate the two vendor nodes (sysfs only)

Reads `/sys/class/hidraw/hidraw*/device/report_descriptor` and `uevent`; it
never opens `/dev/hidraw*`. Prints role, descriptor prefix, VID:PID, product
name and the chosen image/control nodes. Exit 4 if no control node.

#### `opcodes` — show the policy table

`--risk read-only|cosmetic|state-changing|dangerous|all` filters; `-v` adds
expected reply, source note and one-shot warnings. `--json` for scripts.

#### `send OPCODE [--payload HEX] [--expect STATUS]` — one command

`OPCODE` is two bytes (`"04 18"`, `"0418"`, `"0x04,0x18"`). If `--payload` is
omitted the template from `opcodes.yaml` is used (e.g. `04 72` gets its 8-page
metadata template). `--expect` asserts the reply status (`ok` / `rejected` /
`no-verdict` / `any` / a byte) and makes the exit code 1 on mismatch. `--json`
emits a machine-readable reply.

Output shows the request payload, the wrapped 65-byte wire frame, the decoded
status byte 3, the echo check and a hexdump:

```
opcode   : 04 18  (begin)   risk=cosmetic
reply    : status byte 3 = 0x01 (ok); echo=True
request payload (64 B; wire frame = 00 + this = 65 B):
00000000  04 18 00 00 ...
reply payload (64 B):
00000000  04 18 00 01 ...
```

Reply semantics (from `PROTOCOL.md` §2.2): **byte 3** is the status —
`0x01` accepted, `0xFF` rejected/busy, `0x00` echo/no verdict. Commands are
echoed back with the verdict patched in, so `echo=True` on the first two bytes
is the normal case.

#### `poll [--opcode "04 F5"] [--packets 9]` — multi-packet read

Implements the vendor's `FEAT_QUERY` primitive: SET the command
(`04 F5 ... 09`, wire byte 8 = packet count), wait 5 ms, GET the ACK, then GET
the requested number of 64-byte data reports. Use this instead of `send` for
`04 F5`; `send` only reads the one ACK report.

#### `replay FILE` — re-apply a captured/labelled sequence

Accepts JSON (a list, or `{"steps": [...]}`, `{"records": [...]}`,
`{"commands": [...]}`) or JSONL. A step may be:

```json
{"opcode": "04 18", "expect": "ok"}
{"opcode": "04 72", "payload": "00 00 00 00 00 00 08 00"}
{"payload_hex": "01 FF 00 FF 00 00 00 00 00 05 03 00 00 00 AA 55 <zero-padded to 64>",
 "name": "lighting data block"}
{"opcode": "04 02", "delay_ms": 50}
```

* `payload` = bytes after the 2-byte opcode; `payload_hex` = a full 64-byte
  frame (or 65-byte wire frame with the `0x00` report id; it is stripped).
* `opcode` must be a `04 xx` command header. Non-`04` frames are data
  continuation blocks and are given as `payload_hex` only.
* `expect`: `ok` / `rejected` / `no-verdict` / `any` or a byte value. Without it
  a `rejected`/`no-reply` step is treated as a failure.
* Steps stop the replay on a non-matching status unless `--keep-going` is
  given; on abort the firmware may be left mid-transaction (close/reopen the
  node before further writes).
* `capture.py` JSONL works directly as a replay file: incoming reply records are
  skipped, the outgoing `04 xx` commands and continuation blocks are replayed.
  Page writes (4096-byte data) cause the whole replay to be refused.
* `--skip-dangerous` skips dangerous/hard-denied frames (never sends them);
  without it the whole replay is refused. `--save-sent PATH` writes the
  sequence actually sent for later reuse.

### 3.3 Library use

```python
import sys
sys.path.insert(0, "~/Personal/hx450-tools")   # or run from that directory
from probe import Policy, Probe

policy = Policy.load("opcodes.yaml")
with Probe.connect(i_understand=True, allow_writes=True, policy=policy) as keyboard:
    reply = keyboard.send(b"\x04\x18")                 # begin
    print(reply.status_name, reply.echo_ok)
    print(reply.hexdump())
    colours = keyboard.query(b"\x04\xF5", bytes(6) + b"\x09", packets=9)
    for index, packet in enumerate(colours.packets):
        print(index, packet.hex(" "))
```

`Probe.connect(i_understand=False)` raises `SafetyError`; `Probe.send()` raises
`PolicyDenied` before touching the transport. `dry_run=True` returns a
`DryRunTransport` that only prints. `send()` returns a `Reply` with
`.request`, `.data`, `.status`, `.status_name`, `.echo_ok`, `.status_name`,
`.hexdump()`, `.to_dict()`.

### 3.4 How replies are read (and why it is careful)

The firmware answers through **GET_FEATURE**, not through interrupt IN. A fast
read can return the previous command's report ("phantom ACK": byte 3 still
holds the value you wrote, which reads as accepted). `probe.py` therefore:

1. drains stale replies before every command;
2. waits **2 ms** between SET and GET (documented minimum is 1 ms);
3. polls GET until the reply's first two bytes **echo the command** (bounded by
   `--timeout`, default 0.30 s);
4. retries the *first* command once if it is rejected — a known firmware quirk
   where the first command after opening is spuriously rejected;
5. spaces every command by **35 ms** (`cmd_delaytime` from the vendor layout).

---

## 4. `opcodes.yaml` — the risk policy

Each entry has `opcode`, `name`, `risk`, `payload` (bytes after the opcode,
hex), `expected`, `source`, optional `notes` and optional
`one_shot_poison: true`. Risk levels:

| Risk | Meaning |
|---|---|
| `read-only` | no persistent state change |
| `cosmetic` | session-only / visible-only; needs a later `04 02` to persist |
| `state-changing` | persists settings (clock, remap, colours, macros, flash commit) |
| `dangerous` | erase/reset/firmware-adjacent or unknown-destructive — refused |

### 4.1 Current table

| Opcode | Name | Risk | Summary |
|---|---|---|---|
| `04 02` | commit | state-changing | commits the pending transaction to flash; only after a complete stream; flash wear assumed |
| `04 05` | device info | read-only | one-shot, poisons the connection until reopen; run last |
| `04 0F` | factory reset / erase | **dangerous** | hard-denied, never sent |
| `04 11` | base-layer key map | state-changing | 576-byte table / 9 packets when actually written; header-only template |
| `04 13` | lighting entry | cosmetic | wire byte 8 must be `0x01`; needs data block + `04 02` |
| `04 15` | macro memory | state-changing | AK820 macros vs F75 "erase display slots" — ambiguous |
| `04 17` | system settings | state-changing | header-only probe (`payload[6]=1` declared but no packet sent) |
| `04 18` | begin | cosmetic | opens a transaction |
| `04 19` | macro upload begin | cosmetic | AK820 macro begin vs F75 "erase display memory" — ambiguous |
| `04 20` | per-key real-time frame | cosmetic | streaming, no session wrapper |
| `04 23` | per-key static colours | state-changing | persists with `04 02` |
| `04 27` | Fn-layer key map | state-changing | same shape as `04 11` |
| `04 28` | clock sync | state-changing | layout ambiguous (see §7) |
| `04 72` | screen metadata | cosmetic | slot + page count; commit only after complete image stream |
| `04 7F` | reserved / firmware-adjacent | **dangerous** | hard-denied, never sent |
| `04 F0` | end | cosmetic | session close; sibling reports conflict on side effects |
| `04 F5` | read key colours / heartbeat | read-only | FEAT_QUERY multi-packet read; use `poll` |

### 4.2 Adding a candidate opcode

Append an entry to the `opcodes:` list and give it an explicit risk. The loader
validates every field on every run (bad risk / bad hex / duplicate opcode are
fatal). Unknown opcodes on hardware are refused until you do this.

The file is a strict YAML subset (top-level scalars, plus lists of mappings with
scalar values; quoted strings, ints, booleans). It is also valid normal YAML —
`python3 -c "import yaml; yaml.safe_load(open('opcodes.yaml'))"` works if
PyYAML is installed, but PyYAML is **not** a dependency of the tools.

---

## 5. `capture.py` — usbmon text → JSONL → diff

File-only tool: it never opens `/dev/hidraw*` or any USB device. It parses the
usbmon **text** API output (`1t` and `1u` formats) and matches each URB
submission with its callback by tag.

### 5.1 Capturing vendor traffic

```bash
sudo modprobe usbmon
ls /sys/kernel/debug/usb/usbmon/          # pick the bus of the keyboard
sudo cat /sys/kernel/debug/usb/usbmon/3u > /tmp/vendor.mon   # Ctrl-C when done
# ...drive the vendor DeviceDriver.exe (under Wine) in the meantime...
```

`PROTOCOL.md` §8 describes how the original capture was made (Wine + strace of
`winedevice.exe` + usbmon, plus the `config.xml` MI_01 trick that lets Wine
enumerate the device). Find the bus number from
`/sys/kernel/debug/usb/devices` (`T: Bus=03 ...`).

### 5.2 Normalize

```bash
./capture.py /tmp/vendor.mon -o /tmp/vendor.jsonl
./capture.py /tmp/vendor.mon --all-control -o /tmp/all.jsonl    # include std requests
./capture.py /tmp/vendor.mon --bus 3 --device 2 -o /tmp/kb.jsonl
cat /tmp/vendor.mon | ./capture.py - -o /tmp/vendor.jsonl       # stdin
```

Default filter keeps vendor-class `SET_REPORT` (`21 09`) and `GET_REPORT`
(`a1 01`) control transfers — the 0xFF13 feature channel — and drops everything
else (bulk, interrupt, isoc, standard requests, other devices unless filters
say otherwise). Only **completed** control transfers are emitted; image page
ACKs are interrupt-IN reports on the image node and are therefore not part of a
control-transfer JSONL.

### 5.3 JSONL record

One JSON object per line; stable field names:

| Field | Meaning |
|---|---|
| `line`, `tag`, `ts_us`, `t_ms` | provenance and relative time |
| `addr`, `bus`, `device`, `endpoint`, `direction` | usbmon address (`bus` is null for old `1t` dumps) |
| `setup` | `bmRequestType`, `bRequest`, `wValue`, `wIndex`, `wLength` as hex strings |
| `request_type`, `recipient` | decoded from `bmRequestType` |
| `frame_kind` | `feature` / `output` / `input` / `other` (from `wValue`, only for SET/GET_REPORT) |
| `interface` | `wIndex` when it fits a byte |
| `status`, `length`, `captured` | URB status, reported length, bytes present in the dump |
| `data_source` | `submit` (control OUT data lives on the S line) or `callback` (control IN) |
| `report_id` | leading `0x00` when a 65/4097-byte transfer had one |
| `payload_hex` | data with report id stripped, capped by `--max-data` (default 256) |
| `payload_truncated`, `data_hex` | truncation flag and raw data prefix |
| `data_sha256` | SHA-256 of the **full** raw data (always covers everything) |
| `opcode` | `"04 18"` for outgoing `04 xx` command headers, else null |
| `kind_label` | `command` / `continuation` / `reply` |
| `status_byte`, `status_name` | reply byte 3 decoded for inbound GET_REPORT |

Example line (pretty-printed here; the file is one line per record):

```json
{"line":4,"tag":"ffff880000001001","ts_us":100000000,"t_ms":0.0,
 "addr":"Co:3:002:0","bus":3,"device":2,"endpoint":0,"direction":"out",
 "request_type":"class","recipient":"interface",
 "setup":{"bmRequestType":"21","bRequest":"09","wValue":"0300","wIndex":"0003","wLength":"0041"},
 "frame_kind":"feature","interface":3,"status":0,"length":65,"captured":65,
 "data_source":"submit","report_id":0,
 "payload_hex":"04 18 00 00 ...","payload_truncated":false,
 "data_sha256":"...","opcode":"04 18","kind_label":"command",
 "status_byte":null,"status_name":null}
```

### 5.4 Diff

```bash
./capture.py --diff /tmp/start.jsonl /tmp/light.jsonl
./capture.py --diff A.jsonl B.jsonl --json --only-direction out
```

Compares transfer sequences with `difflib`, reports equal runs, records only in
A/B, per-field changes, the first differing payload byte with context, and an
opcode histogram (A vs B). Exit 0 = identical, 1 = differences, 2 = file error.
This is how you answer "what does the vendor tool send differently when I click
X?": capture two sessions, diff them, turn the new command into an
`opcodes.yaml` entry, then reproduce it with `probe.py`.

---

## 6. Protocol reference (what the code implements)

```
SET:  ioctl(fd, HIDIOCSFEATURE(65),  b"\x00" + payload_64)   # report id + 64 bytes
GET:  ioctl(fd, HIDIOCGFEATURE(65),  buf_65) -> strip buf[0] -> 64-byte reply
```

| Fact | Value |
|---|---|
| Control node | usage page `0xFF13`, 64-byte FEATURE reports (65 bytes on the wire) |
| Image node | usage page `0xFF68`, 4096-byte OUTPUT pages written as 4097 bytes, ACK starts `01 5A 02` on the same node |
| Status | reply payload **byte 3**: `01` accepted, `FF` rejected, `00` no verdict/echo |
| Timing | 35 ms between commands (`cmd_delaytime=35`), ≥1 ms SET→GET |
| Command family | `04 xx`, often `AA 55` end-of-data marker in data blocks |

Firmware quirks (documented in `PROTOCOL.md` / sibling reports) that the tools
handle or warn about:

* **Reply queue lags** — drain before every command; otherwise you read the
  previous reply. `probe.py` drains and echo-matches.
* **Spurious first rejection** — the first command after opening can be
  rejected; `probe.py` retries it once.
* **Read-too-fast phantom ACK** — a GET with no delay can return your own
  request with status still `0x00`. 2 ms SET→GET plus echo matching avoids this.
* **hidraw strips report id** — feature buffers must be 65 bytes; page buffers
  4097. Implemented in the transport (control) and in `keg450.py` (pages).
* **`04 05` is one-shot** — poisons the connection until reopen.
* **`04 F0` is contradictory** — session end on AK820, possibly harmful for
  image-flash persistence on AKS075. Use only to close partial transactions.
* **Page ACK placement** — per-page ACK is read from the *image* node, not the
  control node; `probe.py` does not do image pages at all.

---

## 7. Ambiguities found while implementing (feedback for the hardware owner)

These are the points where the sources disagree or hardware confirmation is
missing. `opcodes.yaml` notes repeat the ones that affect a specific opcode.

1. **`04 28` clock layout.** `keg450.py` (HX-KEG450 vendor capture) sends
   `04 28 <yy> <mm> <dd> <hh> <mm> <ss>` in the command header; AK820 / AULA /
   AKS075 send a 64-byte **data block** instead:
   `00 <slot> 5A <yy> <mm> <dd> <hh> <mm> <ss> 00 <dow> ... AA 55`, and
   `04 28`'s payload byte 8 is a packet count. `opcodes.yaml` uses the
   HX-KEG450 layout as template and says so. Verify with the real RTC before
   trusting either.
2. **`04 F5` semantics.** `PROTOCOL.md` calls it a ~30 ms heartbeat poll
   (`04 F5 ... 09`); the AK820 atlas says it is a FEAT_QUERY read of the
   per-key colour table (9 × 64-byte packets on a 576-byte table). Both are
   consistent with a poll that happens to read LEDs, but the *reply layout for
   this 160×96 board* is unverified — `poll` deliberately just dumps the raw
   packets instead of interpreting them.
3. **`04 72` byte 2 (screen slot).** Seen as `0x00`, `0x01`, `0x02`, `0x03`
   on sibling firmware, "inert" on one. The template uses `0x00` per the
   HX-KEG450 capture; the ACK echo should be checked before trusting it.
4. **`04 F0` end-of-session.** Sibling reports contradict (harmless session
   end vs restarting the GIF player / breaking flash persistence). Marked
   cosmetic but flagged in `opcodes.yaml`.
5. **`04 11` / `04 27` / `04 15` / `04 19` / `04 17` semantics split.**
   AK820 atlas: keymaps / macros / settings. F75 firmware labels: "erase
   display slots", "erase display memory", "reset …". Unknown which applies to
   the HX-KEG450. They are `state-changing`, and the templates send only the
   header (no data block, no commit) so a probe cannot rewrite a table.
6. **`04 05` one-shot poisoning.** Unverified on this firmware (measured on
   AULA EA75). The warning is best-effort: a CLI invocation cannot reopen a
   connection mid-run, so put `04 05` in its own invocation / last in a replay.
7. **Reply echo assumption.** `probe.py` treats a reply as valid only when its
   first two bytes echo the command (`PROTOCOL.md`: commands are echoed with the
   verdict patched in). If some opcode answers differently, `-v` will show
   "reply echoes .. expected .." and the reply may come back with
   `echo=False`; treat that as "verify manually" rather than success.
8. **Status `0x00` ambiguity.** "No verdict" can mean "plain echo" or "ignored",
   and that can differ per opcode. `send` reports it but does not call it
   success; replay tolerates it unless you assert `expect`.
9. **Image path is out of scope here.** Page writes are 4097-byte OUTPUT
   reports on `0xFF68` and the per-page ACK is an interrupt-IN report on the
   same node. `capture.py` emits control transfers only; `probe.py` refuses
   4096-byte replay frames. Use `keg450.py` for screen work.
10. **Commit wear.** Flash wear per `04 02` is assumed but unmeasured; keep
    commits rare (the vendor keeps refresh intervals ≥30 s for live content).

---

## 8. Verification performed (offline)

* `python3 -m py_compile probe.py capture.py` — clean.
* `probe.py discover` — read the real sysfs descriptors of a connected
  HX-KEG450 (`hidraw6` = image `06 68 ff`, `hidraw7` = control `06 13 ff`) and
  opened nothing.
* `probe.py send … --dry-run` / `poll --dry-run` / `replay … --dry-run` —
  printed exact 65-byte frames; dangerous opcodes still exit 3.
* A 111-check offline test suite (in-memory fake transport + monkeypatched
  `os.open`) proves: no `os.open` call in `discover`, `--dry-run`, or the
  `--i-understand`-missing path; only one `os.open` call site in `probe.py`
  (inside `ControlTransport.open`); policy matrix; echo/retry logic; FEAT_QUERY
  collection; CLI exit codes; capture parsing (including control OUT data on
  the submit line and control IN data on the callback line), `1t` addresses,
  truncation + SHA-256, and diffing.
* Synthetic usbmon dumps (written under `/tmp`, never derived from the device)
  exercised `capture.py`: 19 control transfers parsed from a 56-line dump,
  image page ACK interrupt lines skipped, `--all-control`/`--bus`/`--device`
  filters, identical diff (exit 0) and one-byte-different diff (exit 1).

## 9. Related files

* `../hiska-keg450-lcd/` — Python library/CLI for screen + lighting (working).
* `../hx450-studio/` — Rust/TUI studio implementation.
* `../research/hid-kb/` — sibling-family opcode atlases and the vendor package.
