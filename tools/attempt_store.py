#!/usr/bin/env python3
"""The attempt store: every judged draft that did not match, kept so a tool can go on from it.

A give-up used to leave a sentence and a count (knowledge/attempts.jsonl); the draft itself
survived only if the worker happened to save it, and most near misses were lost that way.
`swarm.py try` now keeps the source of every draft that does not match, and `swarm.py giveup`
the worker's draft files it never judged. Text and metadata only: no instruction of the game is
stored (the judge's diff is reduced to counts and a class), so the store can leave the machine.

    attempt_store.py status                    attempts, functions, functions with no other draft
    attempt_store.py show ADDR                 the attempts kept for one function, closest first
    attempt_store.py export OUT.tar.gz [--addr ADDR,ADDR]
    attempt_store.py import IN.tar.gz          merge another machine's export (existing files stay)

Layout, under drafts/ at the root (ignored by git; GT4_DRAFTS names another directory):

    drafts/ADDR/ADDR_SHA.c|cpp     the source as it was judged; SHA is the first 16 hex digits of
                                   its sha1 (finish_near.py's digest), so a text is stored once
    drafts/ADDR/log.jsonl          one row per event, appended:
        try     sha, ext, worker, tier, parent (the worker's previous attempt on the function),
                compiler (marker name, null for the project's), command (the compile command),
                nothrow (callees the source declares throw()), verdict, and for a verdict
                "differs": differ / of / original / mine (the judge's counts) and class
        kept    a draft file found at a give-up that was never judged here (origin: its path)
        giveup  worker, tier, attempts, best, note, drafts (the shas the worker left)
        match   sha of the source that matched and its parent: the edit between the two is what
                closed the parent's difference (the source itself is in src/)
        pass    sha, pass (a mechanical step: sweep, context, rewrite, ...), version (of the
                tool), result: what has already run on that text, so a new tool knows what is
                untried

Class of a difference (coarse, from the judge's report):
    length       the draft has another number of instructions than the original
    branch-form  every differing instruction is a branch against its branch-likely form
                 (beq/beql ...): the signature of a missing `throw()` (tools/tu_context.py)
    registers    every differing instruction is the original's with other registers
    order        the differing instructions are the original's own, in another order
    other        anything else

The writer costs file operations only (one small read, one or two writes): nothing is compiled.
"""
import argparse
import hashlib
import io
import json
import os
import re
import sys
import tarfile
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STORE = os.environ.get("GT4_DRAFTS") or os.path.join(ROOT, "drafts")
EXTS = ("c", "cpp")
SOURCE = re.compile(r"^([0-9a-f]{8})_([0-9a-f]{16})\.(c|cpp)$")
MEMBER = re.compile(r"^drafts/([0-9a-f]{8})/(?:\1_[0-9a-f]{16}\.(?:c|cpp)|log\.jsonl)$")
DRAFT_FILE = r"(?:[_.].*)?\.(c|cpp)$"  # after the address: build/swarm/WORKER/ADDR*.c|cpp
HEAD = re.compile(r"(\d+) of (\d+) instructions differ \(original (\d+), mine (\d+)\)")
MARKER = re.compile(r"^/\* compiler: ([\w.+-]+) \*/\s*$")
NOTHROW = re.compile(r"\b([A-Za-z_]\w*)\s*\((?:[^;{}()]|\([^()]*\))*\)\s*(?:const\s*)?throw\s*\(\s*\)\s*;")
REGISTER = re.compile(r"\$\w+")
LIKELY = {"beql", "bnel", "beqzl", "bnezl", "bgezl", "bltzl", "blezl", "bgtzl", "bc1tl", "bc1fl",
          "bc0tl", "bc0fl", "bc2tl", "bc2fl", "bgezall", "bltzall"}


def read(path):
    with open(path, "rb") as f:
        return f.read()


def digest(data):
    """The store's name for a text: the first 16 hex digits of its sha1 (bytes or str)."""
    if isinstance(data, str):
        data = data.encode("utf-8")
    return hashlib.sha1(data).hexdigest()[:16]


def key(addr):
    return addr if isinstance(addr, str) else f"{addr:08x}"


def folder(addr):
    return os.path.join(STORE, key(addr))


def source_path(addr, sha, ext):
    return os.path.join(folder(addr), f"{key(addr)}_{sha}.{ext}")


# ---------------------------------------------------------------- what the judge said

