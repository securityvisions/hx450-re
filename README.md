# HX450 RE kit

Reverse-engineering kit for the **HISKA HX-KEG450** keyboard — a 160×96 LCD,
RGB lighting, key remapping, macros and a 2.4 GHz dongle, all driven by a private
HID protocol that only the vendor's Windows app understood.

![license](https://img.shields.io/badge/license-MIT-blue)
![protocol](https://img.shields.io/badge/protocol-fully%20mapped-f0a33c)
![firmware](https://img.shields.io/badge/firmware-SONiX%20SN32F2xx-888)
![hardware](https://img.shields.io/badge/hardware-HX--KEG450-4cc38a)
![platform](https://img.shields.io/badge/platform-Linux-333?logo=linux&logoColor=white)

This repository holds the **evidence, the tooling and the deep notes**. The
shipping tools live in two sibling repos:

| Repo | What it is |
|---|---|
| [**hiska-keg450-lcd**](https://github.com/securityvisions/hiska-keg450-lcd) | Python CLI + protocol reference — image/GIF upload, lighting, live frames |
| [**hx450-studio**](https://github.com/securityvisions/hx450-studio) | Rust + egui desktop studio — canvas editor, timeline, lighting, live providers |
| **hx450-re** (here) | gated opcode prober, usbmon capture/diff, Ghidra evidence, full opcode atlas |

---

## What was recovered

The vendor tool is an MFC binary that speaks **fifteen wired opcodes** over a
64-byte HID Feature channel, plus a separate 33-byte 2.4 GHz dongle family and a
device→host event channel. Everything the UI can do is mapped.

| Area | Capability | Opcode |
|---|---|---|
| Lighting | 19 on-board effects, colour, brightness, speed, direction | `04 13` |
| | per-key static colours (576 B RGB / 192 B mono) | `04 23` |
| | real-time per-key stream, ~30 ms frames | `04 20` |
| | per-key colour **readback** (9 × 64 B) | `04 F5` |
| Keys | key map, base layer (576 B) | `04 11` |
| | key map, Fn layer | `04 27` |
| Macros | 3584-byte macro image, 100-entry offset table | `04 19` + `04 15` |
| Settings | Win/Alt+F4/Alt+Tab lock, Fn switch, sleep time, debounce | `04 17` |
| Screen | 160×96 RGB565 boot animation, 255 frames, 256-byte header | `04 72` + 4096 B pages |
| Clock | RTC sync | `04 28` |
| Session | begin / commit / end | `04 18` / `04 02` / `04 F0` |

Full byte layouts, builder addresses and confidence labels:
[`docs/OPCODES.md`](docs/OPCODES.md) · plain-language matrix:
[`hiska-keg450-lcd/docs/CAPABILITIES.md`](https://github.com/securityvisions/hiska-keg450-lcd/blob/main/docs/CAPABILITIES.md).

### What is *not* there

- **No firmware blob** anywhere in the vendor package (0-byte PE overlays, no
  RCDATA, `innoextract -t` accounts for every payload byte).
- **No firmware dump path.** The MCU is SONiX SN32F2xx; public SONiX ISP has no
  read-memory command, so dumping needs SWD.
- **No `04 05` device-info command**, no protocol checksum (`AA 55` is just a
  marker), and **no profile byte on the wire** — the three UI profiles are a
  host-side database.

---

## The toolkit

`tools/` holds a deliberately paranoid prober so hardware experiments never turn
into accidents.

```bash
cd tools

./probe.py discover                    # sysfs only: find the two vendor interfaces
./probe.py opcodes -v                  # the risk policy: every candidate opcode
./probe.py send "04 18" --dry-run      # print the exact 65-byte frame, touch nothing

./probe.py poll --i-understand                       # read-only 04 F5 query
./probe.py send "04 28" --payload "<yy mm dd hh mm ss>" \
           --i-understand --allow-writes             # clock sync
./capture.py /tmp/vendor.mon -o /tmp/vendor.jsonl    # usbmon dump -> JSONL
./capture.py --diff a.jsonl b.jsonl                  # mechanical capture diff
```

**Safety model**

| Flag | Meaning |
|---|---|
| *(none)* | dry-run only; never opens `/dev/hidraw*` |
| `--i-understand` | allowed to open the device; read-only opcodes only |
| `--allow-writes` | cosmetic / state-changing opcodes |
| `--allow-unknown` | unclassified opcodes |
| — | `04 0F`, `04 7F` and anything marked `dangerous` are refused at **every** exit |

Policy is checked **before** the node is opened, so a refused run never touches
the hardware. Replay is all-or-nothing. Details: [`tools/README.md`](tools/README.md).

---

## Documents

| Document | Contents |
|---|---|
| [`docs/OPCODES.md`](docs/OPCODES.md) | the atlas: five send primitives, every wired opcode with byte layouts, keymap/macro/settings/clock/screen block formats, 2.4 GHz family, event channel, UI→opcode map, negative findings |
| [`docs/FIRMWARE.md`](docs/FIRMWARE.md) | MCU identification, proof that no blob ships, update path, dump assessment |
| [`docs/HARDWARE-NOTES.md`](docs/HARDWARE-NOTES.md) | on-device measurements: readback channel, event channel, double page ACKs, firmware version |
| [`docs/RE-METHOD.md`](docs/RE-METHOD.md) | how it was recovered — Ghidra 12 headless, objdump call-site sweeps, evidence layout |
| [`docs/evidence/`](docs/evidence/) | 65 Ghidra-decompiled functions, one per cited address (`VA = RVA + 0x400000`) |

---

## How it was done

1. The vendor installer was unpacked with `innoextract` and its MFC app analysed
   statically (Ghidra 12.1.2 headless, all 5,654 functions decompiled).
2. The app was also run under Wine — patching one line of its `config.xml` made
   it detect the device — and driven with `xdotool` while `usbmon` and `strace`
   captured every control transfer.
3. Recovered sequences were replayed from Linux against the real keyboard until
   it acknowledged, byte for byte.
4. Ambiguous fields were settled by controlled A/B tests on hardware (colourful
   flag, `04 13` write mode, page ACK placement, slot values).

The full narrative is in [`docs/RE-METHOD.md`](docs/RE-METHOD.md); the earlier
first-pass write-up is in
[`research/hid-kb/REPORT.md`](https://github.com/securityvisions/hiska-keg450-lcd).

---

## Risk notes

Every opcode here **writes device state**. Key remapping and macros can leave a
keyboard that is awkward to type on until it is restored from the vendor app's
database; per-key lighting and settings are cosmetic. There is no factory-reset
opcode — only the vendor app's re-upload. Do not poke `04 0F`-style erase/reset
opcodes from related families: they are not part of this build and the tooling
refuses them.

Vendor firmware v1.06 is what this was tested against (`bcdDevice 0x0106`); the
vendor app itself expects 1.20 and offers an update it cannot deliver.

## License

[MIT](LICENSE). Not affiliated with HISKA. Everything here was derived from
observing software and hardware that the author owns.
