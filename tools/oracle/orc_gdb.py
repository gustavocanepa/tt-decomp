"""gdb side of tools/oracle.py: runs inside gdb against Sony's unstripped cc1plus / cc1.

    ORACLE_CFG=cfg.json gdb -q -batch -nx -x orc_gdb.py --args cc1plus ARGS...
    gdb -q -batch -nx -x orc_gdb.py cc1plus        (kept alive: a configuration file per line on
                                                   stdin, with "argv" and "stdout" in it; one
                                                   `ORACLE-DONE` line on stdout per compile)

It stops the compiler at its allocation (and scheduling) decisions, records them, and overrides
the ones the configuration names. Everything is addressed by symbol name (functions, globals,
struct fields), never by address, so the same script serves any compiler binary that kept its
symbols; the two layouts of the allocator's tables are both read (gcc 2.96: `struct qty`,
`struct allocno`; gcc 2.9: parallel arrays `qty_n_refs[]`, `allocno_reg[]`, `hard_reg_conflicts[]`).

Configuration (JSON):
    out            file the result is written to
    function       assembler name of the function to work on (others are compiled untouched)
    trace          "full" (every input of every decision), "light" (decisions and results only)
    force_reload   {pseudo: hard reg}: written into reg_renumber[] at the entry of reload()
    force_alloc    {pseudo: hard reg}: imposed where the decision is made (find_free_reg in
                   local-alloc, find_reg in global), so later decisions follow from it
    untie          [[pseudo, pseudo]]: pairs local-alloc must not put into one quantity
    sched          {"trace": bool, "force": {"PASS:BLOCK:STEP": uid}, "order": {uid: position},
                   "passes": [2], "every_pick": true}: the scheduler's ready list before each
                   pick (at the reorder hook once per cycle, and after each issue where the loop
                   takes the insns schedule_insn has just made ready), single picks to override,
                   or a whole wanted order (PASS 1 = before reload, 2 = after; BLOCK counts the
                   schedule_block calls of the pass). With "blocks" ({"PASS:BLOCK": [uids]}, as
                   a traced run returns them in `sched_blocks`) and "stall": true, a cycle is
                   ended early when the insn the order wants next is still in the queue.
                   Every changed pick carries `rank`: the inputs of rank_for_schedule for the
                   insn this compile would issue and for the wanted one (priority, dependents,
                   luid, register weight, tie to the last issued insn) and the comparison that
                   decided; "trace": "full" gives those inputs for the top of every ready list
    reorg          the delay-slot pass (reorg.c, resource.c), every key optional:
                   "trace": true | "full"   the insn chain as dbr_schedule receives it, every
                            fill (emit_delay_sequence) with the phase, the thread it came from and
                            the annul flag, every thread tried, every candidate that reached
                            eligible_for_delay / eligible_for_annul_false, every answer of
                            mark_target_live_regs, mostly_true_jump; with "full" also the calls
                            at which the liveness scan stopped (can_throw) and the candidates a
                            resource conflict refused
                   "live": {target uid: {"add": [hard regs], "remove": [hard regs]}}: what
                            mark_target_live_regs answers for that target, edited on return
                   "nothrow": true | [call uids]: the liveness scan does not stop at these calls
                   "predict": {jump uid: value}: the return of mostly_true_jump (-1..2)
                   "reject": [[delay insn uid, candidate uid]]: eligible_for_delay and
                            eligible_for_annul_false answer no for that pair
                   "take": {delay insn uid: candidate uid}: they answer no for every other
                            candidate of that delay insn (the compiler still decides whether
                            the wanted one may go there)
"""
import json
import os
import shlex
import struct
import sys

import gdb

CFG = {}


def configure(cfg):
    """Take one configuration (see the top of the file) into the module's globals and forget
    everything recorded for the one before."""
    global CFG, WANT, TRACE, F_RELOAD, F_ALLOC, SCHED, S_FORCE, S_ORDER, S_PASSES, S_BLOCKS, UNTIE
    global REORG, R_TRACE, R_LIVE, R_NOTHROW, R_PREDICT, R_REJECT, R_TAKE
    CFG = cfg
    WANT = CFG.get("function")
    TRACE = CFG.get("trace", "full")
    F_RELOAD = {int(k): int(v) for k, v in CFG.get("force_reload", {}).items()}
    F_ALLOC = {int(k): int(v) for k, v in CFG.get("force_alloc", {}).items()}
    SCHED = CFG.get("sched") or {}
    S_FORCE = {k: int(v) for k, v in SCHED.get("force", {}).items()}
    S_ORDER = {int(k): int(v) for k, v in SCHED.get("order", {}).items()}
    S_PASSES = set(SCHED.get("passes", [2]))
    S_BLOCKS = SCHED.get("blocks") or {}
    UNTIE = {tuple(x) for x in CFG.get("untie", [])}
    REORG = CFG.get("reorg") or {}
    R_TRACE = REORG.get("trace")
    R_LIVE = {int(k): (set(v.get("add", [])), set(v.get("remove", []))) for k, v in REORG.get("live", {}).items()}
    R_NOTHROW = REORG.get("nothrow")
    R_PREDICT = {int(k): int(v) for k, v in REORG.get("predict", {}).items()}
    R_REJECT = {(int(b), int(x)) for b, x in REORG.get("reject", [])}
    R_TAKE = {int(b): int(x) for b, x in REORG.get("take", {}).items()}
    OUT.clear()
    OUT.update({"functions": {}, "errors": []})
    ST.clear()
    ST.update({"fn": None, "block": None, "pending": None, "depth": 0, "mask": None, "sched_pass": 0, "sched_block": None,
               "sched_step": 0})