def plain_branch(text):
    """An instruction as (mnemonic, operands, is branch-likely) with a branch in its plain, full
    form: the disassembler writes `beqz $v0, T` but `beql $v0, $zero, T`."""
    mnemonic, _, operands = text.partition(" ")
    likely = mnemonic in LIKELY
    if likely:
        mnemonic = mnemonic[:-2] + "l" if mnemonic.endswith("all") else mnemonic[:-1]
    if mnemonic in ("beqz", "bnez"):
        reg, _, target = operands.partition(", ")
        mnemonic, operands = mnemonic[:3], f"{reg}, $zero, {target}"
    return mnemonic, operands, likely


def diff_pairs(report):
    """[(original, mine)] of the differing lines of a judge report, symbol tags dropped."""
    out = []
    for line in report.splitlines():
        if line.startswith("! ") and " | " in line:
            left, right = line[2:].split(" | ", 1)
            out.append((" ".join(left.split()), " ".join(re.sub(r"\s+<[^<>]*>$", "", right).split())))
    return out


def branch_form_only(pairs):
    """True when every differing line is one branch in its plain form on one side and its
    branch-likely form on the other, operands equal."""
    if not pairs:
        return False
    for left, right in pairs:
        (lm, lo, ll), (rm, ro, rl) = plain_branch(left), plain_branch(right)
        if lm != rm or lo != ro or ll == rl:
            return False
    return True


def classify(report):
    """What a judge report (the output of `match.py check`) says, without its instructions:
    {"verdict": differs | no-compile | refused | link | none | other} and, for differs, the
    counts (differ, of, original, mine) and the class of the difference (module docstring)."""
    if not report:
        return {"verdict": "none"}
    m = HEAD.search(report)
    if not m:
        if "compile failed" in report:
            return {"verdict": "no-compile"}
        if "REFUSED" in report or "REJECTED" in report:
            return {"verdict": "refused"}
        if "DIFFERS AFTER LINKING" in report:
            return {"verdict": "link"}
        return {"verdict": "other"}
    differ, of, original, mine = (int(x) for x in m.groups())
    pairs = diff_pairs(report)
    if original != mine:
        cls = "length"
    elif branch_form_only(pairs):
        cls = "branch-form"
    elif pairs and all(REGISTER.sub("$", a) == REGISTER.sub("$", b) for a, b in pairs):
        cls = "registers"
    elif pairs and sorted(a for a, _ in pairs) == sorted(b for _, b in pairs):
        cls = "order"
    else:
        cls = "other"
    return {"verdict": "differs", "differ": differ, "of": of, "original": original, "mine": mine, "class": cls}


def context(text):
    """What the source says about how it is to be compiled: the compiler its first line names
    (None: the project's), that compiler's command, and the callees it declares `throw()`."""
    m = MARKER.match(text.split("\n", 1)[0])
    name = m.group(1) if m else None
    try:
        import project
        command = project.compiler_command(name)
    except (Exception, SystemExit):
        command = None
    return {"compiler": name, "command": command, "nothrow": sorted(set(NOTHROW.findall(text)))}


# ---------------------------------------------------------------- writing

def rows(addr):
    path = os.path.join(folder(addr), "log.jsonl")
    out = []
    try:
        with open(path, encoding="utf-8") as f:
            for line in f:
                try:
                    out.append(json.loads(line))
                except ValueError:
                    continue
    except OSError:
        pass
    return out


def append(addr, row):
    row = {"time": time.strftime("%Y-%m-%d %H:%M:%S"), "addr": key(addr), **row}
    os.makedirs(folder(addr), exist_ok=True)
    with open(os.path.join(folder(addr), "log.jsonl"), "a", encoding="utf-8") as f:
        f.write(json.dumps(row) + "\n")  # one short line per write: safe with parallel appends
    return row


def keep_text(addr, text, ext):
    """Store the text (once); returns its sha."""
    data = text.encode("utf-8") if isinstance(text, str) else text
    sha = digest(data)
    path = source_path(addr, sha, ext)
    if not os.path.exists(path):
        os.makedirs(folder(addr), exist_ok=True)
        tmp = f"{path}.{os.getpid()}.tmp"
        with open(tmp, "wb") as f:
            f.write(data)
        os.replace(tmp, path)
    return sha


def last_of(worker, earlier):
    """The sha of the worker's latest attempt among the function's rows."""
    for r in reversed(earlier):
        if r.get("event") in ("try", "kept") and r.get("worker") == worker:
            return r.get("sha")
    return None


