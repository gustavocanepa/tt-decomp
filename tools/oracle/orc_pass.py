"""The passes after register allocation, and all of them together.

steer    the second scheduler: move the insns toward the original's order at every pick (the
         reorder hook once per cycle and, in gcc 2.96, after each issue), ending a cycle early
         when the insn the original has next still waits in the queue.
slots    the delay-slot pass (reorg): what filled each slot, from which thread, annulled or not,
         what the liveness scan believed at the other thread and where it stopped; and a search
         over its decisions (a register live or dead at a target, a call the scan may pass, a
         candidate refused, a branch prediction) for the ones that give the original's slots.
compose  allocation, scheduling and delay slots in the compiler's order, each forced on top of
         the ones before it, until the output is the original or nothing moves. The result is
         one decision list across passes, or the instructions no decision accounts for.

Everything here produces certificates: a forced compile that equals the original says the
draft's logic is the original's. Nothing here is a match and nothing is saved.
"""
import collections
import time

import match
import orc_core as C
import orc_early as E
import orc_rtl as R

# (delay-slot instructions placed before their branch, passes steered, stall): tried in order
TRIES = ((False, [2], False), (True, [2], False), (True, [2], True), (False, [2], True), (False, [1, 2], False))
GATE = 2            # instructions no decision accounts for, at most, for the passes to be tried
MAX_SLOT_ROUNDS = 5
MAX_SLOT_CANDIDATES = 24
BUDGET = 100        # seconds one draft may spend in compose before it reports what it has
PRIORITY = {"nothrow": 0, "live": 1, "take": 2, "predict": 3, "reject": 4}


# ---------------------------------------------------------------- scheduler

def order_map(s, lst, slots=False):
    """({insn uid: wanted position}, exact): where the original has each of my instructions.
    Exact when mine are a permutation of the original's (branch form aside); otherwise only the
    instructions found in both are placed. With slots, an instruction the original has in a
    delay slot is placed just before its branch or call: that is where the scheduler must leave
    it for reorg to take it."""
    mine = [R.canon(w) for w in lst.linked]
    raw = s.padded(len(mine))
    target = [R.canon(w) for w in raw]
    exact = len(mine) == len(target) and collections.Counter(mine) == collections.Counter(target)
    where = collections.defaultdict(list)
    for j, w in enumerate(target):
        where[w].append(j)
    order = {}
    for w, (_, _, uid) in zip(mine, lst.words):
        if not where[w]:
            continue
        j = where[w].pop(0)
        if uid is not None and uid not in order:
            order[uid] = 2 * j - 3 if slots and j and R.transfers(raw[j - 1]) else 2 * j
    return order, exact