RTX = {}
UID_OFFSET = 4      # INSN_UID is the first operand of an insn: fld[0] follows the 4-byte header

for cmd in ("set pagination off", "set confirm off", "set breakpoint pending on",
            "set print thread-events off", "set debuginfod enabled off"):
    try:
        gdb.execute(cmd)
    except gdb.error:
        pass

OUT, ST = {}, {}
BPS = []        # the breakpoints of the current configuration
ADDRS = {}      # addresses found by disassembling, kept between runs of one gdb


def ev(expr):
    return gdb.parse_and_eval(expr)


def I(v):
    """A gdb value as a signed Python int (gdb reads these STABS ints back unsigned)."""
    x, bits_ = int(v), 8 * v.type.sizeof
    x &= (1 << bits_) - 1
    return x - (1 << bits_) if x >> (bits_ - 1) else x


def has(expr):
    try:
        ev(expr)
        return True
    except gdb.error:
        return False


QTY_STRUCT = has("qty")
ALLOCNO_STRUCT = has("allocno")
FIRST_PSEUDO = None


def arg(n):
    """n-th argument of the function just entered (the binary keeps frame pointers)."""
    return I(ev(f"*(int *)($ebp + {8 + 4 * n})"))


def hset(v):
    """A HARD_REG_SET value as a Python int (scalar, or an array of host words)."""
    if v.type.strip_typedefs().code == gdb.TYPE_CODE_ARRAY:
        lo, hi = v.type.strip_typedefs().range()
        width = v[lo].type.sizeof * 8
        out = 0
        for i in range(lo, hi + 1):
            out |= (int(v[i]) & ((1 << width) - 1)) << (width * (i - lo))
        return out
    return int(v) & ((1 << (v.type.sizeof * 8)) - 1)


def write_hset(v, value):
    t = v.type.strip_typedefs()
    inf = gdb.selected_inferior()
    size = t.sizeof
    inf.write_memory(int(v.address), value.to_bytes(size, "little"))


def bits(x):
    out, i = [], 0
    while x:
        if x & 1:
            out.append(i)
        x >>= 1
        i += 1
    return out


def qf(q, name):
    return ev(f"qty[{q}].{name}") if QTY_STRUCT else ev(f"qty_{name}[{q}]")


ALLOCNO_ARRAY = {"reg": "allocno_reg", "size": "allocno_size", "calls_crossed": "allocno_calls_crossed",
                 "n_refs": "allocno_n_refs", "live_length": "allocno_live_length"}


def af(a, name):
    if ALLOCNO_STRUCT:
        return ev(f"allocno[{a}].{name}")
    return ev(f"{ALLOCNO_ARRAY.get(name, name)}[{a}]")


def fn_name():
    try:
        d = ev("current_function_decl")
        if int(d) == 0:
            return None
        return d.dereference()["decl"]["assembler_name"].dereference()["identifier"]["pointer"].string()
    except gdb.error as e:
        return None


def active():
    return ST["fn"] is not None and (WANT is None or ST["fn"] == WANT)


def rec():
    return OUT["functions"].setdefault(ST["fn"], {"local": [], "global": [], "sched": [], "forced": [], "failed": []})


def enter_function():
    ST["fn"] = fn_name()
    ST["block"] = None
    ST["pending"] = None
    ST["depth"] = 0


def renumber(p):
    return I(ev(f"reg_renumber[{p}]"))


def settle():
    """The result of the last global find_reg call is in reg_renumber once it has returned."""
    p = ST["pending"]
    if p is not None:
        p["result"] = renumber(p["_pseudo"])
        del p["_pseudo"]
        ST["pending"] = None


class Stop(gdb.Breakpoint):
    def __init__(self, spec, fn):
        super().__init__(spec, internal=True)
        self.fn = fn
        BPS.append(self)

    def stop(self):
        try:
            self.fn()
        except Exception as e:  # never leave the compiler stopped
            import traceback
            if len(OUT["errors"]) < 20:
                OUT["errors"].append(f"{self.location}: {type(e).__name__}: {e}: " + traceback.format_exc()[-300:])
        return False


# ------------------------------------------------------------------ local-alloc

def on_local_alloc():
    enter_function()


def on_block_alloc():
    if ST["fn"] is None:
        enter_function()
    ST["block"] = arg(0)
    ST["depth"] = 0


def qty_pseudos(q):
    out = []
    i = I(qf(q, "first_reg"))
    while i >= 0 and len(out) < 64:
        out.append(i)
        i = I(ev(f"reg_next_in_qty[{i}]"))
    return out


def on_find_free_reg():
    if not active():
        return
    outer = ST["depth"] == 0
    ST["depth"] += 1
    if not outer:
        return
    cls, mode, q, acc, sugg, born, dead = (arg(i) for i in range(7))
    pseudos = qty_pseudos(q)
    call = {"block": ST["block"], "qty": q, "pseudos": pseudos, "class": cls, "accept_call_clobbered": acc,
            "just_try_suggested": sugg, "born": born, "dead": dead, "result": None}
    if TRACE == "full":
        call.update(n_refs=I(qf(q, "n_refs")), birth=I(qf(q, "birth")), death=I(qf(q, "death")),
                    size=I(qf(q, "size")), calls_crossed=I(qf(q, "n_calls_crossed")),
                    mode=I(qf(q, "mode")),
                    sugg=bits(hset(ev(f"qty_phys_sugg[{q}]"))) if I(ev(f"qty_phys_num_sugg[{q}]")) else [],
                    copy_sugg=bits(hset(ev(f"qty_phys_copy_sugg[{q}]"))) if I(ev(f"qty_phys_num_copy_sugg[{q}]")) else [])
        live = 0
        if dead > born:
            v0 = ev(f"regs_live_at[{born}]")
            size = v0.type.strip_typedefs().sizeof
            raw = bytes(gdb.selected_inferior().read_memory(int(v0.address), size * (dead - born)))
            for k in range(dead - born):
                live |= int.from_bytes(raw[k * size:(k + 1) * size], "little")
        call["live"] = bits(live)
    rec()["local"].append(call)
    ST["call"] = call
    want = next((F_ALLOC[p] for p in pseudos if p in F_ALLOC), None)
    ST["mask"] = None
    if want is not None and dead > born:
        v = ev(f"regs_live_at[{born}]")
        saved = hset(v)
        full = (1 << (v.type.strip_typedefs().sizeof * 8)) - 1
        write_hset(v, saved | (full & ~(1 << want)))
        ST["mask"] = (born, saved, want)
        call["forced"] = want
        if sugg:    # decide it now, among all registers, not only the suggested ones
            gdb.execute("set var *(int *)($ebp + 24) = 0")