def put(addr, text, ext, report=None, worker="", tier=None, event="try", origin=None):
    """Keep one draft of the function at addr: its text and a row saying how it was judged
    (report: the output of match.py check; None for a draft nobody judged). Returns the row, or
    None when this very text was the worker's last attempt with the same verdict."""
    ext = ext.lstrip(".")
    if ext not in EXTS:
        raise ValueError(f"not a source extension: {ext}")
    verdict = classify(report) if report is not None else {"verdict": None}
    earlier = rows(addr)
    sha = keep_text(addr, text, ext)
    same = next((r for r in reversed(earlier) if r.get("event") in ("try", "kept") and r.get("worker") == worker), None)
    if same and same.get("sha") == sha and all(same.get(k) == v for k, v in verdict.items()):
        return None
    parent = same.get("sha") if same and same.get("sha") != sha else None
    row = {"event": event, "sha": sha, "ext": ext, "worker": worker, "tier": tier, "parent": parent,
           **context(text if isinstance(text, str) else text.decode("utf-8", "replace")), **verdict}
    if origin:
        row["origin"] = origin
    return append(addr, row)


def giveup(addr, worker, tier, attempts, best, note, draft_dir=None):
    """A give-up: keep the worker's draft files for the function that were never judged here
    (draft_dir/ADDR*.c|cpp) and say which texts it left."""
    known = {r.get("sha") for r in rows(addr)}
    left = []
    if draft_dir and os.path.isdir(draft_dir):
        pattern = re.compile("^" + key(addr) + DRAFT_FILE, re.I)
        for name in sorted(os.listdir(draft_dir)):
            m = pattern.match(name)
            path = os.path.join(draft_dir, name)
            if not m or not os.path.isfile(path):
                continue
            data = read(path)
            sha = digest(data)
            left.append(sha)
            if sha not in known:
                put(addr, data, m.group(1), None, worker, tier, "kept", os.path.relpath(path, ROOT).replace(os.sep, "/"))
    left += [r["sha"] for r in rows(addr) if r.get("event") == "try" and r.get("worker") == worker and r["sha"] not in left]
    return append(addr, {"event": "giveup", "worker": worker, "tier": tier, "attempts": attempts, "best": best,
                         "note": note, "drafts": left})


def matched(addr, text, worker="", tier=None):
    """A match: one row naming the worker's previous attempt, when it has one in the store."""
    earlier = rows(addr)
    if not earlier:
        return None
    return append(addr, {"event": "match", "sha": digest(text), "worker": worker, "tier": tier,
                         "parent": last_of(worker, earlier)})


def mark_pass(addr, sha, name, version, result=None):
    """Record that the mechanical step `name` (at `version` of its tool) ran on the stored text
    sha of addr. A text that is not in the store is ignored; returns the row or None."""
    try:
        if not any(os.path.exists(source_path(addr, sha, ext)) for ext in EXTS):
            return None
        return append(addr, {"event": "pass", "sha": sha, "pass": name, "version": version, "result": result})
    except OSError:
        return None


# ---------------------------------------------------------------- reading

def functions():
    """The addresses (8 hex digits) with a folder in the store."""
    try:
        return sorted(d for d in os.listdir(STORE) if re.fullmatch(r"[0-9a-f]{8}", d))
    except OSError:
        return []


def attempts(addr):
    """{sha: attempt} of the texts kept for addr: path (None if the text is missing), ext, the
    latest judgment (verdict, differ, of, original, mine, class), compiler, command, nothrow,
    worker, tier, parent, time, tries (how often it was judged) and passes {name: latest row}."""
    out = {}
    for r in rows(addr):
        sha = r.get("sha")
        if r.get("event") in ("try", "kept"):
            a = out.setdefault(sha, {"sha": sha, "tries": 0, "passes": {}})
            judged = r["event"] == "try"
            if judged or "verdict" not in a:
                a.update({k: v for k, v in r.items() if k not in ("event", "addr")})
            a["tries"] += judged
        elif r.get("event") == "pass" and sha in out:
            out[sha]["passes"][r.get("pass")] = {k: r.get(k) for k in ("version", "result", "time")}
    for sha, a in out.items():
        path = source_path(addr, sha, a.get("ext", "cpp"))
        a["path"] = path if os.path.exists(path) else None
    return out


def true_length(addr):
    """Instructions of the original function at addr, padding dropped; None without the inventory
    or the executable. (For readers only: it loads the code, which the writer never does.)"""
    try:
        import match
        addr = int(addr, 16) if isinstance(addr, str) else addr
        text_addr, text = match.load_text()
        return len(match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr))))
    except (Exception, SystemExit):
        return None


