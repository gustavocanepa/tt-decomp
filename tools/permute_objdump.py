#!/usr/bin/env python3
"""Score one function while its compiler still sees the complete real source unit.

Both target and candidate are displayed at the same positive address so local
branch targets agree despite different positions within their objects. The
unchanged judge validates the complete group before any result is accepted.
"""
import argparse
import subprocess
import match


BASE = 0x10000000


def command(path, name, arch):
    _, _, functions = match.read_object(path, want_symbols=True)
    selected = [offset for symbol, offset, _ in functions if symbol == name]
    if len(selected) != 1:
        raise ValueError(f"expected one function {name}, found {len(selected)}")
    offset = selected[0]
    if offset >= BASE:
        raise ValueError("function offset exceeds scoring display base")
    return ["mips-linux-gnu-objdump", "-drz", "-m", arch,
            f"--adjust-vma={BASE - offset}", f"--disassemble={name}", path]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--function", required=True)
    parser.add_argument("--arch", required=True)
    parser.add_argument("object")
    args = parser.parse_args()
    subprocess.run(command(args.object, args.function, args.arch), check=True)


if __name__ == "__main__":
    main()