def on_find_free_reg_return():
    if not active() or ST["depth"] == 0:
        return
    ST["depth"] = 0
    result = I(ev("$eax"))
    call = ST.get("call")
    if call is not None:
        call["result"] = result
    if ST["mask"]:
        born, saved, want = ST["mask"]
        v = ev(f"regs_live_at[{born}]")
        write_hset(v, saved | ((1 << result) if result >= 0 else 0))
        ST["mask"] = None
        if result != want and call is not None:
            call["force_failed"] = True


def rtx_regno(ptr):
    """Register number of a REG, looking through SUBREGs; None for anything else."""
    inf = gdb.selected_inferior()
    for _ in range(4):
        code = struct.unpack("<H", bytes(inf.read_memory(ptr, 2)))[0]
        first = struct.unpack("<i", bytes(inf.read_memory(ptr + UID_OFFSET, 4)))[0]
        if code == RTX["REG"]:
            return first
        if code != RTX["SUBREG"]:
            return None
        ptr = first & 0xFFFFFFFF
    return None


def on_combine_regs():
    """combine_regs (usedreg, setreg, may_save_copy, insn_number, insn, already_dead) ties the
    register set by an insn to an operand that dies in it: one quantity, one hard register. A
    pair named in `untie` is kept apart: the call is handed something that is not a register."""
    if not active():
        return
    # stopped on the function's first instruction (the prologue copies the arguments into
    # registers): the arguments are above the return address
    sp = I(ev("$esp")) & 0xFFFFFFFF
    inf = gdb.selected_inferior()
    a0, a1, _, _, insn = struct.unpack("<5I", bytes(inf.read_memory(sp + 4, 20)))
    u, s_ = rtx_regno(a0), rtx_regno(a1)
    if u is None or s_ is None:
        return
    if (u, s_) in UNTIE or (s_, u) in UNTIE:
        inf.write_memory(sp + 4, struct.pack("<I", insn))
        rec().setdefault("untied", []).append([u, s_])


# ------------------------------------------------------------------ global

def on_global_alloc():
    if ST["fn"] is None:
        enter_function()
    ST["depth"] = 0


def on_find_reg():
    if not active():
        return
    settle()
    num, losers, alt, acc, retrying = (arg(i) for i in range(5))
    pseudo = I(af(num, "reg"))
    call = {"allocno": num, "pseudo": pseudo, "alt_regs_p": alt, "accept_call_clobbered": acc, "retrying": retrying,
            "losers": 1 if losers else 0, "result": None, "_pseudo": pseudo}
    want = F_ALLOC.get(pseudo)
    if want is not None:
        v = af(num, "hard_reg_conflicts")
        full = (1 << (v.type.strip_typedefs().sizeof * 8)) - 1
        call["conflicts_before_force"] = bits(hset(v))
        write_hset(v, hset(v) | (full & ~(1 << want)))
        call["forced"] = want
    if TRACE == "full":
        call.update(n_refs=I(af(num, "n_refs")), live_length=I(af(num, "live_length")), size=I(af(num, "size")),
                    calls_crossed=I(af(num, "calls_crossed")),
                    conflicts=call.get("conflicts_before_force") or bits(hset(af(num, "hard_reg_conflicts"))),
                    prefs=bits(hset(af(num, "hard_reg_preferences"))),
                    copy_prefs=bits(hset(af(num, "hard_reg_copy_preferences"))),
                    used_so_far=bits(hset(ev("regs_used_so_far"))))
        for name in ("hard_reg_full_preferences", "regs_someone_prefers"):
            try:
                call[name] = bits(hset(af(num, name)))
            except gdb.error:
                pass
    rec()["global"].append(call)
    ST["pending"] = call


# ------------------------------------------------------------------ reload

CALLEE_SAVED = set(range(16, 24)) | {30} | set(range(52, 64))


def decl_vars():
    """{pseudo: [name, line, kind]} for every variable and parameter whose home is a pseudo."""
    out = {}
    seen = 0

    def one(d, kind):
        nonlocal seen
        seen += 1
        decl = d.dereference()["decl"]
        rtl = decl["rtl"]
        if int(rtl) == 0:
            return
        r = rtl.dereference()
        if str(r["code"]) != "REG":
            return
        regno = int(r["fld"][0]["rtint"])
        name = decl["name"]
        text = name.dereference()["identifier"]["pointer"].string() if int(name) else None
        entry = [text, int(decl["linenum"]), kind]
        if regno not in out or (out[regno][0] is None and text):
            out[regno] = entry

    def chain(d, kind):
        while int(d) and seen < 4000:
            code = str(d.dereference()["common"]["code"])
            if code in ("VAR_DECL", "PARM_DECL", "RESULT_DECL"):
                one(d, "param" if code == "PARM_DECL" else kind)
            d = d.dereference()["common"]["chain"]

    def block(b, depth):
        while int(b) and seen < 4000:
            blk = b.dereference()["block"]
            chain(blk["vars"], f"local{depth}")
            block(blk["subblocks"], depth + 1)
            b = b.dereference()["common"]["chain"]

    f = ev("current_function_decl").dereference()["decl"]
    chain(f["arguments"], "param")
    init = f["initial"]
    if int(init) and str(init.dereference()["common"]["code"]) == "BLOCK":
        block(init, 0)
    return out