def steer(s, force, reorg=None, tag="s", base=None):
    """Steer the scheduler toward the original's order, on top of the registers in `force` and
    the delay-slot overrides in `reorg`. Returns {"result", "differ", "score", "cfg", "picks",
    "blocked", ...}; `cfg` is the scheduler configuration of the best try, None when nothing got
    closer; `blocked` names the insns the original has earlier than a dependence allows here."""
    if base is None:
        base = s.forced(tag + "n", force, sched={"trace": True}, reorg=reorg)
    ok, report, lst, _, rec, _ = base
    out = {"result": "already equal" if ok else "not reproduced", "differ": C.differ(report), "score": s.score(report, lst),
           "cfg": None, "tries": [], "blocked": []}
    if ok:
        return out
    blocks = rec.get("sched_blocks") or {}
    out["steps"] = len(rec.get("sched", []))
    best = out["score"]
    for slots, passes, stall in TRIES:
        order, exact = order_map(s, lst, slots)
        out["permutation"] = exact
        if not order or (stall and not blocks):
            continue
        cfg = {"order": order, "passes": passes}
        if stall:
            cfg.update(blocks=blocks, stall=True)
        try:
            ok2, report2, lst2, _, rec2, _ = s.forced(f"{tag}{int(slots)}{len(passes)}{int(stall)}", force, sched=cfg, reorg=reorg)
        except C.OracleError as e:
            out["tries"].append({"passes": passes, "slots": slots, "stall": stall, "error": str(e)[:80]})
            continue
        changed, seen = [], set()
        for st in rec2.get("sched", []):        # one issue may show at two hooks: count the insn once
            if "forced" in st and st["forced"] not in seen:
                seen.add(st["forced"])
                changed.append(st)
        d, sc = C.differ(report2), s.score(report2, lst2)
        out["tries"].append({"passes": passes, "slots": slots, "stall": stall, "differ": d, "picks_changed": len(changed)})
        blocked = [st["blocked"] for st in rec2.get("sched", []) if st.get("blocked", {}).get("by")]
        if blocked and not out["blocked"]:
            notes = R.barriers(s.dump(f"{tag}{int(slots)}{len(passes)}{int(stall)}", "greg", lst2.fname))
            for bl in blocked[:6]:
                e = {"want": bl["want"], "line": s.line_of(bl["want"]),
                     "by": [{"insn": u, "kind": k, "line": s.line_of(u), **({"barrier": notes[u]} if u in notes else {})}
                            for u, k in bl["by"][:4]]}
                out["blocked"].append(e)
        if sc < best:
            best = sc
            out.update(result="reproduced" if ok2 else "closer", cfg=cfg, differ=d, score=sc, passes=passes, slots=slots, stall=stall,
                       picks_changed=len(changed), stalls=sum(1 for st in changed if "stall" in st),
                       picks=[dict({"step": st["key"], "ready": st["ready"], "picked": st["pick"], "forced": st["forced"],
                                    "line": s.line_of(st["forced"]), "picked_line": s.line_of(st["pick"])},
                                   **({"stall": st["stall"]} if "stall" in st else {}),
                                   **({"rank": st["rank"], "why": why_pick(st)} if "rank" in st else {})) for st in changed][:20],
                       report=report2, lst=lst2)
        if ok2:
            break
    out["best"] = best
    return out


NEED = {
    "priority": "priority is the longest latency path from an insn to the end of its block: the original's insn needs a longer "
                "chain of dependents after it, or this one a shorter one (what uses each value, and how late)",
    "dependents": "the original's insn needs more insns depending on it than this one. Dependences come from registers too: a "
                  "callee declared void that really returns a value (or the reverse) changes the ones on $v0, a call's "
                  "argument registers and its clobbers likewise",
    "tie to the last issued insn": "an insn tied to the one just issued by an anti or output dependence goes after an "
                                   "independent one: what was issued just before differs in the original",
    "source order": "equal for the scheduler: the earlier one in the source goes first. Exchange the two statements, the "
                    "operands of the expression, or the order of the arguments",
    "register weight": "before reload an insn that frees a register goes before one that takes one: a value dies (or is "
                       "born) in the other insn in the original",
    "no sort": "the order follows the dependents list of the insn issued just before, which is the reverse of the order in "
               "which the insns were analysed: the two insns are in the other order in the source",
    "not ready": "something makes the other insns wait in the original, or this one ready earlier: a latency (a load, a "
                 "multiply) or a dependence that this draft has and the original has not",
}


def why_pick(st):
    """One changed pick as a sentence with the inputs of the scheduler's ranking."""
    r = st.get("rank") or {}
    if "decided_by" not in r:
        return None
    n, w = r["natural"], r["wanted"]
    side = lambda x: ", ".join(f"{k} {x[k]}" for k in ("priority", "dependents", "luid") if k in x)
    return (f"this compile issues insn {n['uid']} ({side(n)}), the original insn {w['uid']}" + (f" ({side(w)})" if side(w) else "")
            + f"; decided by {r['decided_by']}: {r['text']}")


# ---------------------------------------------------------------- delay slots

