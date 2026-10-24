#!/usr/bin/env python3
"""Judge every kept near-miss draft of an unmatched function with every compiler profile.

Most closures found by hand in the October 2026 rounds were a change of profile, not of code:
ee-gcc2.96-nsa-g for soft-float libm (nops in jal delay slots), ee-gcc2.9-991111 for the SDK glue
(ring buffers, RPC wrappers, polling loops), ee-gcc2.96-exceptions for libio members, nsa-nosib
for init siblings. A draft is only ever judged under the profile its writer picked, so the
others stay untried. This tries them all, cheaply and without a model; a MATCH is saved through
`swarm.py try`, the rest is reported.

    profile_sweep.py [--addr ADDR,ADDR] [--max-differ 120] [--limit N] [--save]

Report: build/auto/profile_sweep.jsonl (one row per function: best profile and its difference).
"""
import argparse
import glob
import json
import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
OUT = os.path.join(ROOT, "build", "auto", "profile_sweep.jsonl")
MARK = re.compile(r"^\s*/\*\s*compiler:\s*\S+\s*\*/\s*\n")


def profiles():
    names = re.findall(r'^\[compilers\."?([^"\]]+)"?\]', open(os.path.join(ROOT, "project.toml")).read(), re.M)
    # the experimental nosched1 profiles are not allowed (AGENTS.md)
    return [None] + [n for n in names if "nosched1" not in n]


def solved(addr):
    return bool(glob.glob(os.path.join(ROOT, "src", "**", "func_%s.*" % addr.upper()), recursive=True))


def judge(addr, text, ext, profile):
    body = MARK.sub("", text, count=1)
    if profile:
        body = "/* compiler: %s */\n%s" % (profile, body)
    d = tempfile.mkdtemp(dir=os.path.join(ROOT, "build"), prefix="sweep_")
    path = os.path.join(d, "func_%s.%s" % (addr, ext))
    open(path, "w", encoding="utf-8").write(body)
    r = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", addr, path],
                       capture_output=True, text=True, errors="replace", timeout=600)
    out = r.stdout.strip().splitlines()[:1]
    head = out[0] if out else ""
    if ": MATCH" in head:
        return 0, path
    m = re.search(r"(\d+) of (\d+) instructions differ", head)
    return (int(m.group(1)) if m else None), path


def kept(addr):
    """The closest kept drafts of one function: [(differ, file)]."""
    d = os.path.join(ROOT, "drafts", addr)
    best = {}
    log = os.path.join(d, "log.jsonl")
    if os.path.exists(log):
        for line in open(log, encoding="utf-8"):
            row = json.loads(line)
            if row.get("ev") == "try" or "sha" in row:
                if row.get("differ") is not None:
                    best[row["sha"]] = row["differ"]
    files = glob.glob(os.path.join(d, addr + "_*"))
    rows = []
    for f in files:
        sha = os.path.basename(f).split("_")[1].split(".")[0]
        rows.append((best.get(sha, 9999), f))
    return sorted(rows)[:2]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--addr")
    ap.add_argument("--max-differ", type=int, default=120)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--save", action="store_true", help="save a MATCH with swarm.py try")
    a = ap.parse_args()
    addrs = a.addr.split(",") if a.addr else sorted(os.listdir(os.path.join(ROOT, "drafts")))
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    done = 0
    for addr in addrs:
        addr = addr.lower()
        if solved(addr):
            continue
        cands = [c for c in kept(addr) if c[0] <= a.max_differ]
        if not cands:
            continue
        best = None
        for base, f in cands:
            text = open(f, encoding="utf-8", errors="replace").read()
            ext = f.rsplit(".", 1)[1]
            for p in profiles():
                n, path = judge(addr, text, ext, p)
                if n is not None and (best is None or n < best["differ"]):
                    best = {"addr": addr, "profile": p, "differ": n, "base_differ": base, "file": path}
                if n == 0:
                    break
            if best and best["differ"] == 0:
                break
        row = dict(best or {"addr": addr, "differ": None})
        if best and best["differ"] == 0 and a.save:
            r = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "swarm.py"), "try", addr,
                                best["file"], "--worker", "sweep"], capture_output=True, text=True, errors="replace")
            row["saved"] = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else r.stderr[-200:]
        with open(OUT, "a") as o:
            o.write(json.dumps(row) + "\n")
        print(json.dumps(row), flush=True)
        done += 1
        if a.limit and done >= a.limit:
            break


if __name__ == "__main__":
    main()