def on_reload():
    if ST["fn"] is None or fn_name() != ST["fn"]:
        enter_function()
    if not active():
        return
    settle()
    r = rec()
    n = I(ev("max_regno"))
    first = FIRST_PSEUDO
    base = I(ev("reg_renumber"))
    raw = bytes(gdb.selected_inferior().read_memory(base + 2 * first, 2 * (n - first)))
    ren = struct.unpack(f"<{n - first}h", raw)
    r["renumber"] = {str(first + i): h for i, h in enumerate(ren)}
    try:
        r["vars"] = {str(k): v for k, v in decl_vars().items()}
    except Exception as e:
        OUT["errors"].append(f"decl walk: {type(e).__name__}: {e}")
    if F_RELOAD:
        final = dict(zip(range(first, n), ren))
        vacated = set()
        for p, h in F_RELOAD.items():
            if first <= p < n:
                vacated.add(final[p])
                final[p] = h
                gdb.execute(f"set var reg_renumber[{p}] = {h}")
                r["forced"].append([p, h])
            else:
                r["failed"].append([p, h, "no such pseudo"])
        used = set(final.values())
        for h in vacated:
            # a callee-saved register nothing lives in any more must not be saved by the prologue
            if h in CALLEE_SAVED and h not in used:
                gdb.execute(f"set var regs_ever_live[{h}] = 0")
    ST["fn"] = None


# ------------------------------------------------------------------ scheduler (haifa)

def on_schedule_insns():
    restore_rate()
    fn = fn_name()
    if ST.get("sched_fn") != fn:
        ST["sched_fn"] = fn
        ST["sched_pass"] = 0
    ST["sched_pass"] += 1
    ST["sched_block"] = None
    ST["sched_seq"] = -1


def restore_rate():
    if ST.get("rate") is not None:
        gdb.execute(f"set var issue_rate = {ST['rate']}")
        ST["rate"] = None


def on_schedule_block():
    restore_rate()
    ST["sched_block"] = arg(0)
    ST["sched_seq"] = ST.get("sched_seq", -1) + 1
    ST["sched_step"] = 0
    ST["issued"] = []
    ST["stalls"] = {}


def steer(base, n, mid):
    """Rearrange ready[0..n) (the insn at ready[n - 1] is issued next). With an order ({uid:
    wanted position}) the listed insns are rearranged among the places they hold so that they
    leave in that order; picks named one by one are moved to the top."""
    restore_rate()
    fn = ST.get("sched_fn")
    if fn is None or (WANT is not None and fn != WANT) or n <= 0:
        return
    inf = gdb.selected_inferior()
    ptrs = list(struct.unpack(f"<{n}I", bytes(inf.read_memory(base, 4 * n))))
    uids = [struct.unpack("<i", bytes(inf.read_memory(p + UID_OFFSET, 4)))[0] for p in ptrs]
    # PASS:BLOCK:STEP, BLOCK counted over the pass (after reload every block is its own region
    # and schedule_block's own argument is always 0)
    key = f"{ST['sched_pass']}:{ST.get('sched_seq', 0)}:{ST['sched_step']}"
    ST["sched_step"] += 1
    step = {"key": key, "ready": uids, "pick": uids[-1]}
    if mid:
        step["mid"] = 1
    new = list(range(n))
    if S_ORDER and ST["sched_pass"] in S_PASSES:
        slots = [i for i in range(n) if uids[i] in S_ORDER]
        ranked = sorted(slots, key=lambda i: -S_ORDER[uids[i]])
        for slot, src in zip(slots, ranked):
            new[slot] = src
    want = S_FORCE.get(key)
    if want is not None:
        if want in uids:
            i = [uids[k] for k in new].index(want)
            new.append(new.pop(i))
        else:
            step["force_failed"] = want
    if new != list(range(n)):
        inf.write_memory(base, struct.pack(f"<{n}I", *[ptrs[k] for k in new]))
        step["order"] = [uids[k] for k in new]
        if new[-1] != n - 1:
            step["forced"] = uids[new[-1]]
            try:    # why this compile would have issued the other one
                nat, want_ = rank_inputs(ptrs[-1], uids[-1]), rank_inputs(ptrs[new[-1]], uids[new[-1]])
                by, text = decided(nat, want_, ST["sched_pass"] == 1, mid)
                step["rank"] = {"natural": nat, "wanted": want_, "decided_by": by, "text": text}
            except Exception as e:
                step["rank"] = {"error": f"{type(e).__name__}: {e}"[:120]}
    if SCHED.get("trace") == "full":
        try:
            step["inputs"] = [rank_inputs(ptrs[k], uids[k]) for k in range(max(0, n - 8), n)]
        except Exception as e:
            step["inputs_error"] = str(e)[:80]
    blk = S_BLOCKS.get(f"{ST['sched_pass']}:{ST.get('sched_seq', 0)}")
    if blk and S_ORDER and SCHED.get("stall") and ST["sched_pass"] in S_PASSES:
        # the insn the wanted order has next is not ready (it waits in the queue for a
        # latency): end the cycle instead of issuing a later one before it
        left = [u for u in blk if u in S_ORDER and u not in ST["issued"]]
        w = min(left, key=S_ORDER.get) if left else None
        if w is not None and w not in uids and ST["stalls"].get(w, 0) < 4 and any(u in S_ORDER for u in uids):
            ST["stalls"][w] = ST["stalls"].get(w, 0) + 1
            if mid:
                gdb.execute("set var can_issue_more = 0")
            else:
                ST["rate"] = I(ev("issue_rate"))
                gdb.execute("set var issue_rate = 0")
            step["stall"] = w
            step["forced"] = w
            try:
                tick = I(ev(f"h_i_d[{w}].tick" if has("h_i_d") else f"insn_tick[{w}]"))
                clock = I(ev("clock_var")) if has("clock_var") else None
                step["rank"] = {"natural": rank_inputs(ptrs[-1], uids[-1]), "wanted": {"uid": w, "tick": tick},
                                "decided_by": "not ready",
                                "text": f"insn {w} is not ready: it waits in the queue for a latency (its tick is {tick}"
                                        + (f", the clock {clock}" if clock is not None else "") + "), or on an insn not issued yet"}
            except Exception as e:
                step["rank"] = {"error": f"{type(e).__name__}: {e}"[:120]}
        elif w is not None and w not in uids and ST["stalls"].get(w, 0) == 4:
            # waiting did not help: the wanted insn depends on one the order has after it
            ST["stalls"][w] = 5
            try:
                step["blocked"] = {"want": w, "by": waiting_for(ptrs[-1], w, set(ST["issued"]))}
            except Exception as e:
                step["blocked"] = {"want": w, "by": [], "error": str(e)[:80]}
    if SCHED.get("trace") or "forced" in step or "blocked" in step:
        OUT["functions"].setdefault(fn, {"local": [], "global": [], "sched": [], "forced": [], "failed": []})["sched"].append(step)