def slot_table(s, lst, rec):
    """One row per instruction with a delay slot, as this compile left it: what is in the slot,
    which phase put it there, from where, annulled or not, and the original's at that place."""
    rg = rec.get("reorg") or {}
    mine = lst.linked
    target = s.padded(len(mine))
    pair = dict(R.align_words(mine, target))
    fills = {}
    for f in rg.get("fills", []):
        fills[f["insn"]] = f
    before = {uid: n for n, (uid, _) in enumerate(rg.get("before", []))}
    rows = []
    for i, w in enumerate(mine):
        if not R.transfers(w) or i + 1 >= len(mine):
            continue
        uid, slot_uid = lst.words[i][2], lst.words[i + 1][2]
        f = fills.get(uid)
        row = {"index": i, "uid": uid, "line": s.line_of(uid), "likely": R.is_likely(w), "slot_uid": slot_uid,
               "slot_word": mine[i + 1], "filled": bool(mine[i + 1])}
        if f:
            src = f.get("thread")
            row["phase"] = f["phase"]
            if src:
                row["from"] = ("the branch target" if src["if_true"] else "the fall-through") + \
                    (" (its only user: moved)" if src["own"] else " (copied)")
                row["opposite"] = src["opposite"]
            elif slot_uid in before and uid in before:
                row["from"] = "before it" if before[slot_uid] < before[uid] else "after it"
        j = pair.get(i)
        if j is not None and j + 1 < len(target):
            row["original"] = {"index": j, "likely": R.is_likely(target[j]), "slot_word": target[j + 1]}
            row["differs"] = row["likely"] != R.is_likely(target[j]) or R.canon(mine[i + 1]) != R.canon(target[j + 1])
            if R.canon(mine[i + 1]) != R.canon(target[j + 1]) and target[j + 1]:
                # the instruction of mine that the original has in this slot: the nearest equal one
                want = R.canon(target[j + 1])
                near = sorted((abs(k - i), k) for k, w2 in enumerate(mine) if R.canon(w2) == want and lst.words[k][2] is not None)
                if near:
                    row["original_uid"] = lst.words[near[0][1]][2]
        else:
            row["differs"] = None       # no instruction of the original pairs with it
        rows.append(row)
    return rows


def slot_candidates(rows, rec, cur):
    """Single overrides worth trying for the slots that differ, from the trace of this compile."""
    rg = rec.get("reorg") or {}
    threads = collections.defaultdict(list)
    for t in rg.get("threads", []):
        threads[t["insn"]].append(t)
    live, stops, every = {}, collections.defaultdict(set), set()
    for l in rg.get("live", []):
        live[l["target"]] = set(l["live"])
        for c in l["stops"]:
            stops[l["for"]].add(c)
            every.add(c)
    predicted = dict((u, v) for u, v in rg.get("predict", []))
    out = []
    for row in rows:
        if not row.get("differs") or row["uid"] is None:
            continue
        b = row["uid"]
        regs = {R.written(row["slot_word"])}
        if row.get("original"):
            regs.add(R.written(row["original"]["slot_word"]))
        regs.discard(None)
        for t in threads.get(b, []):
            if t["opposite"] is None:
                continue
            for r in sorted(regs):
                out.append(("live", t["opposite"], "remove" if r in live.get(t["opposite"], ()) else "add", r))
        if row.get("original_uid") is not None:
            out.append(("take", b, row["original_uid"]))
        if row["filled"] and row["slot_uid"] is not None:
            out.append(("reject", b, row["slot_uid"]))
        if b in predicted:
            out += [("predict", b, v) for v in (2, 1, 0, -1) if v != predicted[b]]
        out += [("nothrow", c) for c in sorted(stops.get(b, ()))]
    if any(r.get("differs") for r in rows) and (every or any(k == "c" for _, k in rg.get("before", []))) \
            and cur.get("nothrow") is not True:
        # every call at once: the search does not record where each scan stopped (that costs a
        # stop per scanned insn); slot_search narrows it to the calls that matter afterwards
        out.insert(0, ("nothrow", True))
    seen, uniq = set(), []
    for c in out:
        if c not in seen and not applied(cur, c):
            seen.add(c)
            uniq.append(c)
    return uniq[:MAX_SLOT_CANDIDATES]


def applied(cfg, cand):
    kind = cand[0]
    if kind == "live":
        return cand[3] in cfg.get("live", {}).get(str(cand[1]), {}).get(cand[2], [])
    if kind == "reject":
        return [cand[1], cand[2]] in cfg.get("reject", [])
    if kind == "take":
        return cfg.get("take", {}).get(str(cand[1])) == cand[2]
    if kind == "predict":
        return cfg.get("predict", {}).get(str(cand[1])) == cand[2]
    return cfg.get("nothrow") is True or (cand[1] is not True and cand[1] in (cfg.get("nothrow") or []))