def differing(attempt, length=None):
    """How far a judged attempt is from the function: the judge's count, plus the instructions the
    draft does not have at all. A draft that returns early is judged over its own span only (the
    judge then takes the rest for another function), so a two-instruction stub reads "2 of 2"."""
    return attempt.get("differ", 1 << 30) + missing(attempt, length)


def missing(attempt, length):
    """Instructions of the original the draft lacks; one is not counted (the function's length is
    read up to the next one, and its last nop may be alignment)."""
    short = (length or 0) - attempt.get("mine", 0)
    return short if short > 1 else 0


def distance(attempt, length=None):
    """Sort key, closest first: judged differences by count, then drafts nobody judged, then the
    ones that did not compile."""
    v = attempt.get("verdict")
    if v == "differs":
        return (0, differing(attempt, length))
    return (1, 0) if v is None else (2, 0)


def drafts(known=None, closest=2):
    """{address: [paths relative to the root]} for finish_near.py's draft discovery: per function
    the `closest` stored attempts by the judge's count, and every kept draft nobody judged.
    known: {address: [paths]} already found elsewhere; a stored text equal to one of those files
    is left out, so nothing is judged twice."""
    out = {}
    for name in functions():
        addr = int(name, 16)
        found = [a for a in attempts(name).values() if a["path"] and a.get("verdict") in ("differs", None)]
        if not found:
            continue
        length = true_length(addr)
        found.sort(key=lambda a: (distance(a, length), a.get("time", "")))
        judged = [a for a in found if a.get("verdict") == "differs"][:closest]
        picked = judged + [a for a in found if a.get("verdict") is None]
        have = set()
        for p in (known or {}).get(addr, ()):
            try:
                have.add(digest(read(os.path.join(ROOT, p))))
            except OSError:
                pass
        paths = [os.path.relpath(a["path"], ROOT) for a in picked if a["sha"] not in have]
        if paths:
            out[addr] = paths
    return out


# ---------------------------------------------------------------- moving between machines

def export(out_path, only=None):
    """Write the store (or the functions in `only`) as a gzipped tar of drafts/ADDR/ files:
    sources and logs, nothing else. Returns (functions, files)."""
    names = [n for n in functions() if only is None or n in only]
    files = 0
    with tarfile.open(out_path, "w:gz") as tar:
        for name in names:
            for f in sorted(os.listdir(folder(name))):
                member = f"drafts/{name}/{f}"
                if MEMBER.match(member):
                    tar.add(os.path.join(folder(name), f), arcname=member, recursive=False)
                    files += 1
    return len(names), files


def import_(in_path):
    """Merge an export into the store: a source is added when missing (and only if its content
    has the sha its name says), log rows are added when not there yet. Members that are not the
    store's own kind of file are refused. Returns (sources added, rows added, members refused)."""
    added = merged = refused = 0
    with tarfile.open(in_path, "r:*") as tar:
        for member in tar:
            m = MEMBER.match(member.name)
            if not m or not member.isfile() or member.size > 4 << 20:
                refused += 1
                continue
            data = tar.extractfile(member).read()
            base = os.path.basename(member.name)
            dest = os.path.join(folder(m.group(1)), base)
            if base == "log.jsonl":
                have = set()
                if os.path.exists(dest):
                    have = {l.strip() for l in read(dest).decode("utf-8", "replace").splitlines()}
                new = []
                for line in data.decode("utf-8", "replace").splitlines():
                    line = line.strip()
                    try:
                        ok = isinstance(json.loads(line), dict)
                    except ValueError:
                        ok = False
                    if ok and line not in have:
                        have.add(line)
                        new.append(line)
                if new:
                    os.makedirs(folder(m.group(1)), exist_ok=True)
                    with open(dest, "a", encoding="utf-8") as f:
                        f.write("".join(l + "\n" for l in new))
                    merged += len(new)
            elif SOURCE.match(base).group(2) != digest(data):
                refused += 1
            elif not os.path.exists(dest):
                os.makedirs(folder(m.group(1)), exist_ok=True)
                tmp = f"{dest}.{os.getpid()}.tmp"
                with open(tmp, "wb") as f:
                    f.write(data)
                os.replace(tmp, dest)
                added += 1
    return added, merged, refused


# ---------------------------------------------------------------- commands

def other_drafts():
    """Addresses (int) with a draft file under build/swarm/*/ (what existed before the store)."""
    out = set()
    swarm_dir = os.path.join(ROOT, "build", "swarm")
    pattern = re.compile(r"^([0-9a-fA-F]{8})" + DRAFT_FILE)
    try:
        workers = [d for d in os.listdir(swarm_dir) if os.path.isdir(os.path.join(swarm_dir, d))]
    except OSError:
        return out
    for w in workers:
        for name in os.listdir(os.path.join(swarm_dir, w)):
            m = pattern.match(name)
            if m:
                out.add(int(m.group(1), 16))
    return out


