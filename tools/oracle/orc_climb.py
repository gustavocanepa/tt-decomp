"""oracle.py climb: search for the source edit that makes the compiler take the named decisions
by itself, scored by the decisions and not by the judge's row count.

What the earlier search (`aim --rounds`) did, and what this one does differently
    aim judged up to 40 variants a draft, sampled at the sites the report names, and measured
    the decision distance (a whole report under gdb, 5 s) of the 6 variants with the fewest
    differing rows; a variant that fixed the named decision and broke something else, or that
    fixed one of two decisions, looked like any other failure. Here
      1. every variant gets a verdict per named decision from ONE plain compile (cc1 + as in the
         draft's own work directory, no gdb, no judge call): the base draft's decisions are
         tied once to the rows of the original they change (the instruction whose register
         field must become the original's; the two instructions a scheduler pick exchanges;
         the branch and slot rows of a delay-slot decision), and a variant's listing is read
         against the same rows. So the search sees which edit MOVES which decision, also when
         the function does not match yet, and what the edit broke (rows that were right);
      2. the rest of a variant's distance is counted in decision units read from the listing
         (registers that sit elsewhere, instructions out of order, branch forms, instructions
         with no counterpart), not in rows: one misplaced register is one unit whether it
         shows in 2 rows or in 20;
      3. the best few by that score are certified by the oracle (report under gdb), and the
         search goes on from the certified one with the fewest decisions, with its own named
         decisions and sites: edits compose (one edit per decision, or one that moves a
         decision and one that repairs what it broke);
      4. all rules at all sites are in reach: the sites the report names go first, the others
         follow up to the cap, so an edit away from the named line is not lost.
    The same variants, compiled the same number of times, searched blindly (random order,
    climbing by the judge's row count) are the baseline: `--blind` runs both from every draft.

A scored compile costs what the compiler costs: about 0.02 s (cc1plus, as, read the object;
7 ms of wall time each at 3 jobs), against 0.13 s for a compile under gdb and 3 to 8 s for a
report.

Two searches. `--stepwise` (the first measurement): one draft at a time, the best two variants
by the score certified by the oracle, on from the certified one with the fewest decisions. The
default (the second): a beam. The decisions are tied to rows of the ORIGINAL, so the first
draft's signature reads every descendant's listing and no certificate is needed on the way; the
beam keeps the variants with the fewest units, the ones that took a named decision the
original's way whatever they broke (`--movers`), and with `--rows` the ones the judge's row
count likes; the oracle certifies the best descendant at the end.

Measured 2026-10-12 on retry_brief's queue (certified, or within 3 instructions), every arm
with the same variants and the same number of compiles, the blind arm climbing by rows:
    c1  stepwise, 137 drafts (83 certified), 3 steps of 300: scored 15 matches (9 at the first
        step, 5 at the second, 1 at the third), blind the same 15; 16,732 + 1,170 compiles
        against 16,345. 14 saved (one is defined in another function's file already).
    c2  beam 2 + 2 movers, the 117 drafts left: scored 2 new (00472de8, 00562a70), blind 3
        (00472de8, 0048fed0, 001ccb10), 61,055 against 60,644 compiles; 4 saved.
    c3  beam 2 + 2 movers + 3 by rows, the 109 left: 1 more (003784b8, three edits).
    The score does not find more matches than the judge's row count at equal compiles: at the
    first step both see the same variants, and deeper each ranking reaches a match the other
    misses. What the score adds is the verdict per decision: a named decision was moved by
    some edit in 61 of 137 drafts, without breaking a row that was right in 23 (9 of those
    matched at once); the list per function (`movers`) is what a retry starts from. 23
    functions ended nearer and are kept as closer drafts: 9 certified with fewer decisions, 14
    uncertified with fewer units. 43 of the 294 named decisions do not show in the draft's own
    listing (the steered compile changes the pick, the output is the same): they are marked and
    never counted as moved.

    oracle.py climb [-j3] [--steps 3] [--cap 160] [--beam 2] [--movers 2] [--rows 0] [--stepwise]
                    [--blind] [--only ADDR,..] [--include-matched] [--within 3] [--limit N]
                    [--tag T] [--dry] [--seconds 900]
        every function of retry_brief's queue (certified, or within a few instructions): its
        closest draft is searched. A variant whose plain compile equals the original is judged
        by match.py, and a MATCH is saved through finish_near.save() (swarm.py try judges it a
        third time) unless rewrite_rules.review() flags its source (then it is listed as held).
        A certified variant with fewer decisions than the draft is kept as
        build/oracle/climb/TAG/ADDR/best.EXT with its oracle report, so the retry queue offers
        it as the function's closest draft after the next `retry_brief.py index`.
    oracle.py movers ADDR[,ADDR] [--tag T]
        for the functions given: the named decisions of the draft, and per rule the edits that
        moved each one (and what they broke), from the last climb.

Files under build/oracle/climb/TAG/: results.jsonl (one row per draft: arms.scored / arms.blind
with steps, compiles, match; decisions; movers), summary.json, ADDR/ (variants kept: the matches,
the certified bases).

Nothing here is a match but what match.py says MATCH on plain compiler output.
"""
import bisect
import collections
import json
import os
import random
import shutil
import signal
import sys
import time

import orc_core as C
import orc_rewrite as W
import orc_rtl as R
import match
import project
import rewrite_rules as RR

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "oracle")
CLIMB = os.path.join(OUT, "climb")


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def total(row):
    """Decisions that separate a certified draft from the original, None when not certified."""
    if not row:
        return None
    if row.get("kind") == "match":
        return 0
    if row.get("certified") and row.get("distance") is not None:
        return row["distance"]
    c = row.get("combined") or {}
    return c.get("total") if c.get("certified") else None