def with_override(cfg, cand):
    new = {"live": {t: {k: list(v) for k, v in d.items()} for t, d in cfg.get("live", {}).items()},
           "reject": [list(x) for x in cfg.get("reject", [])], "predict": dict(cfg.get("predict", {})),
           "take": dict(cfg.get("take", {})),
           "nothrow": cfg.get("nothrow") if cfg.get("nothrow") is True else list(cfg.get("nothrow") or [])}
    kind = cand[0]
    if kind == "live":
        d = new["live"].setdefault(str(cand[1]), {})
        other = "add" if cand[2] == "remove" else "remove"
        if cand[3] in d.get(other, []):
            d[other].remove(cand[3])
        d.setdefault(cand[2], []).append(cand[3])
    elif kind == "reject":
        new["reject"].append([cand[1], cand[2]])
    elif kind == "take":
        new["take"][str(cand[1])] = cand[2]
    elif kind == "predict":
        new["predict"][str(cand[1])] = cand[2]
    elif cand[1] is True:
        new["nothrow"] = True
    elif new["nothrow"] is not True:
        new["nothrow"].append(cand[1])
    return {k: v for k, v in new.items() if v}


def overrides(cfg):
    """A delay-slot configuration as a list of single decisions."""
    out = []
    for t, d in sorted((cfg or {}).get("live", {}).items()):
        out += [("live", int(t), how, r) for how in ("add", "remove") for r in d.get(how, [])]
    out += [("take", int(b), x) for b, x in sorted((cfg or {}).get("take", {}).items())]
    out += [("reject", b, x) for b, x in (cfg or {}).get("reject", [])]
    out += [("predict", int(u), v) for u, v in sorted((cfg or {}).get("predict", {}).items())]
    nt = (cfg or {}).get("nothrow")
    out += [("nothrow", True)] if nt is True else [("nothrow", c) for c in nt or []]
    return out


def slot_search(s, force, sched=None, start=None, tag="d", base=None, deadline=None):
    """Greedy search over delay-slot decisions: at each round every single override the trace
    suggests is compiled and judged, the one that comes closest to the original is kept.
    Returns {"result", "differ", "score", "cfg", "tried", ...}."""
    cfg = dict(start or {})
    if base is None:
        base = s.forced(tag + "n", force, sched=sched, reorg=dict(cfg, trace=True))
    ok, report, lst, _, rec, _ = base
    d0 = C.differ(report)
    out = {"result": "already equal" if ok else "not reproduced", "differ": d0, "score": s.score(report, lst), "cfg": None,
           "tried": 0, "rounds": []}
    if ok or d0 is None:
        return out
    best = out["score"]
    for rnd in range(MAX_SLOT_ROUNDS):
        rows = slot_table(s, lst, rec)
        cands = slot_candidates(rows, rec, cfg)
        if not cands:
            break
        scored = []
        for n, cand in enumerate(cands):
            if deadline and time.time() > deadline:
                break
            trial = with_override(cfg, cand)
            try:
                res = s.forced(f"{tag}{rnd}_{n}", force, sched=sched, reorg=dict(trial, trace=True))
            except C.OracleError:
                continue
            out["tried"] += 1
            if C.differ(res[1]) is not None:
                scored.append((s.score(res[1], res[2]), PRIORITY[cand[0]], n, cand, trial, res))
            if res[0] and cand[0] == "nothrow":
                break       # the most useful answer already
        if not scored:
            break
        sc, _, _, cand, trial, res = min(scored, key=lambda x: x[:3])
        out["rounds"].append({"candidates": len(cands), "kept": list(cand) if sc < best else None, "score": sc})
        if sc >= best:
            break
        best, cfg = sc, trial
        if cand == ("nothrow", True):
            # which calls: the ones a liveness scan stopped at; one of them alone if that is enough
            try:
                full = s.forced(f"{tag}{rnd}_f", force, sched=sched, reorg=dict(cfg, nothrow=[], trace="full"))
                calls = sorted({c for l in (full[4].get("reorg") or {}).get("live", []) for c in l["stops"]})
            except C.OracleError:
                calls = []
            for subset in [[c] for c in calls[:8]] + ([calls] if 1 < len(calls) <= 8 else []):
                narrow = dict(cfg, nothrow=subset)
                r2 = s.forced(f"{tag}{rnd}_s", force, sched=sched, reorg=dict(narrow, trace=True))
                out["tried"] += 1
                if C.differ(r2[1]) is not None and s.score(r2[1], r2[2]) <= sc:
                    cfg, res = narrow, r2
                    break
        ok, report, lst, _, rec, _ = res
        out.update(result="reproduced" if ok else "closer", differ=C.differ(report), score=sc, cfg=cfg, report=report, lst=lst, rec=rec)
        if ok:
            break
    out["best"] = best
    return out