def waiting_for(near, uid, issued):
    """[[insn uid, kind]]: the insns `uid` depends on (its LOG_LINKS, as the scheduler built
    them) that have not been issued. The insn is looked for along the chain around `near`."""
    found = None
    for step_field in (2, 1):
        p, n = near, 0
        while p and n < 4000 and found is None:
            if uid_of(p) == uid:
                found = p
            p, n = fld(p, step_field), n + 1
    if found is None:
        return []
    kinds = {}
    for name in ("REG_DEP_ANTI", "REG_DEP_OUTPUT"):
        try:
            kinds[int(ev(f"(int){name}"))] = "anti" if name.endswith("ANTI") else "output"
        except gdb.error:
            pass
    out, link, n = [], fld(found, 5), 0
    while link and n < 200:
        dep = fld(link, 0)
        mode = (u32(link) >> 16) & 0xFF
        if uid_of(dep) not in issued:
            out.append([uid_of(dep), kinds.get(mode, "data")])
        link, n = fld(link, 1), n + 1
    return out


def list_len(ptr):
    n = 0
    while ptr and n < 10000:
        ptr, n = fld(ptr, 1), n + 1
    return n


def rank_inputs(ptr, uid):
    """What rank_for_schedule compares for one ready insn: its priority (the longest latency
    path from it to the end of the block), the number of insns that depend on it, its place
    in the original order (luid), its register weight (first pass only), and how it is tied
    to the insn issued just before (none, data, anti, output)."""
    if has("h_i_d"):
        get = lambda name: ev(f"h_i_d[{uid}].{name}")
        depend, names = "depend", {"priority": "priority", "luid": "luid", "weight": "reg_weight", "tick": "tick"}
    else:
        get = lambda name: ev(f"insn_{name}[{uid}]")
        depend, names = "depend", {"priority": "priority", "luid": "luid", "weight": "reg_weight", "tick": "tick"}
    out = {"uid": uid}
    for key, name in names.items():
        try:
            out[key] = I(get(name))
        except gdb.error:
            pass
    try:
        out["dependents"] = list_len(I(get(depend)) & 0xFFFFFFFF)
    except gdb.error:
        pass
    out["after_last"] = "none"
    try:
        last = I(ev("(int)last_scheduled_insn")) & 0xFFFFFFFF
        if last:
            out["last"] = uid_of(last)
            anti, outp = int(ev("(int)REG_DEP_ANTI")), int(ev("(int)REG_DEP_OUTPUT"))
            lu = uid_of(last)
            link = I(ev(f"(int)h_i_d[{lu}].depend" if has("h_i_d") else f"(int)insn_depend[{lu}]")) & 0xFFFFFFFF
            n = 0
            while link and n < 2000:
                if fld(link, 0) == ptr:
                    mode = (u32(link) >> 16) & 0xFF
                    out["after_last"] = "anti" if mode == anti else "output" if mode == outp else "data"
                    break
                link, n = fld(link, 1), n + 1
    except gdb.error:
        pass
    return out