# ---------------------------------------------------------------- a listing against the original

def _key(w):
    """Skeleton of a word with a stack slot's offset left out (the frame follows from the
    registers saved): orc_rtl.unmatched's key."""
    op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
    if rs == 29 and (op >= 0x20 or op in (0x1A, 0x1B) or (op in (9, 0x19) and rt == 29)):
        w &= 0xFFFF0000
    return R.skeleton(w)


def pairing(mine, target):
    """{my index: original index}: instructions equal up to branch form, the k-th with the k-th,
    then among the rest those equal up to their registers. Order plays no part."""
    out, where, taken, rest = {}, collections.defaultdict(list), set(), []
    for j, w in enumerate(target):
        where[R.canon(w)].append(j)
    for i, w in enumerate(mine):
        js = where.get(R.canon(w))
        if js:
            out[i] = js.pop(0)
            taken.add(out[i])
        else:
            rest.append(i)
    loose = collections.defaultdict(list)
    for j, w in enumerate(target):
        if j not in taken:
            loose[_key(w)].append(j)
    for i in rest:
        js = loose.get(_key(mine[i]))
        if js:
            out[i] = js.pop(0)
    return out


def _lis(seq):
    """Length of the longest increasing subsequence."""
    tails = []
    for x in seq:
        k = bisect.bisect_left(tails, x)
        if k == len(tails):
            tails.append(x)
        else:
            tails[k] = x
    return len(tails)


def measure(mine, target):
    """A listing against the original, in the units the search climbs on:
    rows      the judge's count: rows that differ, position by position
    bad       those rows (indices into the original)
    content   instructions one side has and the other has not, whatever registers and order
    regs      distinct (my register, the original's) pairs among paired instructions
    order     paired instructions that would have to move to stand in the original's order
    form      branches in the other form (likely against plain)
    units     regs + order + form + 2 * content
    inv       {original index: my index}"""
    width = max(len(mine), len(target))
    bad = {j for j in range(width) if j >= len(mine) or j >= len(target) or mine[j] != target[j]}
    pair = pairing(mine, target)
    only_mine, only_orig = R.unmatched(mine, target)
    regs, form = set(), 0
    for i, j in pair.items():
        a, b = mine[i], target[j]
        if R.canon(a) != R.canon(b):
            (_, fa), (_, fb) = R.fields(a), R.fields(b)
            if fa.keys() == fb.keys():
                regs.update((fa[f], fb[f]) for f in fa if fa[f] != fb[f])
        elif R.is_likely(a) != R.is_likely(b):
            form += 1
    seq = [pair[i] for i in sorted(pair)]
    order = len(seq) - _lis(seq)
    content = len(only_mine) + len(only_orig)
    return {"rows": len(bad), "bad": bad, "content": content, "regs": len(regs), "order": order, "form": form,
            "units": len(regs) + order + form + 2 * content, "inv": {j: i for i, j in pair.items()}}


# ---------------------------------------------------------------- the named decisions as rows

def signature(s, row):
    """The decisions of a certified draft's report, each tied to the rows of the original it
    changes, so that any other listing can be asked whether it takes the decision the original's
    way. `s`: a Session on the draft after natural(). Returns a list of dicts:
        allocation  pseudo, var, from, to, rows [[original row, register field]]
        sched       want_row, got_row (the instruction the original issues first, and the one
                    this compile issues first), line, picked_line, decided_by
        reorg       kind, rows (the branch and its slot)"""
    if not row or total(row) is None:
        return []
    mine = list(s.lst.linked)
    target = s.padded(len(mine))
    pair = pairing(mine, target)
    at = {}
    for i, (_, _, uid) in enumerate(s.lst.words):
        if uid is not None and uid not in at:
            at[uid] = i
    passes = row.get("passes") or {}
    alloc = passes.get("allocation") or {}
    force = row["reload"]["force"] if row.get("certified") else alloc.get("force") or {}
    named = {d.get("pseudo"): d for d in (row.get("causal") or {}).get("decisions", []) + (alloc.get("causal") or {}).get("decisions", [])}
    out = []
    for p, (src, dst) in sorted(force.items(), key=lambda kv: int(kv[0])):
        p = int(p)
        rows, any_rows = [], []
        for i, j in sorted(pair.items()):
            (ka, fa), (kb, fb) = R.fields(mine[i]), R.fields(target[j])
            if ka != kb or fa.keys() != fb.keys():
                continue
            for f in fa:
                if fa[f] == src and fb[f] == dst:
                    ins = s.by_uid.get(s.lst.words[i][2])
                    any_rows.append([j, f])
                    if ins is None or p in (ins.sets | ins.uses):
                        rows.append([j, f])
        d = named.get(p, {})
        out.append({"pass": "allocation", "pseudo": p, "var": d.get("var"), "line": d.get("line"), "from": R.regname(src),
                    "to": R.regname(dst), "rows": rows or any_rows})
    for pick in (passes.get("sched") or {}).get("picks", []):
        iu, iv = at.get(pick.get("forced")), at.get(pick.get("picked"))
        ju, jv = pair.get(iu), pair.get(iv)
        e = {"pass": "sched", "line": pick.get("line"), "picked_line": pick.get("picked_line"),
             "decided_by": (pick.get("rank") or {}).get("decided_by"), "want_row": ju, "got_row": jv}
        if ju is None or jv is None or (iu < iv) == (ju < jv):
            # not visible as these two exchanged: the rows the pick's instruction must stand on
            e.update(want_row=None, got_row=None, rows=[j for j in (ju, jv) if j is not None])
        out.append(e)
    for e in (passes.get("reorg") or {}).get("decisions", []):
        rows = []
        for uid in [e.get("branch")] + list(e.get("branches") or []):
            j = pair.get(at.get(uid))
            if j is not None:
                rows += [j, j + 1]
        out.append({"pass": "reorg", "kind": e.get("decision"), "line": e.get("line"), "rows": sorted(set(rows))})
    return out


