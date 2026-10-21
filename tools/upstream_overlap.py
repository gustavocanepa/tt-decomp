#!/usr/bin/env python3
"""Which functions are other contributors working on? Read before leasing an area to a worker.

Contributors push branches to their forks long before a PR exists. This lists every fork of the
repository, compares each branch pushed in the last N days with master through the GitHub API
(read only), and collects the function addresses of the sources they add under src/. The result
is the set of addresses to keep workers off, and the units where the contributors are active.

    upstream_overlap.py [--days 7] [--units]    print the contributors' addresses and units
    upstream_overlap.py --check ADDR,ADDR       which of these someone else already has

Writes build/upstream_claims.json ({"addresses": {addr: [repo:branch, ...]}, "units": {...}}).
A name that does not carry an address (RaceBGMPS2__update.cpp) is reported by path only.
"""
import argparse
import collections
import datetime
import json
import os
import re
import subprocess

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "build", "upstream_claims.json")
UPSTREAM = "gustavocanepa/gt4-decomp"
ADDR = re.compile(r"func_([0-9A-Fa-f]{8})\.")
UNIT = re.compile(r"^src/[^/]+/(unit_[0-9A-Fa-f]{8})/")


def gh(path):
    r = subprocess.run(["gh", "api", path, "--paginate"], capture_output=True, text=True)
    if r.returncode:
        return None
    text = r.stdout.strip()
    try:
        return json.loads(text)
    except ValueError:  # --paginate joins pages as consecutive arrays
        return json.loads("[" + text.replace("][", "],[") + "]") if text else None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--days", type=int, default=7)
    ap.add_argument("--check")
    ap.add_argument("--units", action="store_true")
    a = ap.parse_args()
    if a.check:
        claims = json.load(open(OUT))["addresses"]
        for x in a.check.lower().split(","):
            print(x, claims.get(x, "free"))
        return
    since = datetime.datetime.now(datetime.timezone.utc) - datetime.timedelta(days=a.days)
    addresses = collections.defaultdict(list)
    units = collections.Counter()
    unnamed = collections.defaultdict(list)
    forks = gh(f"repos/{UPSTREAM}/forks") or []
    for fork in forks:
        repo = fork["full_name"]
        owner = repo.split("/")[0]
        if datetime.datetime.fromisoformat(fork["pushed_at"].replace("Z", "+00:00")) < since:
            continue
        for br in gh(f"repos/{repo}/branches") or []:
            name = br["name"]
            if name in ("master", "progress"):
                continue
            cmp_ = gh(f"repos/{UPSTREAM}/compare/master...{owner}:{name}")
            if not cmp_ or not cmp_.get("ahead_by"):
                continue
            tag = f"{owner}:{name}"
            for f in cmp_.get("files", []):
                fn = f["filename"]
                if not fn.startswith("src/") or f["status"] == "removed":
                    continue
                m = ADDR.search(fn)
                u = UNIT.match(fn)
                if u:
                    units[(owner, u.group(1))] += 1
                if m:
                    addresses[m.group(1).lower()].append(tag)
                else:
                    unnamed[tag].append(fn)
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    json.dump({"addresses": addresses, "units": {f"{o}/{u}": n for (o, u), n in units.items()},
               "unnamed": unnamed}, open(OUT, "w"), indent=1)
    print(f"{len(addresses)} addresses on {len({t for v in addresses.values() for t in v})} branches -> {OUT}")
    if a.units:
        for (o, u), n in sorted(units.items(), key=lambda x: -x[1]):
            print(f"  {o:12} {u} {n} sources")


if __name__ == "__main__":
    main()