def decided(nat, want, first_pass, mid):
    """The first comparison of rank_for_schedule on which the insn this compile issues beats the
    one the original issues (the order of the comparisons is that of gcc's haifa-sched.c)."""
    if mid:
        return "no sort", ("the insns the last issue made ready are taken in the same cycle, before the list is sorted "
                           "again: the last one of that insn's dependents list goes first")
    if nat.get("priority") != want.get("priority"):
        return "priority", f"priority {nat.get('priority')} against {want.get('priority')}"
    if first_pass and nat.get("weight") != want.get("weight"):
        return "register weight", f"register weight {nat.get('weight')} against {want.get('weight')}"
    cls = lambda r: 2 if r.get("after_last") in ("anti", "output") else 3
    if cls(nat) != cls(want):
        return "tie to the last issued insn", (f"the insn issued just before is insn {nat.get('last')}: this one is "
                                               f"{nat.get('after_last')}-dependent on it, the other {want.get('after_last')}")
    if nat.get("dependents") != want.get("dependents"):
        return "dependents", f"{nat.get('dependents')} insns depend on it against {want.get('dependents')}"
    return "source order", f"equal on priority and dependents: the earlier insn of the source goes first (luid {nat.get('luid')} against {want.get('luid')})"


def on_sched_reorder():
    """The target's reorder hook (mips_sched_reorder (dump, sched_verbose, ready, n_ready)) runs
    once per cycle on the sorted ready list."""
    steer(arg(2) & 0xFFFFFFFF, arg(3), False)


def on_schedule_insn_return():
    """Back in schedule_block from schedule_insn (insn, ready, n_ready, clock): the insns it made
    ready are at the end of the list and, where the issue loop takes ready[--n_ready] (gcc 2.96),
    the next one leaves in the same cycle without the reorder hook seeing it."""
    fn = ST.get("sched_fn")
    if fn is None or (WANT is not None and fn != WANT):
        return
    uid = uid_of(u32(I(ev("$esp")) & 0xFFFFFFFF))
    ST.setdefault("issued", []).append(uid)
    if SCHED.get("trace"):
        r = OUT["functions"].setdefault(fn, {"local": [], "global": [], "sched": [], "forced": [], "failed": []})
        r.setdefault("sched_blocks", {}).setdefault(f"{ST['sched_pass']}:{ST.get('sched_seq', 0)}", []).append(uid)
    steer(I(ev("ready")) & 0xFFFFFFFF, I(ev("$eax")), True)


# ------------------------------------------------------------------ delay slots (reorg)

FLAG = {}       # rtx flag name -> bit in the first word
KIND = {}       # rtx code -> one letter
FLD = [4]       # sizeof (rtunion): 8 where the compiler was built with a 64-bit HOST_WIDE_INT


def mem(addr, n):
    return bytes(gdb.selected_inferior().read_memory(addr & 0xFFFFFFFF, n))


def u32(addr):
    return struct.unpack("<I", mem(addr, 4))[0]


def uid_of(ptr):
    """INSN_UID of an insn, label or note; None for a null pointer."""
    ptr &= 0xFFFFFFFF
    return struct.unpack("<i", mem(ptr + UID_OFFSET, 4))[0] if ptr else None


def fld(ptr, n):
    """XEXP (ptr, n) as an address."""
    return u32((ptr & 0xFFFFFFFF) + UID_OFFSET + n * FLD[0])


def flag(ptr, name):
    return (u32(ptr) >> FLAG[name]) & 1


def top(n):
    """n-th argument seen from a function's first instruction or from its `ret`."""
    return u32((I(ev("$esp")) & 0xFFFFFFFF) + 4 + 4 * n)


def rets(fn):
    if ("ret", fn) in ADDRS:
        return ADDRS["ret", fn]
    out = []
    for line in gdb.execute(f"disassemble {fn}", to_string=True).splitlines():
        parts = line.split()
        if len(parts) >= 3 and parts[0].startswith("0x") and "ret" in parts[2:4]:
            out.append(int(parts[0].rstrip(":"), 16))
    ADDRS["ret", fn] = out
    return out


def dbr():
    return ST.get("dbr_fn") is not None and (WANT is None or ST["dbr_fn"] == WANT)


def reorg_rec():
    r = OUT["functions"].setdefault(ST["dbr_fn"], {"local": [], "global": [], "sched": [], "forced": [], "failed": []})
    return r.setdefault("reorg", {"before": [], "fills": [], "threads": [], "live": [], "predict": [], "trials": [],
                                  "events": [], "blocked": [], "forced": []})


def on_dbr_schedule():
    ST["dbr_fn"] = fn_name()
    ST["phase"] = "start"
    ST["B"] = None
    ST["thread"] = None
    ST["live_stack"] = []
    ST["seen_live"] = set()
    if not dbr() or not R_TRACE:
        return
    chain, p, n = [], arg(0) & 0xFFFFFFFF, 0
    while p and n < 50000:
        code = struct.unpack("<H", mem(p, 2))[0]
        if code in KIND:
            chain.append([uid_of(p), KIND[code]])
        p, n = fld(p, 2), n + 1
    reorg_rec()["before"] = chain


def on_phase(name):
    def hook():
        if dbr():
            n = I(ev("reorg_pass_number")) if has("reorg_pass_number") else 0
            ST["phase"] = f"{name}{arg(0) if name == 'simple' else ''}.{n}"
            ST["B"] = None
            ST["thread"] = None
    return hook


def on_get_jump_flags():
    if dbr():
        ST["B"] = uid_of(arg(0))


def on_fill_slots_from_thread():
    if not dbr():
        return
    insn, cond, thread, opp, likely, if_true, own = (arg(i) & 0xFFFFFFFF for i in range(7))
    t = {"phase": ST["phase"], "insn": uid_of(insn), "thread": uid_of(thread), "opposite": uid_of(opp), "likely": likely,
         "if_true": if_true, "own": own, "unconditional": int(cond == (I(ev("const_true_rtx")) & 0xFFFFFFFF))}
    ST["thread"] = t
    ST["B"] = t["insn"]
    try:
        ST["opp_ptr"] = I(ev("&opposite_needed")) & 0xFFFFFFFF
    except gdb.error:
        ST["opp_ptr"] = None
    if R_TRACE:
        reorg_rec()["threads"].append(t)


