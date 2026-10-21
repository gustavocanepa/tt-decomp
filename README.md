# Tourist Trophy decompilation

[![Code](https://decomp.dev/gustavocanepa/tt-decomp.svg?mode=shield&measure=code&label=Code)](https://decomp.dev/gustavocanepa/tt-decomp)
[![Functions](https://decomp.dev/gustavocanepa/tt-decomp.svg?mode=shield&measure=functions&label=Functions)](https://decomp.dev/gustavocanepa/tt-decomp)

A work-in-progress matching decompilation of Polyphony Digital's Tourist Trophy (PS2, `CORE.TT`,
NTSC-U SCUS-97502 v1.00): C++ source that compiles, with the original compiler, to the exact same
instructions as the game. The long-term goal is a native port.

Tourist Trophy is built on Gran Turismo 4's code base. It is a sister project of the
[Gran Turismo 4 decompilation](https://github.com/gustavocanepa/gt4-decomp): same compiler, same
tools, and many functions that are identical in both games. Format documentation comes from the
[Gran Turismo Modding Hub](https://nenkai.github.io/gt-modding-hub/).

**This repository contains no game data.** You need your own copy of the game.

## Status

- The executable is understood: `CORE.TT` is Salsa20-encrypted and raw-deflate compressed, loading
  at `0x00100000` with entry `0x00100008`; 14,866 functions are reached by calls.
- The compiler family is the same as GT4's (Sony's ee-gcc 2.96, gcc 2.x C++ mangling, the same
  `PDISTD` library).
- 3,232 functions (23%) are identical to a function already matched in the GT4 project, and 2,880
  more are identical to GT4 functions still open: one match settles both games. See
  [`knowledge/tt.md`](knowledge/tt.md).
<!-- progress:start -->
- **Progress (October 2026, commit `970e72b7f58b`): 24,359 of 31,593 functions match (77.1%), 41.8% of the code bytes; 85.7% of the sources are clean.**
  Clean source: 85.7% of the 24,359 function sources are free of m2c
  macros, raw offset casts, temp_/var_ names and pasted headers (`tools/clean_report.py`).
  The live numbers are on the `progress` branch (objdiff report format); this paragraph is written by
  `tools/update_readme.py` from `progress/report.json`, never by hand.
- **The full build reproduces the original executable** (both loaded segments, SHA-1 checked):
  23,211 functions, 37.7% of the code bytes, are linked from C/C++
  source at their original addresses, and the rest is assembled from splat's disassembly of your own
  executable. 1,281 of 2,284,744 data bytes (0.06%; `.data` plus `.bss`)
  are the constants of 55 functions, placed from source at their original addresses.
  0 functions that were hand-written assembly in the original are listed in
  [`config/asm_functions.txt`](config/asm_functions.txt) and not counted.
<!-- progress:end -->

## Credits

Started and maintained by **Gustavo Canepa** ([@gustavocanepa](https://github.com/gustavocanepa)),
with AI agents (Anthropic's Claude) doing the bulk of the matching. Thanks to Nenkai and the Gran
Turismo modding community, whose research made the file formats understandable.

If you use these tools or this work elsewhere, please credit this project (MIT, see [LICENSE](LICENSE)).

This license covers the tools, documentation and the source code written for this project.
Tourist Trophy is a trademark of Sony Interactive Entertainment; this project is not affiliated
with or endorsed by Sony Interactive Entertainment or Polyphony Digital. It contains no game data,
and you need your own copy of the game to use it.

## Contributing

Help is welcome: matching functions, naming them, reconstructing structs and classes, or improving
the tools. Start with [CONTRIBUTING.md](CONTRIBUTING.md).

## Setup

Requirements: Python 3.11+ with `rabbitizer` (`pip install rabbitizer`), and Linux or WSL (Ubuntu).

1. Dump your disc and place the image as described in [`orig/README.md`](orig/README.md), then
   extract, decrypt and convert the executable (commands there).
2. Set up the Linux side once: `bash tools/setup_linux.sh` (compiler, MIPS binutils, permuter).
3. Split the executable with splat (assembly for every function, under `build/splat/`):
   `bash tools/splat.sh` (in WSL/Linux).
4. Check that the full build reproduces your executable: `python tools/build.py`.
5. Build the function list and the duplicate groups:
   `python tools/find_functions.py orig/SCUS-97502/files/CORE.TT build/functions.csv` and
   `python tools/dedup.py scan`.

The tools and how to reuse them for another game are described in [TOOLS.md](TOOLS.md).

## Working on a function

```sh
python tools/match.py asm 100220                       # show the original
python tools/match.py check 100220 src/func_00100220.c # compile and compare
```

A function is done when `check` prints `MATCH` and `python tools/build.py` still reproduces the
original (it links every function at its real address and compares SHA-1).
