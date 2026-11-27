#!/usr/bin/env python3
"""Stage GCC 2000-10-03's public RTTI sources for tools/libmatch.py.

No game files are read or copied. Only the original sources and the minimal
target configuration needed by their headers go into the staging directory.
"""
import argparse
import shutil
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--gcc-tree", type=Path, required=True,
                        help="root of the extracted gcc-20001003 public source tree")
    parser.add_argument("--output", type=Path,
                        default=Path(__file__).resolve().parents[2] /
                        "gt4-thirdparty/gcc-runtime-20001003/rtti")
    args = parser.parse_args()
    cp = args.gcc_tree / "gcc/cp"
    files = [cp / name for name in ("tinfo.cc", "tinfo2.cc", "tinfo.h")]
    files += sorted((cp / "inc").glob("*"))
    files = [path for path in files if path.is_file()]
    for name in ("tinfo.cc", "tinfo2.cc", "tinfo.h", "typeinfo", "new", "exception"):
        if not any(path.name == name for path in files):
            parser.error(f"missing GCC runtime source: {name}")
    args.output.mkdir(parents=True, exist_ok=True)
    for path in files:
        shutil.copyfile(path, args.output / path.name)
    (args.output / "tconfig.h").write_text("#define BITS_PER_UNIT 8\n", encoding="ascii")
    (args.output / "stddef.h").write_text(
        "#ifndef GT4_RUNTIME_STDDEF\n#define GT4_RUNTIME_STDDEF\n"
        "typedef unsigned int size_t;\ntypedef int ptrdiff_t;\n"
        "#define NULL 0\n#endif\n", encoding="ascii")
    print(f"Staged {len(files)} public GCC source/header files in {args.output}")


if __name__ == "__main__":
    main()