def describe_slots(s, cfg, lst, rec):
    """The delay-slot overrides as sentences a reader can act on."""
    rg = rec.get("reorg") or {}
    stops = collections.defaultdict(set)
    users = collections.defaultdict(set)
    for l in rg.get("live", []):
        stops[l["target"]].update(l["stops"])
        if l["for"] is not None:
            users[l["target"]].add(l["for"])
    out = []
    for c in overrides(cfg):
        e = {"pass": "reorg", "decision": c[0]}
        if c[0] == "live":
            _, t, how, r = c
            e.update(target=t, line=s.line_of(t), register=R.regname(r), want="live" if how == "add" else "dead",
                     branches=sorted(users.get(t, ())), scan_stopped_at=sorted(stops.get(t, ())))
            e["why"] = (f"at insn {t}" + (f" (line {e['line']})" if e["line"] else "") + f" the original takes {e['register']} as "
                        f"{e['want']}; this compile finds it {'dead' if how == 'add' else 'live'} there. That decides whether "
                        f"the branch across it may take an instruction that sets {e['register']} into its slot, and whether "
                        "the slot is annulled (branch-likely)")
            if e["scan_stopped_at"]:
                e["why"] += ("; the liveness scan from there stopped at the call(s) " + ", ".join(map(str, e["scan_stopped_at"]))
                             + ", which may throw")
            e["need"] = ("a later use of that value on that path (live)" if how == "add" else
                         "no use of that value on that path before it is set again, or a callee on the way declared "
                         "`throw()` so that the scan sees the next set (dead)")
        elif c[0] == "nothrow":
            e.update(call=c[1], line=s.line_of(c[1]) if c[1] is not True else None)
            e["why"] = ("the liveness scan must pass " + ("every call" if c[1] is True else f"the call insn {c[1]}")
                        + ": in the original that callee cannot throw")
            e["need"] = "declare the callee `throw()`, or define it earlier in the same file (context closure, finish_near.py context)"
        elif c[0] == "take":
            e.update(branch=c[1], candidate=c[2], line=s.line_of(c[1]), candidate_line=s.line_of(c[2]))
            e["why"] = (f"the delay slot of insn {c[1]}" + (f" (line {e['line']})" if e["line"] else "") + f" holds insn {c[2]}"
                        + (f" (line {e['candidate_line']})" if e["candidate_line"] else "") + " in the original; here another "
                        "instruction is nearer to it and is taken first")
            e["need"] = ("that instruction must be the last one before the branch or call that it does not depend on: "
                         "in the original its statement (or that argument's evaluation) comes later")
        elif c[0] == "reject":
            e.update(branch=c[1], candidate=c[2], line=s.line_of(c[1]), candidate_line=s.line_of(c[2]))
            e["why"] = f"the original does not put insn {c[2]} into the delay slot of insn {c[1]}"
            e["need"] = "that instruction must not be the nearest one the branch does not depend on: another statement sits between them in the original"
        else:
            e.update(branch=c[1], value=c[2], line=s.line_of(c[1]))
            e["why"] = f"mostly_true_jump answers {c[2]} for the branch insn {c[1]} in the original"
            e["need"] = "the prediction follows the shape of the branch (loop back edge, comparison against zero, pointer test)"
        out.append(e)
    return out


# ---------------------------------------------------------------- all passes

def texts(s, words, indices):
    """The instructions at `indices` of a word list, disassembled as the judge prints them."""
    out = []
    for i in indices[:12]:
        try:
            out.append(" ".join(match.disasm(words[i], s.addr + 4 * i).split()))
        except Exception:
            out.append(f"{words[i]:08x}")
    return out


def early(s, row, lst, report):
    """For a draft a few instructions away in content (not in order or registers): what the
    passes before allocation made, deleted or rewrote where the two differ (orc_early)."""
    n = row.get("unaccounted_forced", row.get("unaccounted", 0))
    if not 1 <= n <= 4 or report is None:
        return
    try:
        e = E.explain(s, lst, report)
    except Exception as err:        # a dump this reader does not know must not cost the report
        row["early"] = {"error": f"{type(err).__name__}: {err}"[:160]}
        return
    e["text"] = E.sentences(e)
    row["early"] = e


