# Tourist Trophy: what is established

Facts about this game's executable, as far as the project has measured them. Compiler habits shared
with Gran Turismo 4 are in `ee-gcc-2.96.md`; the GT4 project's `knowledge/gt4.md` covers the code
base both games share (C++ idioms, STL, strings, handles) and applies here until shown otherwise.

## The executable

- `CORE.TT` (NTSC-U SCUS-97502 v1.00) is Salsa20-encrypted (8-byte IV first, CRC last, key
  "PolyphonyDigital"), then laid out like `CORE.GT4`: boot flags, size, raw deflate; inside, two
  SHA-512 hashes, entry `0x00100008` and three sections, the last 24 bytes of the code repeated as a
  section of their own (dropped by `core2elf.py`, as in GT4).
- Code `0x00100000-0x00578cb8` (4.47 MB), data `0x00578d00-0x0061b5fc` (651 KB); decompressed
  image 5.36 MB, against GT4's 5.36 MB of a larger code segment (0x00100000-0x00617a14).
- 14,866 functions are reached by `jal` (GT4: 15,068 by the same count).
- The C++ symbols left in the data (mangled names such as `t10std_vector2ZQ26PDISTD11MathVector...`)
  use gcc 2.x mangling and the same `PDISTD` library as GT4: same compiler family.

## Shared code with Gran Turismo 4 (measured 2026-10-09)

Function bodies compared with link-time values masked (tools/dedup.py's hashing), against GT4's
function list and matched sources:

| TT functions (14,305 of at least 3 instructions) | functions | code bytes |
|---|---|---|
| identical to a GT4 function already matched | 3,232 | 4.9% |
| identical to a GT4 function not matched yet | 2,880 | 13.9% |
| at least 90% identical (same length within 2 instructions) | 862 | 4.1% |
| 70-90% identical | 893 | 2.0% |
| no close GT4 counterpart by this measure | 6,438 | 75.1% |

The last row is an upper bound: the comparison only pairs functions of nearly equal length, so a
large function with one inserted statement counts as new. No Adhoc script VM was found by name
(GT4's `Adhoc` strings are absent).