def on_emit_delay_sequence():
    if not dbr() or not R_TRACE:
        return
    insn, lst = arg(0) & 0xFFFFFFFF, arg(1) & 0xFFFFFFFF
    slots = []
    while lst and len(slots) < 8:
        x = fld(lst, 0)
        slots.append({"uid": uid_of(x), "from_target": flag(x, "in_struct")})
        lst = fld(lst, 1)
    fill = {"phase": ST["phase"], "insn": uid_of(insn), "slots": slots, "annul": flag(insn, "unchanging")}
    t = ST.get("thread")
    if t and t["insn"] == fill["insn"] and t["phase"] == ST["phase"]:
        fill["thread"] = {k: t[k] for k in ("thread", "opposite", "if_true", "own", "likely")}
    reorg_rec()["fills"].append(fill)


def on_live_enter():
    if dbr():
        ST["live_stack"].append({"target": uid_of(arg(1)), "stops": []})


def on_live_return():
    if not dbr():
        return
    cur = ST["live_stack"].pop() if ST["live_stack"] else {"target": uid_of(top(1)), "stops": []}
    t = cur["target"]
    if t is None:
        return
    v = ev(f"((struct resources *){top(2)})->regs")
    live = hset(v)
    if t in R_LIVE:
        add, remove = R_LIVE[t]
        new = live
        for h in add:
            new |= 1 << h
        for h in remove:
            new &= ~(1 << h)
        if new != live:
            write_hset(v, new)
            reorg_rec()["forced"].append(["live", t, sorted(bits(new & ~live)), sorted(bits(live & ~new))])
            live = new
    if R_TRACE:
        key = (t, live, ST["B"], tuple(cur["stops"]))
        if key not in ST["seen_live"]:
            ST["seen_live"].add(key)
            reorg_rec()["live"].append({"target": t, "live": bits(live), "for": ST["B"], "phase": ST["phase"],
                                        "stops": cur["stops"]})


def on_scan_can_throw():
    """Right after find_dead_or_set_registers asked can_throw (insn): a yes ends the scan there."""
    if not dbr() or I(ev("$eax")) == 0:
        return
    uid = uid_of(u32(I(ev("$esp")) & 0xFFFFFFFF))
    if R_NOTHROW is True or (R_NOTHROW and uid in R_NOTHROW):
        gdb.execute("set var $eax = 0")
        if ["nothrow", uid] not in reorg_rec()["forced"]:
            reorg_rec()["forced"].append(["nothrow", uid])
    elif ST["live_stack"] and uid not in ST["live_stack"][-1]["stops"]:
        ST["live_stack"][-1]["stops"].append(uid)


def on_mostly_true_jump_return():
    if not dbr():
        return
    uid, value = uid_of(top(0)), I(ev("$eax"))
    if uid in R_PREDICT and R_PREDICT[uid] != value:
        gdb.execute(f"set var $eax = {R_PREDICT[uid]}")
        reorg_rec()["forced"].append(["predict", uid, value, R_PREDICT[uid]])
        value = R_PREDICT[uid]
    if R_TRACE:
        reorg_rec()["predict"].append([uid, value])


def on_eligible_return(kind):
    def hook():
        if not dbr():
            return
        b, x, ok = uid_of(top(0)), uid_of(top(2)), I(ev("$eax"))
        if ok and ((b, x) in R_REJECT or (b in R_TAKE and R_TAKE[b] != x)):
            gdb.execute("set var $eax = 0")
            reorg_rec()["forced"].append(["reject" if (b, x) in R_REJECT else "take", b, x, kind])
            ok = 0
        if R_TRACE:
            reorg_rec()["trials"].append([ST["phase"], b, x, kind, ok])
    return hook


def on_resource_return(kind):
    """insn_sets_resource_p / insn_references_resource_p (insn, res, delayed) said yes: the
    candidate conflicts. Against `opposite_needed` that is the reason to annul."""
    def hook():
        if not dbr() or I(ev("$eax")) == 0:
            return
        x, res = uid_of(top(0)), top(1)
        what = "needed at the opposite thread" if res == ST.get("opp_ptr") else kind
        row = [ST["phase"], ST["B"], x, what]
        if row not in reorg_rec()["blocked"][-6:]:
            reorg_rec()["blocked"].append(row)
    return hook


def on_event(name, nargs):
    def hook():
        if dbr():
            reorg_rec()["events"].append([ST["phase"], name] + [uid_of(top(i)) for i in range(nargs)])
    return hook