def taken(d, mine, target, m):
    """Does this listing take decision d the original's way? True, False, or None when the
    decision cannot be read off it (the rows are not there)."""
    inv = m["inv"]
    if d["pass"] == "allocation":
        if not d["rows"]:
            return None
        for j, f in d["rows"]:
            i = inv.get(j)
            if i is None or j >= len(target) or R.fields(mine[i])[1].get(f) != R.fields(target[j])[1].get(f):
                return False
        return True
    if d["pass"] == "sched" and d.get("want_row") is not None:
        iu, iv = inv.get(d["want_row"]), inv.get(d["got_row"])
        if iu is None or iv is None:
            return False
        return R.canon(mine[iu]) == R.canon(target[d["want_row"]]) and R.canon(mine[iv]) == R.canon(target[d["got_row"]]) \
            and (iu < iv) == (d["want_row"] < d["got_row"])
    rows = d.get("rows") or []
    if not rows:
        return None
    return all(j not in m["bad"] for j in rows)


def describe(d):
    if d["pass"] == "allocation":
        return f"allocation: {('`' + d['var'] + '`') if d.get('var') else 'pseudo ' + str(d['pseudo'])} in {d['to']}, not {d['from']}"
    if d["pass"] == "sched":
        return (f"scheduler: the insn of line {d.get('line') or '?'} before the one of line {d.get('picked_line') or '?'}"
                + (f" (decided by {d['decided_by']})" if d.get("decided_by") else ""))
    return f"delay slot: {d.get('kind')}" + (f" at line {d['line']}" if d.get("line") else "")


# ---------------------------------------------------------------- plain compiles of variants

class Quick:
    """One draft and its variants in one work directory: the compiler proper and the assembler,
    nothing else. The words are compared here; only match.py says MATCH."""

    def __init__(self, addr, path):
        self.s = C.Session(addr, path)
        self.n = 0
        self.plain = 0

    def close(self):
        self.s.close()

    def base(self):
        self.s.natural()
        self.plain += 2
        return list(self.s.lst.linked)

    def target(self, n):
        return self.s.padded(n)

    def words(self, text):
        """The variant's instructions as linked words, None when it does not compile."""
        s = self.s
        tag = f"q{self.n}"
        self.n += 1
        self.plain += 1
        name = tag + s.ext
        with open(os.path.join(s.work, name), "w", encoding="utf-8", newline="\n") as f:
            f.write(text)
        argv = list(s.argv)
        dump = argv.index("-dumpbase")
        for i, x in enumerate(argv):
            if x == s.base and i != dump + 1:
                argv[i] = name
        argv[dump + 1] = name
        argv[-1] = tag + ".s"
        try:
            r = C.sh(argv, s.work, env=s.env, timeout=60)
            out_s = os.path.join(s.work, tag + ".s")
            if r.returncode != 0 or not os.path.exists(out_s) or os.path.getsize(out_s) == 0:
                return None
            return list(s.assemble(tag).linked)
        except (C.OracleError, SystemExit, OSError, ValueError, IndexError):
            return None
        finally:
            for ext in (s.ext, ".s", ".o", ".lst"):
                try:
                    os.remove(os.path.join(s.work, tag + ext))
                except OSError:
                    pass


FIRST = ("callee_return", "falls_off_end")
HELD = ("mined barrier_last", "mined falls_off_end")    # compiled though review() may flag the result: a MATCH is held back


def flagged(new, text):
    return bool(set(RR.review(new)) - set(RR.review(text)))


def _turns(vs):
    """Variants reordered so that every kind of rewrite gets its turn."""
    by = collections.OrderedDict()
    for v in vs:
        by.setdefault(v[0], []).append(v)
    out, queues = [], list(by.values())
    while any(queues):
        for q in queues:
            if q:
                out.append(q.pop(0))
    return out