def in_order(s, lst):
    """Are my instructions already in the original's order (as far as they can be placed)?"""
    order, _ = order_map(s, lst)
    seq = [order[uid] for _, _, uid in lst.words if uid in order]
    return all(a <= b for a, b in zip(seq, seq[1:]))


def compose(s, row):
    """Allocation, scheduling, delay slots, each on top of the others, to a fixed point. Adds to
    `row` (the report of oracle.py): `passes`, `combined`, `logic`, `only_original`,
    `only_draft`, `unaccounted`, `early`. The fields the allocation report wrote stay as they are."""
    fp = row.get("reload", {})
    force = {int(p): v[1] for p, v in fp.get("force", {}).items()} if fp.get("result") == "closer" else {}
    sched, reorg = None, {}
    # where allocation alone left it (no compile: the fixed point kept its best listing)
    report, lst = (s.best_report, s.best_lst) if force and getattr(s, "best_lst", None) else (s.report, s.lst)
    d, sc = C.differ(report), s.score(report, lst)
    only_mine, only_orig = R.unmatched(lst.linked, s.padded(len(lst.linked)))
    row["only_draft"] = texts(s, lst.linked, only_mine)
    row["only_original"] = texts(s, s.padded(len(lst.linked)), only_orig)
    row["unaccounted"] = len(only_mine) + len(only_orig)
    passes = {"differ": {"start": sc}, "order": []}
    row["passes"] = passes
    row["aligned"] = s.distance(report, lst)
    if d is None or row["unaccounted"] > GATE:
        row["logic"] = "open"
        row["combined"] = {"certified": False, "differ": d, "aligned": row["aligned"],
                           "reason": f"{row['unaccounted']} instructions could not be aligned with one of the other side, whatever "
                                     "the registers, the order or the branch form: the passes were not forced",
                           "only_draft": row["only_draft"], "only_original": row["only_original"]}
        early(s, row, lst, report)
        return row
    info = {"sched": None, "reorg": None, "blocked": []}
    deadline = time.time() + BUDGET
    for outer in range(3):
        before = sc
        if time.time() > deadline:
            passes["out_of_time"] = True
            break
        if sc:
            f2 = s.fixed_point(sched=sched, reorg=reorg or None, start=force, loose=True, tag=f"v{outer}")
            if f2["score_forced"] < sc:
                force = {int(p): v[1] for p, v in f2["force"].items()}
                sc, report, lst = f2["score_forced"], s.best_report, s.best_lst
                passes["order"].append("allocation")
        base = None
        if sc:
            # the state as it is, unsteered, with both traces: what the scheduler and reorg did
            base = s.forced(f"b{outer}", force, sched={"trace": True}, reorg=dict(reorg, trace=True))
            if not in_order(s, base[2]):
                st = steer(s, force, reorg or None, tag=f"s{outer}", base=base)
                info["blocked"] = st["blocked"]
                if st["cfg"] and st["best"] < sc:
                    sched, sc, report, lst = st["cfg"], st["best"], st["report"], st["lst"]
                    info["sched"] = st
                    passes["order"].append("sched")
                    base = None
            elif sched and s.score(base[1], base[2]) <= sc:
                # the registers moved since: the order no longer needs steering
                sched, info["sched"] = None, None
                sc, report, lst = s.score(base[1], base[2]), base[1], base[2]
        if sc:
            if base is None or sched:
                base = s.forced(f"c{outer}", force, sched=sched, reorg=dict(reorg, trace=True))
            if any(r.get("differs") for r in slot_table(s, base[2], base[4])):
                ss = slot_search(s, force, sched, reorg, tag=f"d{outer}", base=base, deadline=deadline)
                if ss["cfg"] and ss["best"] < sc:
                    reorg, sc, report, lst = ss["cfg"], ss["best"], ss["report"], ss["lst"]
                    info["reorg"] = ss
                    passes["order"].append("reorg")
        passes["differ"][f"round {outer}"] = sc
        if not sc or sc == before:
            break
    rec = {}
    if reorg:       # once more, with the full delay-slot trace, for the sentences of the report
        _, report, lst, _, rec, _ = s.forced("kf", force, sched=sched, reorg=dict(reorg, trace="full"))
    d = C.differ(report)
    ok = d == 0
    passes["allocation"] = {"pseudos": len(force), "force": {str(p): [s.disp.get(p, -1), h] for p, h in sorted(force.items())
                                                              if s.disp.get(p, -1) != h}}
    st = info["sched"]
    passes["sched"] = {k: st[k] for k in ("passes", "slots", "stall", "picks_changed", "stalls", "picks", "permutation")
                       if k in st} if st and sched else None
    passes["sched_blocked"] = info["blocked"] if not ok else []
    passes["reorg"] = {"overrides": [list(c) for c in overrides(reorg)], "decisions": describe_slots(s, reorg, lst, rec),
                       "tried": info["reorg"]["tried"] if info["reorg"] else 0} if reorg else None
    counts = {"allocation": len(passes["allocation"]["force"]), "sched": passes["sched"]["picks_changed"] if passes["sched"] else 0,
              "reorg": len(passes["reorg"]["overrides"]) if passes["reorg"] else 0}
    lines = [f"allocation: pseudo {p} in {R.regname(v[1])}, not {R.regname(v[0])}" for p, v in passes["allocation"]["force"].items()]
    if ok and counts["allocation"] and time.time() < deadline:
        # which allocation decisions those registers come down to, the other passes still forced
        try:
            rec0 = s.forced("t", {}, at="alloc", trace="light")[4]
            want = {int(p): h for p, h in rec0.get("renumber", {}).items()}
            want.update(force)
            ca = s.causal(want, sched=sched, reorg=reorg or None)
        except C.OracleError as e:
            ca = {"result": "error", "decisions": [], "note": str(e)[:120]}
        passes["allocation"]["causal"] = ca
        if ca["result"] == "match":
            counts["allocation"] = len(ca["decisions"])
            lines = [f"allocation: pseudo {x['pseudo']}" + (f" (`{x['var']}`)" if x.get("var") else "")
                     + (f" tied to pseudo {x['tied_to']['pseudo']}" if x.get("decision") == "tie" else
                        f" got {x.get('got')}, the original has {x.get('want')}") + f": {x.get('why', '')}" for x in ca["decisions"]]
    if passes["sched"]:
        for p in passes["sched"]["picks"]:
            lines.append(f"scheduler, step {p['step']}: issue insn {p['forced']}" + (f" (line {p['line']})" if p.get("line") else "")
                         + (" after ending the cycle" if "stall" in p else "") + f", not {p['picked']}"
                         + (f" (line {p['picked_line']})" if p.get("picked_line") else "")
                         + (f". {p['why'][0].upper()}{p['why'][1:]}" if p.get("why") else ""))
            if p.get("rank", {}).get("decided_by") in NEED:
                p["need"] = NEED[p["rank"]["decided_by"]]
    if passes["reorg"]:
        lines += ["delay slots: " + e["why"] for e in passes["reorg"]["decisions"]]
    row["combined"] = {"certified": ok, "differ": d, "aligned": s.distance(report, lst), "decisions": counts,
                       "total": sum(counts.values()), "passes": [k for k in ("allocation", "sched", "reorg") if counts[k]],
                       "list": lines[:40]}
    row["logic"] = "complete" if ok else "open"
    if not ok:
        row["combined"]["residual_class"] = C.classify(report)
        m2, o2 = R.unmatched(lst.linked, s.padded(len(lst.linked)))
        row["combined"]["only_draft"] = texts(s, lst.linked, m2)
        row["combined"]["only_original"] = texts(s, s.padded(len(lst.linked)), o2)
        row["unaccounted_forced"] = len(m2) + len(o2)
        early(s, row, lst, report)
        row["combined"]["blocked"] = [
            f"insn {b['want']}" + (f" (line {b['line']})" if b["line"] else "") + " comes earlier in the original than "
            + ", ".join(f"insn {x['insn']}" + (f" (line {x['line']})" if x["line"] else "") + f", on which it depends here ({x['kind']}"
                        + (f"; that insn follows {x['barrier']}: a loop or `do {{ }} while (0)` starts or ends there in this draft and "
                           "nothing is scheduled across it" if x.get("barrier") else "") + ")" for x in b["by"])
            for b in info["blocked"]]
    return row