def summary():
    """Counts over the whole store, for `status` and for measuring what it saves."""
    elsewhere = other_drafts()
    s = {"functions": 0, "texts": 0, "tries": 0, "kept": 0, "giveups": 0, "matches": 0, "passes": 0,
         "bytes": 0, "classes": {}, "verdicts": {}, "functions_without_other_draft": 0,
         "near_without_other_draft": 0}
    for name in functions():
        rs = rows(name)
        found = attempts(name)
        texts = [a for a in found.values() if a["path"]]
        if not texts:
            continue
        s["functions"] += 1
        s["texts"] += len(texts)
        s["bytes"] += sum(os.path.getsize(a["path"]) for a in texts)
        for r in rs:
            e = r.get("event")
            field = {"try": "tries", "kept": "kept", "giveup": "giveups", "match": "matches", "pass": "passes"}.get(e)
            if field:
                s[field] += 1
        for a in texts:
            v = a.get("verdict") or "not judged"
            s["verdicts"][v] = s["verdicts"].get(v, 0) + 1
            if a.get("class"):
                s["classes"][a["class"]] = s["classes"].get(a["class"], 0) + 1
        if int(name, 16) not in elsewhere:
            s["functions_without_other_draft"] += 1
            length = true_length(name)
            if any(a.get("verdict") == "differs" and differing(a, length) <= 5 for a in texts):
                s["near_without_other_draft"] += 1
    return s


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("status")
    p = sub.add_parser("show"); p.add_argument("addr")
    p = sub.add_parser("export"); p.add_argument("out"); p.add_argument("--addr", help="only these functions (comma separated)")
    p = sub.add_parser("import"); p.add_argument("archive")
    a = ap.parse_args()
    if a.cmd == "status":
        s = summary()
        print(f"store: {os.path.relpath(STORE, ROOT)}")
        print(f"{s['texts']} drafts of {s['functions']} functions, {s['bytes']} bytes; rows: {s['tries']} tries, "
              f"{s['kept']} kept at a give-up, {s['giveups']} give-ups, {s['matches']} matches, {s['passes']} passes")
        print("verdicts: " + ", ".join(f"{k}: {v}" for k, v in sorted(s["verdicts"].items())))
        print("classes: " + ", ".join(f"{k}: {v}" for k, v in sorted(s["classes"].items())))
        print(f"functions whose only kept draft is here (none under build/swarm/*/): {s['functions_without_other_draft']}, "
              f"{s['near_without_other_draft']} of them within 5 instructions")
    elif a.cmd == "show":
        name = f"{int(re.sub(r'^(func_|0x)', '', a.addr, flags=re.I), 16):08x}"
        length = true_length(name)
        found = sorted(attempts(name).values(), key=lambda x: (distance(x, length), x.get("time", "")))
        for x in found:
            count = str(x.get("verdict") or "not judged")
            if x.get("verdict") == "differs":
                short = missing(x, length)
                count = f"{x['differ']} of {x['of']} ({x['class']})" + (f" +{short} missing" if short else "")
            print(f"{x['sha']}.{x.get('ext')} {count:34s} {x.get('worker') or '-':10s} {x.get('tier') or '-':7s} "
                  f"{x.get('compiler') or 'default'}; nothrow: {len(x.get('nothrow') or [])}; tries: {x['tries']}; "
                  f"passes: {','.join(sorted(x['passes'])) or '-'}" + ("" if x["path"] else "   (text missing)"))
        for r in rows(name):
            if r.get("event") in ("giveup", "match"):
                print(f"{r['time']} {r['event']} {r.get('worker') or '-'} " +
                      (f"after {r.get('attempts')} tries, best {r.get('best')}: {r.get('note', '')}" if r["event"] == "giveup"
                       else f"{r.get('sha')} (parent {r.get('parent')})"))
        if not found:
            print("nothing kept")
    elif a.cmd == "export":
        only = {f"{int(x, 16):08x}" for x in a.addr.split(",")} if a.addr else None
        n, files = export(a.out, only)
        print(f"{files} files of {n} functions -> {a.out}")
    else:
        added, merged, refused = import_(a.archive)
        print(f"{added} sources and {merged} rows added, {refused} members refused")


if __name__ == "__main__":
    main()
