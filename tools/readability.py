#!/usr/bin/env python3
"""How readable is src/ for a human? Counts the marks that make a source hard to read, per file,
so readability work can be ranked and its progress published (like tools/clean_report.py does for
m2c leftovers). A mark is a smell, never proof of a bug: the judge decides correctness.

    no comment      no comment at all: nobody says what the function is for
    generic name    the function is still func_ADDR (no RTTI, script or library name known)
    generic fields  struct members called unkNN / fNN / padNN instead of what they hold
    register names  locals named after registers or m2c (a0, v1, s2, temp_xx, var_xx, sp10)
    cast offsets    byte-pointer arithmetic where a struct member would do

    readability.py [--json] [--worst N] [--by-dir]

A file is "readable" when it has none of the marks. --worst lists the files with most marks first
(ties: larger first), which is the order a naming/commenting pass should take them in.
"""
import json
import os
import re
import sys
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src")

COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
GENERIC_FIELD = re.compile(r"\b(?:unk|f|pad|field|off)_?[0-9A-Fa-f]{1,4}\b")
REG_NAME = re.compile(r"\b(?:[avst][0-9]|temp_\w+|var_\w+|sp[0-9A-Fa-f]{1,3}|arg[0-9]+|ret)\b")
CAST_OFFSET = re.compile(r"\(\s*(?:const\s+)?(?:char|s8|u8|unsigned char)\s*\*\s*\)\s*[\w.>()-]+\s*[-+]\s*(?:0x[0-9A-Fa-f]+|\d+)")
STRING = re.compile(r'"(?:[^"\\\n]|\\.)*"')


def strip(src):
    return STRING.sub('""', COMMENT.sub(" ", src))


def marks(path):
    text = open(path, encoding="utf-8", errors="ignore").read()
    code = strip(text)
    found = []
    # a comment that only restates the compiler profile or the address is not an explanation
    prose = [c for c in COMMENT.findall(text)
             if re.search(r"[A-Za-z]{4,}\s+[A-Za-z]{3,}", c) and "compiler:" not in c]
    if not prose:
        found.append("no comment")
    if os.path.basename(path).startswith("func_"):
        found.append("generic name")
    if GENERIC_FIELD.search(code):
        found.append("generic fields")
    if REG_NAME.search(code):
        found.append("register names")
    if CAST_OFFSET.search(code):
        found.append("cast offsets")
    return found, len(text)


def main(argv):
    worst = int(argv[argv.index("--worst") + 1]) if "--worst" in argv else 0
    rows, total = [], Counter()
    by_dir = defaultdict(lambda: [0, 0])
    for root, _, files in os.walk(SRC):
        for f in files:
            if not f.endswith(".cpp"):
                continue
            p = os.path.join(root, f)
            found, size = marks(p)
            rel = os.path.relpath(p, ROOT).replace(os.sep, "/")
            rows.append((rel, found, size))
            for m in found:
                total[m] += 1
            d = "/".join(rel.split("/")[:2])
            by_dir[d][0] += 1
            by_dir[d][1] += not found
    n = len(rows)
    readable = sum(1 for r in rows if not r[1])
    summary = {"sources": n, "readable": readable, "marks": dict(total)}
    if "--json" in argv:
        print(json.dumps(summary))
        return
    print(f"{n} sources; {readable} ({100 * readable / n:.1f}%) have none of the marks")
    for m, c in total.most_common():
        print(f"  {m:16} {c:6} ({100 * c / n:.1f}%)")
    if "--by-dir" in argv:
        for d, (a, b) in sorted(by_dir.items()):
            print(f"  {d:34} {a:6} sources {100 * b / a:5.1f}% readable")
    if worst:
        rows.sort(key=lambda r: (-len(r[1]), -r[2]))
        for rel, found, size in rows[:worst]:
            print(len(found), size, rel, ",".join(found))


if __name__ == "__main__":
    main(sys.argv[1:])