def generate(text, aim, cap, seed, cplusplus, seen, lead=False):
    """[(rule, site, new text, aimed)]: the single-step variants of a draft from both tables. With
    an aim (orc_aim.sites of the report) the variants at the named sites come first, each rule in
    turn, then the others in a seeded random order; without one, all in that random order.
    lead: the two prototype-level toggles before everything else (the scored search)."""
    def both(aim):
        try:
            a = W.variants(text, aim=aim, cplusplus=cplusplus)
        except Exception:
            a = []
        return a + [("mined " + k, site, new) for k, site, new in RR.variants(text, aim=aim, cplusplus=cplusplus)]

    # the two prototype-level toggles (a callee's return, the function's own): no body edit, few
    # variants, the cause of most scheduler picks around calls and in the last block. Always first.
    toggles = [("mined " + k, site, new) for k, site, new in RR.variants(text, cplusplus=cplusplus, rules=FIRST)]
    every = both(None)
    random.Random(seed).shuffle(every)
    every = _turns(every)
    first = _turns(both(aim)) if aim else []
    out, texts = [], set()
    for aimed, vs in ((True, toggles if lead else []), (True, first), (False, every)):
        for rule, site, new in vs:
            if new in texts or new in seen or (flagged(new, text) and rule not in HELD):
                continue
            texts.add(new)
            out.append((rule, site, new, aimed))
    if aim and cap:
        # the named sites take at most two thirds of the budget: an edit elsewhere must stay in reach
        head = [v for v in out if v[3]][:max(1, 2 * cap // 3)]
        tail = [v for v in out if not v[3]]
        out = head + tail
    return out[:cap] if cap else out


def keep(tag, addr, name, ext, text):
    d = os.path.join(CLIMB, tag, f"{addr:08x}")
    os.makedirs(d, exist_ok=True)
    path = os.path.join(d, name + ext)
    with open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    return path


def really_matches(addr, path):
    try:
        return match.judge(addr, path)[0]
    except (SystemExit, Exception):
        return False


DEADLINE = [None]       # of the draft being searched in this process: oracle.measure_one sets its own alarm


def certify(addr, path, seconds):
    """The oracle's report on one variant (cached per content under build/oracle/). The report
    arms and clears the process alarm itself, so the draft's own time limit is armed again."""
    import oracle
    left = None if DEADLINE[0] is None else DEADLINE[0] - time.time()
    if left is not None and left < 5:
        raise Timeout()
    try:
        return oracle.measure_one((addr, path, int(min(seconds, left or seconds)), False))
    finally:
        if DEADLINE[0] is not None:
            signal.signal(signal.SIGALRM, _alarm)
            signal.alarm(max(1, int(DEADLINE[0] - time.time())))


def lean(m):
    return {k: m[k] for k in ("rows", "content", "regs", "order", "form", "units")}


def search(addr, path, row, a, arm, budget=None):
    """One search from one draft. arm `scored`: variants ranked by the decisions they move and
    the units they leave, the best certified by the oracle, the search goes on from the
    certified one with the fewest decisions. arm `blind`: the same variants in random order,
    going on from the one with the fewest differing rows, until `budget` compiles are spent."""
    import orc_aim
    ext = os.path.splitext(path)[1]
    text = open(path, encoding="utf-8", errors="replace").read()
    res = {"arm": arm, "steps": [], "match": None, "plain": 0, "gdb": 0, "start": None, "end": None, "movers": []}
    seen, stay, cur_total = {text}, 0, total(row)
    seed = addr & 0xFFFF
    step = 0
    while step < (a.steps if arm == "scored" else 50):
        left = None if budget is None else budget - res["plain"] - res["gdb"]
        if left is not None and left <= 2:
            break
        q = Quick(addr, path)
        try:
            base_words = q.base()
            target = q.target(len(base_words))
            b = measure(base_words, target)
            sig = signature(q.s, row) if arm == "scored" else []
            # a decision the draft's own listing already shows the original's way is not one an
            # edit can be seen to move: the steered compile changed that pick, the output did not
            shown = [taken(d, base_words, target, b) is False for d in sig]
            entry = {"step": step, "draft": os.path.relpath(path, ROOT), "decisions": cur_total, "base": lean(b),
                     "named": [describe(d) + ("" if on else "  [not visible in the listing]") for d, on in zip(sig, shown)],
                     "visible": shown}
            if res["start"] is None:
                res["start"] = dict(lean(b), decisions=cur_total)
            if b["rows"] == 0:
                entry["as_is"] = True
                res["steps"].append(entry)
                if really_matches(addr, path):
                    res["match"] = {"path": os.path.relpath(path, ROOT), "rule": "as is", "site": "", "step": step}
                break
            aim = orc_aim.sites(row) if arm == "scored" and row and total(row) is not None else None
            vs = generate(text, aim, a.cap, seed + step, ext == ".cpp", seen, lead=arm == "scored")
            if left is not None:
                vs = vs[:max(0, left - 2)]
            scored = []
            for rule, site, new, aimed in vs:
                w = q.words(new)
                if w is None:
                    continue
                m = measure(w, q.target(len(w)))
                flags = [taken(d, w, q.target(len(w)), m) if on else None for d, on in zip(sig, shown)]
                scored.append({"rule": rule, "site": site, "aimed": aimed, "text": new, "m": m, "moved": flags,
                               "n_moved": sum(1 for f in flags if f), "fixed": len(b["bad"] - m["bad"]),
                               "broke": len(m["bad"] - b["bad"])})
            res["plain"] += q.plain
        finally:
            q.close()
        entry.update(variants=len(vs), compiled=len(scored), aimed=sum(1 for v in vs if v[3]),
                     by_rule=dict(collections.Counter(v[0] for v in vs)))
        res["steps"].append(entry)
        # what moved a named decision (kept for the report, whether or not the search goes that way)
        for v in scored:
            if v["n_moved"]:
                res["movers"].append({"step": step, "rule": v["rule"], "site": v["site"], "moved": v["moved"],
                                      "broke": v["broke"], "after": lean(v["m"])})
        # a variant equal to the original: the judge decides
        hit = None
        for v in scored:
            if v["m"]["rows"] == 0:
                p = keep(a.tag, addr, f"{arm}_match_s{step}", ext, v["text"])
                if really_matches(addr, p):
                    hit = v
                    res["match"] = {"path": os.path.relpath(p, ROOT), "rule": v["rule"], "site": v["site"], "step": step,
                                    "aimed": v["aimed"], "review": RR.review(v["text"])}
                    break
        if hit:
            entry["matched_by"] = hit["rule"]
            break
        if arm == "blind":
            better = [v for v in scored if v["m"]["rows"] < b["rows"]]
            if not better:
                # nothing closer by rows: the next variants of the same draft, while the budget lasts
                seen.update(v[2] for v in vs)
                if not vs:
                    break
                step += 1
                continue
            nxt = min(better, key=lambda v: v["m"]["rows"])
            path = keep(a.tag, addr, f"blind_s{step}", ext, nxt["text"])
            entry["to"] = {"rule": nxt["rule"], "site": nxt["site"], "rows": nxt["m"]["rows"]}
        else:
            key = lambda v: (v["m"]["content"], v["m"]["units"], -v["n_moved"], v["m"]["rows"])
            cands = [v for v in scored if v["m"]["content"] <= b["content"] and
                     ((v["m"]["content"], v["m"]["units"]) < (b["content"], b["units"]) or
                      (v["m"]["units"] == b["units"] and (v["n_moved"] or v["m"]["rows"] < b["rows"])))]
            cands.sort(key=key)
            entry["candidates"] = len(cands)
            best, files = None, []
            for k, v in enumerate(cands[:a.beam]):
                p = keep(a.tag, addr, f"s{step}_c{k}", ext, v["text"])
                files.append(p)
                r = certify(addr, p, a.report_seconds)
                res["gdb"] += r.get("gdb_runs", 0) or 0
                t = total(r)
                rank = (0, t, v["m"]["units"]) if t is not None else (1, v["m"]["content"], v["m"]["units"])
                if best is None or rank < best[0]:
                    best = (rank, v, p, r, t)
            if best is None:
                break
            rank, v, p, r, t = best
            for other in files:         # a variant the search does not go on from is not a kept draft
                if other != p:
                    os.remove(other)
            if t is not None and cur_total is not None:
                go = t < cur_total or (t == cur_total and stay < 1 and (v["n_moved"] or v["m"]["units"] < b["units"]))
                stay = stay + 1 if t == cur_total else 0
            elif t is not None:
                go = True               # the draft was not certified, this one is
            else:
                go = cur_total is None and (v["m"]["content"], v["m"]["units"]) < (b["content"], b["units"])
            entry["to"] = {"rule": v["rule"], "site": v["site"], "decisions": t, "units": v["m"]["units"],
                           "moved": v["moved"], "broke": v["broke"], "taken": bool(go),
                           "draft": os.path.relpath(p, ROOT)}
            if not go:
                os.remove(p)
                break
            path, row, cur_total = p, r, t
        text = open(path, encoding="utf-8").read()
        seen.add(text)
        step += 1
    last = res["steps"][-1] if res["steps"] else {}
    res["end"] = dict(last.get("base") or {}, decisions=cur_total, draft=os.path.relpath(path, ROOT))
    if arm == "scored" and last.get("to", {}).get("taken"):
        # the last step taken was never a base: its own numbers
        res["end"].update(decisions=last["to"]["decisions"], units=last["to"]["units"])
    elif arm == "blind" and last.get("to"):
        res["end"]["rows"] = last["to"]["rows"]
    return res


def beam_search(addr, path, row, a, arm, budget=None):
    """The search of the second measurement. The named decisions are tied to rows of the
    original, so the draft's signature reads any descendant's listing: no certificate is needed
    on the way. From every draft of the beam all variants are compiled; the next beam is, for
    `scored`, the a.beam variants that leave the fewest units plus the a.movers variants that
    took the most named decisions the original's way whatever they broke (a second edit may
    repair it); for `blind`, the a.beam + a.movers variants with the fewest differing rows. The
    oracle certifies the best descendant at the end only."""
    import orc_aim
    ext = os.path.splitext(path)[1]
    text0 = open(path, encoding="utf-8", errors="replace").read()
    res = {"arm": arm, "steps": [], "match": None, "plain": 0, "gdb": 0, "start": None, "end": None, "movers": [], "chain": []}
    root_total = total(row)
    seed = addr & 0xFFFF
    q = Quick(addr, path)
    try:
        base_words = q.base()
        target = q.target(len(base_words))
        b = measure(base_words, target)
        sig = signature(q.s, row) if arm == "scored" else []
        shown = [taken(d, base_words, target, b) is False for d in sig]
        res["start"] = dict(lean(b), decisions=root_total)
        res["named"] = [describe(d) + ("" if on else "  [not visible in the listing]") for d, on in zip(sig, shown)]
        res["visible"] = shown
        res["end"] = dict(lean(b), decisions=root_total, draft=os.path.relpath(path, ROOT))
        if b["rows"] == 0:
            if really_matches(addr, path):
                res["match"] = {"path": os.path.relpath(path, ROOT), "rule": "as is", "site": "", "step": 0, "chain": []}
            return res
        aim = orc_aim.sites(row) if arm == "scored" and root_total is not None else None
        beam = [{"text": text0, "m": b, "chain": [], "n_moved": 0}]
        seen = {text0}
        best = None
        rank = (lambda v: (v["m"]["content"], v["m"]["units"], v["m"]["rows"])) if arm == "scored" else (lambda v: (v["m"]["rows"],))
        for depth in range(a.steps):
            pool, tried = [], 0
            for st in beam:
                vs = generate(st["text"], aim, a.cap, seed + depth, ext == ".cpp", seen, lead=arm == "scored")
                for rule, site, new, aimed in vs:
                    if budget is not None and q.plain >= budget:
                        break
                    seen.add(new)
                    tried += 1
                    w = q.words(new)
                    if w is None:
                        continue
                    tw = q.target(len(w))
                    m = measure(w, tw)
                    flags = [taken(d, w, tw, m) if on else None for d, on in zip(sig, shown)]
                    v = {"text": new, "m": m, "chain": st["chain"] + [[rule, site]], "moved": flags,
                         "n_moved": sum(1 for f in flags if f), "broke": len(m["bad"] - b["bad"]),
                         "odd": flagged(new, text0)}
                    if depth == 0 and v["n_moved"]:
                        res["movers"].append({"step": 0, "rule": rule, "site": site, "moved": flags, "broke": v["broke"],
                                              "after": lean(m)})
                    if m["rows"] == 0:
                        p = keep(a.tag, addr, f"{arm}_match_d{depth}", ext, new)
                        if really_matches(addr, p):
                            res["match"] = {"path": os.path.relpath(p, ROOT), "rule": rule, "site": site, "step": depth,
                                            "chain": v["chain"], "aimed": aimed, "review": RR.review(new)}
                            res["steps"].append({"step": depth, "bases": len(beam), "variants": tried, "matched_by": rule})
                            return res
                        continue
                    pool.append(v)
            sound = [v for v in pool if not v["odd"]]
            if not sound:
                res["steps"].append({"step": depth, "bases": len(beam), "variants": tried})
                break
            sound.sort(key=rank)
            if best is None or rank(sound[0]) < rank(best):
                best = sound[0]
            if arm == "scored":
                head = sound[:a.beam]
                movers = sorted((v for v in sound[a.beam:] if v["n_moved"]),
                                key=lambda v: (-v["n_moved"], v["m"]["content"], v["m"]["units"], v["m"]["rows"]))[:a.movers]
                beam = head + movers
                # and the ones the judge's row count likes: in the second measurement each ranking
                # reached a match the other did not, and a compile costs nothing
                by_rows = sorted((v for v in sound if all(v is not x for x in beam)), key=lambda v: v["m"]["rows"])
                beam += by_rows[:a.rows]
            else:
                beam = sound[:a.beam + a.movers + a.rows]
            res["steps"].append({"step": depth, "bases": len(beam), "variants": tried, "best": lean(sound[0]["m"]),
                                 "movers": sum(1 for v in pool if v["n_moved"])})
            if budget is not None and q.plain >= budget:
                break
    finally:
        res["plain"] = q.plain
        q.close()
    if best is not None and rank(best) < rank({"m": b}):
        res["chain"] = best["chain"]
        p = keep(a.tag, addr, f"{arm}_best", ext, best["text"])
        res["end"] = dict(lean(best["m"]), decisions=None, draft=os.path.relpath(p, ROOT))
        if arm == "scored":
            r = certify(addr, p, a.report_seconds)
            res["gdb"] += r.get("gdb_runs", 0) or 0
            res["end"]["decisions"] = total(r)
            if root_total is not None and (total(r) is None or total(r) >= root_total):
                os.remove(p)        # not nearer by the oracle's count: not a draft to keep
                res["end"]["kept"] = False
    return res


class Timeout(Exception):
    pass


def _alarm(*_):
    raise Timeout()


def climb_one(item):
    addr, path, row, a = item
    out = {"addr": f"{addr:08x}", "draft": os.path.relpath(path, ROOT), "decisions": total(row), "arms": {}}
    started = time.time()
    for arm in ("scored", "blind") if a.blind else ("scored",):
        signal.signal(signal.SIGALRM, _alarm)
        signal.alarm(a.seconds)
        DEADLINE[0] = time.time() + a.seconds
        try:
            budget = None
            if arm == "blind":
                budget = out["arms"]["scored"]["plain"] + out["arms"]["scored"]["gdb"]
            out["arms"][arm] = (search if a.stepwise else beam_search)(addr, path, row, a, arm, budget)
        except Timeout:
            out["arms"][arm] = {"arm": arm, "error": f"over {a.seconds}s", "steps": [], "match": None, "plain": 0, "gdb": 0, "movers": []}
        except Exception as e:      # one bad draft must not stop the run
            out["arms"][arm] = {"arm": arm, "error": f"{type(e).__name__}: {e}"[:300], "steps": [], "match": None, "plain": 0,
                                "gdb": 0, "movers": []}
        finally:
            signal.alarm(0)
            DEADLINE[0] = None
    out["seconds"] = round(time.time() - started, 1)
    return out


# ---------------------------------------------------------------- the run

def closer(res):
    """Did the scored search end nearer than it began: fewer decisions (both certified), or a
    certificate where there was none, or fewer units when neither is certified."""
    s, e = res.get("start"), res.get("end")
    if not s or not e or res.get("match"):
        return False
    if e.get("kept") is False:
        return False
    if s.get("decisions") is not None and e.get("decisions") is not None:
        return e["decisions"] < s["decisions"]
    if s.get("decisions") is not None:
        return False            # it was certified, the descendant is not
    if s.get("decisions") is None and e.get("decisions") is not None:
        return True
    return s.get("decisions") is None and e.get("units", 99) < s.get("units", 99)


def closer_blind(res):
    s, e = res.get("start"), res.get("end")
    return bool(s and e and not res.get("match") and e.get("rows", 999) < s.get("rows", 999))


def taken_rules(res):
    """The rules of the steps a search took (and of the match)."""
    if res.get("match") and res["match"].get("chain"):
        return [rule for rule, _ in res["match"]["chain"]]
    if res.get("chain"):
        return [rule for rule, _ in res["chain"]]
    out = [st["to"]["rule"] for st in res.get("steps", []) if st.get("to") and st["to"].get("taken", True)]
    if res.get("match") and res["match"]["rule"] != "as is":
        out.append(res["match"]["rule"])
    return out


def summarise(rows, a):
    s = {"tag": a.tag, "drafts": len(rows), "steps": a.steps, "cap": a.cap, "beam": a.beam, "arms": {}}
    for arm in ("scored", "blind"):
        mine = [(r["addr"], r["arms"][arm]) for r in rows if arm in r["arms"]]
        if not mine:
            continue
        near = closer if arm == "scored" else closer_blind
        per = collections.defaultdict(lambda: {"match": [], "closer": []})
        for addr, res in mine:
            if res.get("match") and res["match"]["rule"] != "as is":
                for rule in dict.fromkeys(taken_rules(res)):
                    per[rule]["match"].append(addr)
            elif near(res):
                for rule in dict.fromkeys(taken_rules(res)):
                    per[rule]["closer"].append(addr)
        s["arms"][arm] = {
            "matched": sorted(addr for addr, res in mine if res.get("match") and res["match"]["rule"] != "as is"),
            "as_is": sorted(addr for addr, res in mine if res.get("match") and res["match"]["rule"] == "as is"),
            "closer": sorted(addr for addr, res in mine if near(res)),
            "plain": sum(res.get("plain", 0) for _, res in mine), "gdb": sum(res.get("gdb", 0) for _, res in mine),
            "errors": sum(1 for _, res in mine if res.get("error")),
            "match_step": dict(collections.Counter(res["match"]["step"] for _, res in mine
                                                   if res.get("match") and res["match"]["rule"] != "as is")),
            "rules": {k: v for k, v in sorted(per.items())}}
    moved = collections.Counter()
    for r in rows:
        res = r["arms"].get("scored") or {}
        for rule in {m["rule"] for m in res.get("movers", []) if m["step"] == 0}:
            moved[rule] += 1
    s["rules_that_moved_a_named_decision"] = dict(moved.most_common())
    s["drafts_with_a_named_decision_moved"] = sum(1 for r in rows if any(m["step"] == 0 for m in (r["arms"].get("scored") or {}).get("movers", [])))
    s["drafts_certified"] = sum(1 for r in rows if r.get("decisions") is not None)
    return s


def print_summary(s):
    print(f"climb {s['tag']}: {s['drafts']} drafts ({s['drafts_certified']} certified), up to {s['steps']} steps, "
          f"{s['cap']} variants a step, beam {s['beam']}")
    for arm, r in s["arms"].items():
        print(f"  {arm:6}: {len(r['matched'])} matched, {len(r['closer'])} closer, {r['plain']} plain compiles + {r['gdb']} under gdb"
              + (f", {r['errors']} errors" if r["errors"] else ""))
        if r["matched"]:
            print(f"          matched: {' '.join(r['matched'])}  (at step: {r['match_step']})")
        if r["closer"]:
            print(f"          closer:  {' '.join(r['closer'])}")
        for rule, v in r["rules"].items():
            print(f"          {rule:28} match {len(v['match']):2}  closer {len(v['closer']):2}  {' '.join(v['match'])}")
    print(f"  a named decision moved by some edit in {s['drafts_with_a_named_decision_moved']} drafts; by rule: "
          + ", ".join(f"{k} {v}" for k, v in s["rules_that_moved_a_named_decision"].items()))


def cmd_climb(a):
    import finish_near
    import retry_brief
    done = set(project.sources(refresh=True)) if not a.include_matched else set()
    if a.include_matched:
        a.dry = True            # a measurement on kept drafts of functions that have a source: nothing to save
    only = {int(x, 16) for x in a.only.split(",")} if a.only else None
    items = []
    for addr, e in retry_brief.queue(a.within):
        path = os.path.join(ROOT, e["draft"])
        if addr in done or not os.path.isfile(path) or (only and addr not in only):
            continue
        row = retry_brief.load(os.path.join(OUT, f"{addr:08x}_{C.digest(path)}.json"))
        items.append((addr, path, row, a))
    if only:
        # a function asked for by address that the queue does not hold: its closest measured draft
        have = {i[0] for i in items}
        for addr in sorted(only - have - done):
            found = retry_brief.candidates(addr)
            if found:
                path = os.path.join(ROOT, found[0]["path"])
                items.append((addr, path, found[0]["row"], a))
    items = items[:a.limit]
    d = os.path.join(CLIMB, a.tag)
    os.makedirs(d, exist_ok=True)
    out_path = os.path.join(d, "results.jsonl")
    log(f"climb {a.tag}: {len(items)} drafts ({sum(1 for i in items if total(i[2]) is not None)} certified), {a.jobs} jobs, "
        f"{a.steps} steps of {a.cap} variants" + (", blind arm at the same number of compiles" if a.blind else ""))
    rows, saved, held = [], {}, {}
    import multiprocessing
    started = time.time()
    with multiprocessing.Pool(a.jobs, maxtasksperchild=8) as pool, open(out_path, "w") as f:
        for n, r in enumerate(pool.imap_unordered(climb_one, items), 1):
            rows.append(r)
            f.write(json.dumps(r) + "\n")
            f.flush()
            sc = r["arms"].get("scored") or {}
            bl = r["arms"].get("blind") or {}
            for arm, res in (("scored", sc), ("blind", bl)):
                m = res.get("match")
                if not m or r["addr"] in saved or r["addr"] in held:
                    continue
                if m.get("review"):
                    held[r["addr"]] = {"by": arm, "variant": m["path"], "review": m["review"]}
                    log(f"{r['addr']}: MATCH by {arm} ({m['rule']}: {m['site']}) held back: {'; '.join(m['review'])}")
                    continue
                msg = finish_near.save(int(r["addr"], 16), m["path"]) if not a.dry else "dry run: not saved"
                saved[r["addr"]] = {"by": arm, "variant": m["path"], "rule": m["rule"], "site": m["site"], "save": msg}
                log(f"{r['addr']}: MATCH by {arm} at step {m['step']} ({m['rule']}: {m['site']}): {msg}")
            if closer(sc):
                e = sc["end"]
                ext = os.path.splitext(e["draft"])[1]
                best = os.path.join(d, r["addr"], "best" + ext)
                try:
                    shutil.copyfile(os.path.join(ROOT, e["draft"]), best)
                except OSError:
                    pass
                log(f"{r['addr']}: closer, {sc['start'].get('decisions')} -> {e.get('decisions')} decisions "
                    f"({sc['start'].get('units')} -> {e.get('units')} units) by {', '.join(taken_rules(sc))}")
            if n % 10 == 0 or n == len(items):
                log(f"progress: {n} of {len(items)} drafts, {len(saved)} matched, "
                    f"{sum(1 for x in rows if closer(x['arms'].get('scored') or {}))} closer, {time.time() - started:.0f}s")
    s = summarise(rows, a)
    s.update(saved=saved, held=held, seconds=round(time.time() - started))
    json.dump(s, open(os.path.join(d, "summary.json"), "w"), indent=1)
    print_summary(s)
    for addr, v in saved.items():
        print(f"  saved {addr} ({v['by']}, {v['rule']}): {v['save']}")
    print(f"written: build/oracle/climb/{a.tag}/results.jsonl, summary.json")


def cmd_movers(a):
    path = os.path.join(CLIMB, a.tag, "results.jsonl")
    want = {f"{int(x, 16):08x}" for x in a.addrs.split(",")}
    for line in open(path):
        r = json.loads(line)
        if r["addr"] not in want:
            continue
        sc = r["arms"].get("scored") or {}
        first = dict(sc["steps"][0] if sc.get("steps") else {})
        if "named" in sc:
            first.update(named=sc["named"], visible=sc["visible"])
        print(f"{r['addr']} {r['draft']}: {r.get('decisions')} decision(s); {first.get('variants', 0)} variants "
              f"at the first step"
              + (f"; MATCH by {' + '.join(taken_rules(sc)) or sc['match']['rule']}: {sc['match']['site']}" if sc.get("match") else "")
              + (f"; error: {sc['error']}" if sc.get("error") else ""))
        named = first.get("named", [])
        for k, text in enumerate(named):
            if not (first.get("visible") or [True] * len(named))[k]:
                print(f"   {k + 1}. {text}")
                continue
            movers = [m for m in sc.get("movers", []) if m["step"] == 0 and m["moved"][k]]
            clean = [m for m in movers if not m["broke"] and not m["after"]["content"]]
            print(f"   {k + 1}. {text}")
            if not movers:
                print("        no edit moved it")
                continue
            by = collections.defaultdict(list)
            for m in movers:
                by[m["rule"]].append(m)
            for rule, ms in sorted(by.items(), key=lambda kv: min(x["after"]["units"] for x in kv[1])):
                b = min(ms, key=lambda x: (x["after"]["units"], x["broke"]))
                print(f"        {rule}: {len(ms)} edit(s); best: {b['site'][:70]} -> {b['after']['units']} unit(s) left, "
                      f"{b['after']['rows']} rows, broke {b['broke']} row(s)")
            print(f"        {len(clean)} of {len(movers)} moved it without breaking a row that was right")
        if not named:
            print("   no named decision (not certified): searched on units only")
        for st in sc.get("steps", []):
            if st.get("to"):
                print(f"   step {st['step']}: {st['to']['rule']} ({st['to']['site'][:60]}) -> "
                      f"{st['to'].get('decisions')} decision(s), {st['to'].get('units')} unit(s)"
                      + ("" if st["to"].get("taken") else "  [not taken]"))


def add_parsers(sub):
    p = sub.add_parser("climb")
    p.add_argument("-j", "--jobs", type=int, default=3)
    p.add_argument("--steps", type=int, default=3)
    p.add_argument("--cap", type=int, default=160, help="variants compiled per step and draft")
    p.add_argument("--beam", type=int, default=2, help="variants the search goes on from per step (stepwise: certified per step)")
    p.add_argument("--movers", type=int, default=2,
                   help="beside the beam: variants that took a named decision the original's way, whatever they broke")
    p.add_argument("--rows", type=int, default=0,
                   help="beside those: variants with the fewest differing rows (the blind search's ranking)")
    p.add_argument("--stepwise", action="store_true",
                   help="the first measurement's search: one draft at a time, each step certified by the oracle")
    p.add_argument("--blind", action="store_true", help="also search blindly from every draft, at the same number of compiles")
    p.add_argument("--within", type=int, default=3, help="uncertified drafts with at most this many instructions left")
    p.add_argument("--only")
    p.add_argument("--limit", type=int, default=10 ** 6)
    p.add_argument("--tag", default="c1")
    p.add_argument("--dry", action="store_true", help="save nothing")
    p.add_argument("--include-matched", action="store_true",
                   help="also the kept drafts of functions matched meanwhile (a measurement: implies --dry)")
    p.add_argument("--seconds", type=int, default=900, help="time limit per draft and arm")
    p.add_argument("--report-seconds", type=int, default=120, help="time limit of one oracle report")
    p = sub.add_parser("movers")
    p.add_argument("addrs")
    p.add_argument("--tag", default="c1")


COMMANDS = {"climb": cmd_climb, "movers": cmd_movers}