def install_reorg():
    t = gdb.lookup_type("struct rtx_def")
    FLAG.update({f.name: f.bitpos for f in t.fields() if f.bitsize == 1})
    for name, letter in (("INSN", "i"), ("JUMP_INSN", "j"), ("CALL_INSN", "c"), ("CODE_LABEL", "L"), ("BARRIER", "B")):
        KIND[int(ev(f"(int){name}"))] = letter
    Stop("dbr_schedule", on_dbr_schedule)
    Stop("fill_simple_delay_slots", on_phase("simple"))
    Stop("fill_eager_delay_slots", on_phase("eager"))
    Stop("relax_delay_slots", on_phase("relax"))
    Stop("fill_slots_from_thread", on_fill_slots_from_thread)
    if R_TRACE:
        Stop("get_jump_flags", on_get_jump_flags)
        Stop("emit_delay_sequence", on_emit_delay_sequence)
        for name, nargs in (("try_merge_delay_insns", 2), ("delete_from_delay_slot", 1), ("reorg_redirect_jump", 2),
                            ("optimize_skip", 1), ("steal_delay_list_from_target", 1), ("steal_delay_list_from_fallthrough", 1),
                            ("delete_scheduled_jump", 1), ("make_return_insns", 0)):
            try:
                gdb.execute(f"info address {name}", to_string=True)
            except gdb.error:
                continue
            Stop(f"*{name}", on_event(name, nargs))
    if R_TRACE or R_LIVE:
        Stop("mark_target_live_regs", on_live_enter)
        for a in rets("mark_target_live_regs"):
            Stop(f"*{a:#x}", on_live_return)
    if R_TRACE == "full" or R_NOTHROW:
        for a in call_returns("find_dead_or_set_registers", "can_throw"):
            Stop(f"*{a:#x}", on_scan_can_throw)
    if R_TRACE or R_PREDICT:
        for a in rets("mostly_true_jump"):
            Stop(f"*{a:#x}", on_mostly_true_jump_return)
    if R_TRACE or R_REJECT or R_TAKE:
        for name in ("eligible_for_delay", "eligible_for_annul_false", "eligible_for_annul_true"):
            try:
                addrs = rets(name)
            except gdb.error:
                continue
            for a in addrs:
                Stop(f"*{a:#x}", on_eligible_return(name[len("eligible_for_"):]))
    if R_TRACE == "full":
        for name, kind in (("insn_sets_resource_p", "sets something set or needed after it"),
                           ("insn_references_resource_p", "uses something set after it")):
            for a in rets(name):
                Stop(f"*{a:#x}", on_resource_return(kind))


def call_returns(fn, callee):
    """Addresses right after each `call callee` inside fn."""
    if (fn, callee) in ADDRS:
        return ADDRS[fn, callee]
    out = []
    lines = gdb.execute(f"disassemble {fn}", to_string=True).splitlines()
    for i, line in enumerate(lines[:-1]):
        if "call" in line and f"<{callee}>" in line:
            nxt = lines[i + 1].split()
            addr = nxt[0] if nxt[0].startswith("0x") else nxt[1]
            out.append(int(addr.rstrip(":"), 16))
    ADDRS[fn, callee] = out
    return out


def run_once(cfg):
    """One compile under one configuration: breakpoints, run, the record written to cfg["out"].
    With cfg["argv"] the compiler's arguments are set first (a gdb kept for several compiles)."""
    global FIRST_PSEUDO
    configure(cfg)
    for b in BPS:
        try:
            b.delete()
        except RuntimeError:
            pass
    del BPS[:]
    # the first pseudo: hard registers, then the virtual registers (five in gcc 2.9x)
    FIRST_PSEUDO = I(ev("sizeof(reg_alloc_order) / sizeof(reg_alloc_order[0])")) + 5 if has("reg_alloc_order") \
        else I(ev("sizeof(reg_names) / sizeof(reg_names[0])")) + 5
    OUT["first_pseudo"] = FIRST_PSEUDO
    FLD[0] = I(ev("sizeof (rtunion)"))
    OUT["layout"] = {"qty_struct": QTY_STRUCT, "allocno_struct": ALLOCNO_STRUCT}
    want_alloc = TRACE != "none" or F_ALLOC
    if want_alloc:
        Stop("local_alloc", on_local_alloc)
        Stop("block_alloc", on_block_alloc)
        Stop("find_free_reg", on_find_free_reg)
        if UNTIE:
            RTX.update(REG=int(ev("(int)REG")), SUBREG=int(ev("(int)SUBREG")))
            Stop("*combine_regs", on_combine_regs)
        for a in call_returns("block_alloc", "find_free_reg"):
            Stop(f"*{a:#x}", on_find_free_reg_return)
        Stop("global_alloc", on_global_alloc)
        Stop("global.c:find_reg", on_find_reg)
    Stop("reload", on_reload)
    if SCHED:
        Stop("schedule_insns", on_schedule_insns)
        Stop("schedule_block", on_schedule_block)
        Stop("mips_sched_reorder", on_sched_reorder)
        version = ev("version_string").string() if has("version_string") else ""
        OUT["version"] = version
        if SCHED.get("every_pick", True) and not version.startswith("2.9-"):
            for a in call_returns("schedule_block", "schedule_insn"):
                Stop(f"*{a:#x}", on_schedule_insn_return)
    if REORG:
        try:
            install_reorg()
        except Exception as e:
            OUT["errors"].append(f"reorg hooks: {type(e).__name__}: {e}")
    try:
        if "argv" in cfg:
            gdb.execute("set args " + " ".join(shlex.quote(x) for x in cfg["argv"])
                        + " < /dev/null > " + shlex.quote(cfg["stdout"]) + " 2>&1")
        gdb.execute("run", to_string="argv" in cfg)
    except gdb.error as e:
        OUT["errors"].append(f"run: {e}")
    for f in OUT["functions"].values():
        for c in f["global"]:
            c.pop("_pseudo", None)
    with open(CFG["out"], "w") as f:
        json.dump(OUT, f)


def main():
    if "ORACLE_CFG" in os.environ:
        run_once(json.load(open(os.environ["ORACLE_CFG"])))
        return
    # kept alive by tools/oracle/orc_core.py: one configuration file per line on stdin, one
    # line on stdout when its compile is over. Starting gdb and reading the compiler's symbols
    # costs more than the compile it watches.
    while True:
        line = sys.stdin.readline()
        if not line or line.strip() == "quit":
            break
        try:
            run_once(json.load(open(line.strip())))
            answer = "ok"
        except Exception as e:
            answer = f"error {type(e).__name__}: {e}".replace("\n", " ")[:300]
        sys.stdout.write("ORACLE-DONE " + answer + "\n")
        sys.stdout.flush()


main()
