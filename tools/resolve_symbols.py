#!/usr/bin/env python3
"""Give an address to the symbols matched sources call that the symbol table does not know yet.

A matched source can use a name the project has no address for: a soft-float helper the
compiler calls by itself (`dptofp`, `__floatdisf`), a mangled STL member, a vtable, a base
constructor. The judge ignores relocated words, so the function matches, but the full build
cannot link it ("references unnamed-address symbols"). The original executable already says
where each one is: the instruction at the relocation holds the target.

For every object the last full build compiled (build/full/obj, as build.py leaves it), each
relocation against an unknown symbol is read back from the original's words:
  R_MIPS_26          the jal/j target
  R_MIPS_HI16 + LO16 the %hi/%lo pair (the next LO16 of the same symbol), minus the object's addend
A symbol is written only when every use in every object gives the same address. The result
goes to config/resolved_symbols.txt (`name = 0xADDR; // type:func|data`), which tools/symbols.py
reads like stl_symbols.txt: the names resolve but never name an address or a file.

    resolve_symbols.py [--obj DIR]      report and write config/resolved_symbols.txt
    resolve_symbols.py --dry-run        report only
"""
import argparse
import collections
import glob
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import match  # noqa: E402
import project  # noqa: E402
import symbols  # noqa: E402

ROOT = project.ROOT
OUT = os.path.join(ROOT, "config", "resolved_symbols.txt")
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def sext(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--obj", default=os.path.expanduser("~/.local/share/gt4/full/obj"))
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    text_addr, text = match.load_text()
    end = text_addr + len(text)
    orig = lambda addr: struct.unpack_from("<I", text, addr - text_addr)[0]
    found = collections.defaultdict(set)   # name -> {(address, kind)}
    users = collections.defaultdict(set)
    for path in sorted(glob.glob(os.path.join(a.obj, "func_*.o"))):
        m = re.match(r"func_([0-9A-F]{8})\.o$", os.path.basename(path))
        if not m:
            continue
        faddr = int(m.group(1), 16)
        try:
            blob, relocs, _ = match.read_object(path, want_symbols=True)
        except (OSError, ValueError, struct.error, StopIteration):
            continue
        if not text_addr <= faddr < end or faddr + len(blob) > end:
            continue
        mine = lambda off: struct.unpack_from("<I", blob, off)[0]
        offs = sorted(relocs)
        for n, off in enumerate(offs):
            rtype, name, _value, in_text = relocs[off][:4]
            if not name or name.startswith(".") or in_text or symbols.address_of(name) is not None:
                continue
            at = faddr + off
            if rtype == R_MIPS_26:
                target = ((orig(at) & 0x3FFFFFF) << 2 | (at & 0xF0000000)) - ((mine(off) & 0x3FFFFFF) << 2)
                kind = "func"
            elif rtype == R_MIPS_HI16:
                lo = next((o for o in offs[n + 1:] if relocs[o][0] == R_MIPS_LO16 and relocs[o][1] == name), None)
                if lo is None:
                    continue
                target = (((orig(at) & 0xFFFF) << 16) + sext(orig(faddr + lo))) \
                    - (((mine(off) & 0xFFFF) << 16) + sext(mine(lo)))
                kind = "func" if text_addr <= target < end else "data"
            else:
                continue
            found[name].add((target & 0xFFFFFFFF, kind))
            users[name].add(faddr)

    good, bad = {}, {}
    for name, hits in sorted(found.items()):
        if len({h[0] for h in hits}) == 1:
            good[name] = next(iter(hits))
        else:
            bad[name] = hits
    for name, (addr, kind) in good.items():
        print(f"{name} = 0x{addr:08X} ({kind}; used by {len(users[name])} source(s))")
    for name, hits in bad.items():
        print(f"CONFLICT {name}: " + ", ".join(f"0x{h[0]:08X}" for h in sorted(hits)))
    print(f"{len(good)} resolved, {len(bad)} conflicting")
    if a.dry_run or not good:
        return
    old = {}
    if os.path.exists(OUT):
        for line in open(OUT):
            m = re.match(r"\s*([A-Za-z_$][\w$]*)\s*=", line)
            if m:
                old[m.group(1)] = line.rstrip("\n")
    for name, (addr, kind) in good.items():
        old[name] = f"{name} = 0x{addr:08X}; // type:{kind}"
    with open(OUT, "w", newline="\n") as f:
        f.write("// Addresses of symbols matched sources use, read back from the original's relocated words\n"
                "// (tools/resolve_symbols.py). They resolve but never name an address (tools/symbols.py).\n")
        f.write("".join(old[k] + "\n" for k in sorted(old)))
    print(f"wrote {os.path.relpath(OUT, ROOT)}")


if __name__ == "__main__":
    main()
