"""The decision oracle: compile a draft with Sony's compiler under gdb, read the allocation
decisions, override them, and say which ones separate the draft from the original function.

A Session is one draft judged as one function. It works in a private temporary directory and
never writes into the project except the JSON its caller asks for. A forced compile is a
certificate about the draft's logic; it is never a match and nothing here saves a source.
"""
import collections
import difflib
import glob
import hashlib
import json
import os
import re
import select
import shlex
import shutil
import signal
import struct
import subprocess
import sys
import tempfile
import time

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
ROOT = os.path.dirname(TOOLS)
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)
if HERE not in sys.path:
    sys.path.insert(0, HERE)

import match  # noqa: E402
import project  # noqa: E402
import orc_rtl as R  # noqa: E402

GDB_HOOK = os.path.join(HERE, "orc_gdb.py")
HOME = os.path.expanduser("~")
DIFFER = re.compile(r"(\d+) of (\d+) instructions differ")
STUB = '#!/usr/bin/env python3\nimport sys, json, os\njson.dump(sys.argv, open(os.environ["ORACLE_ARGV"], "w"))\n'
SERVER = True       # one gdb per session, kept for all its compiles (orc_gdb.py's loop)
MAX_ROUNDS = 8
MAX_DECISIONS = 12


class OracleError(Exception):
    pass


def sh(argv, cwd, timeout=180, env=None):
    try:
        return subprocess.run(argv, cwd=cwd, capture_output=True, text=True, timeout=timeout, env=env, errors="replace")
    except subprocess.TimeoutExpired:
        raise OracleError(f"timeout: {' '.join(argv[:3])}")


_INCLUDE = []


def include_cache():
    """One copy of include/ per content stamp under /tmp, as tools/include_wsl.sh keeps it (the
    old 32-bit compilers cannot stat files on a Windows drive)."""
    # the stamp stats every header on the Windows drive (0.8 s): once a minute per process is enough
    now = time.time()
    if _INCLUDE and now - _INCLUDE[0] < 60 and os.path.isdir(_INCLUDE[1]):
        return _INCLUDE[1]
    root = os.path.join(os.environ.get("TMPDIR") or "/tmp", "include_cache")
    cache = os.path.join(root, f"{os.path.basename(ROOT)}_{project.include_stamp()}")
    _INCLUDE[:] = [now, cache]
    if not os.path.isdir(cache):
        os.makedirs(root, exist_ok=True)
        tmp = tempfile.mkdtemp(prefix=os.path.basename(cache) + ".", dir=root)
        shutil.copytree(project.INCLUDE, tmp, dirs_exist_ok=True)
        try:
            os.rename(tmp, cache)
        except OSError:
            shutil.rmtree(tmp, ignore_errors=True)
    return cache


def digest(path):
    return hashlib.sha1(open(path, "rb").read()).hexdigest()[:16]


def differ(report):
    """Differing instructions in a judge report: 0 on MATCH, None when there is no listing."""
    first = report.split("\n")[0]
    if ": MATCH" in first:
        return 0
    m = DIFFER.search(first)
    return int(m.group(1)) if m else None


def columns(report):
    left, right = [], []
    for line in report.split("\n")[1:]:
        if "|" not in line or line[:2] not in ("  ", "! "):
            continue
        a, b = line[2:].split("|", 1)
        a, b = " ".join(a.split()), " ".join(re.sub(r"\s+<[^>]*>\s*$", "", b).split())
        if a != "-":
            left.append(a)
        if b != "-":
            right.append(b)
    return left, right


_REG = re.compile(r"\$[a-z0-9]+")
_LIKELY = {"beql": "beq", "bnel": "bne", "bgezl": "bgez", "bltzl": "bltz", "blezl": "blez", "bgtzl": "bgtz",
           "bc1tl": "bc1t", "bc1fl": "bc1f", "beqzl": "beqz", "bnezl": "bnez"}


_COMMUTATIVE = {"add", "addu", "dadd", "daddu", "and", "or", "xor", "nor", "mult", "multu", "mult1", "multu1",
                "add.s", "mul.s", "c.eq.s", "beq", "bne", "beql", "bnel", "madd", "maddu", "madd.s", "mula.s", "adda.s"}


def commuted(a, b):
    """Two listing lines that are one commutative instruction with its two sources exchanged."""
    ta, tb = a.replace(",", " ").split(), b.replace(",", " ").split()
    if len(ta) != len(tb) or ta[0] != tb[0] or ta[0] not in _COMMUTATIVE or a == b:
        return False
    if ta[0].startswith(("beq", "bne")):
        return len(ta) >= 3 and ta[1] == tb[2] and ta[2] == tb[1] and ta[3:] == tb[3:]
    if len(ta) == 4:
        return ta[1] == tb[1] and ta[2] == tb[3] and ta[3] == tb[2]
    return len(ta) == 3 and ta[1] == tb[2] and ta[2] == tb[1]


def swaps(report):
    """The differing rows of a judge report as (index, original, mine) if every one of them is a
    commutative instruction with exchanged operands, else None."""
    left, right = columns(report)
    if len(left) != len(right):
        return None
    diffs = [(i, a, b) for i, (a, b) in enumerate(zip(left, right)) if a != b]
    return diffs if diffs and all(commuted(a, b) for _, a, b in diffs) else None


def classify(report):
    """What differs in a judge listing (the classes of the research pass, build/research/e4):
    match, reg_only, likely, likely+reg, imm, order, order_reg, order_reg_imm, mixed, length."""
    if differ(report) == 0:
        return "match"
    left, right = columns(report)
    if not left or not right:
        return "nocode"
    mnem = lambda s: s.split()[0]
    base = lambda s: {"beqz": "beq", "bnez": "bne"}.get(_LIKELY.get(mnem(s), mnem(s)), _LIKELY.get(mnem(s), mnem(s)))
    shape = lambda s: _REG.sub("$r", s)
    if len(left) == len(right):
        diffs = [(a, b) for a, b in zip(left, right) if a != b]
        if all(commuted(a, b) for a, b in diffs):
            return "operand_order"
        if collections.Counter(left) == collections.Counter(right):
            return "order"
        if all(mnem(a) == mnem(b) and shape(a) == shape(b) for a, b in diffs):
            return "reg_only"
        # a branch against its likely form, alone or with registers: at least one mnemonic differs,
        # and nothing else than registers does (an immediate that differs is not this class)
        if any(mnem(a) != mnem(b) for a, b in diffs) and all(base(a) == base(b) for a, b in diffs) and all(
                shape(re.sub(r"^\S+", "", a).replace(", $zero", "")) == shape(re.sub(r"^\S+", "", b).replace(", $zero", ""))
                for a, b in diffs):
            return "likely" if all(mnem(a) != mnem(b) for a, b in diffs) else "likely+reg"
        if all(mnem(a) == mnem(b) for a, b in diffs) and all(_REG.findall(a) == _REG.findall(b) for a, b in diffs):
            return "imm"
        if collections.Counter(left) == collections.Counter(right):
            return "order"
        if collections.Counter(map(shape, left)) == collections.Counter(map(shape, right)):
            return "order_reg"
        if collections.Counter(map(mnem, left)) == collections.Counter(map(mnem, right)):
            return "order_reg_imm"
        return "mixed"
    if collections.Counter(map(base, left)) == collections.Counter(map(base, right)):
        return "order_reg"
    return "length"


# words: [(offset, raw word, insn uid)]; linked: the words as the linker would leave them, a
# reference the judge cannot resolve (a string literal, a local label) taking the original's
# value where an instruction of the original is the same but for that reference; wild: the
# indices of those words
Listing = collections.namedtuple("Listing", "words fname foff linked wild", defaults=((),))


class Session:
    def __init__(self, addr, src, keep=False):
        self.addr = addr
        self.src = os.path.abspath(src)
        self.keep = keep
        self.ext = os.path.splitext(src)[1]
        self.base = "t" + self.ext
        self.work = tempfile.mkdtemp(prefix="oracle_")
        self.n_gdb = 0
        try:
            shutil.copy(self.src, os.path.join(self.work, self.base))
            os.symlink(include_cache(), os.path.join(self.work, "include"))
            self.profile = project.source_compiler(self.src)
            toks = shlex.split(project.compiler_command(self.profile).replace("$HOME", HOME))
            self.as_path = None
            if toks[0] == "bash" and "cc_as.sh" in toks[1]:
                self.as_path, toks = toks[2], shlex.split(toks[3])
            self.gcc = [t for t in toks if t != "-c"]
            self.env = dict(os.environ, CPATH=os.path.join(self.work, "include"))
            self.argv = self._cc1_argv()
            text_addr, text = match.load_text()
            self.target = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
            while len(self.target) > 2 and self.target[-1] == 0 and self.target[-2] == 0:
                self.target.pop()
            self._text = (text_addr, text)
        except BaseException:
            self.close()
            raise

    def close(self):
        self._stop_gdb()
        if not self.keep:
            shutil.rmtree(self.work, ignore_errors=True)

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        self.close()

    # ------------------------------------------------------------ compiler

    def _cc1_argv(self):
        """The command line the driver gives its compiler proper, taken by putting a stub named
        cc1plus / cc1 first on the driver's program path: works for any gcc driver."""
        stub = os.path.join(self.work, "stub")
        os.makedirs(stub)
        for name in ("cc1plus", "cc1"):
            with open(os.path.join(stub, name), "w") as f:
                f.write(STUB)
            os.chmod(os.path.join(stub, name), 0o755)
        out = os.path.join(self.work, "argv.json")
        r = sh([self.gcc[0], "-B", stub + "/"] + self.gcc[1:] + ["-S", "-dp", self.base, "-o", "stub.s"], self.work,
               env=dict(self.env, ORACLE_ARGV=out))
        if not os.path.exists(out):
            raise OracleError("the driver did not call its compiler: " + (r.stdout + r.stderr)[-300:])
        argv = json.load(open(out))
        name = os.path.basename(argv[0])
        real = sh([self.gcc[0]] + [t for i, t in enumerate(self.gcc[1:]) if t == "-B" or (i and self.gcc[i] == "-B")]
                  + [f"-print-prog-name={name}"], self.work, env=self.env).stdout.strip()
        if not os.path.isfile(real):
            raise OracleError(f"cannot find {name}: {real!r}")
        clean, skip = [real], 0
        for i, a in enumerate(argv[1:], 1):
            if skip:
                skip -= 1
            elif a == "-isystem" and i + 1 < len(argv) and argv[i + 1].startswith(stub):
                skip = 1
            else:
                clean.append(a)
        return clean

    def compile(self, tag, cfg=None, dumps=()):
        """Run the compiler proper: output TAG.s, dumps TAG.NN.pass. With cfg, under gdb with the
        hook; returns what the hook recorded."""
        argv = list(self.argv)
        argv[argv.index("-dumpbase") + 1] = tag
        argv[-1] = tag + ".s"
        argv[-2:-2] = list(dumps)
        out_s = os.path.join(self.work, tag + ".s")
        if os.path.exists(out_s):
            os.remove(out_s)
        trace = {}
        if cfg is None:
            r = sh(argv, self.work, env=self.env)
        else:
            cfg_path = os.path.join(self.work, tag + ".cfg.json")
            out = os.path.join(self.work, tag + ".trace.json")
            if os.path.exists(out):
                os.remove(out)
            self.n_gdb += 1
            if SERVER:
                said = os.path.join(self.work, tag + ".out")
                json.dump(dict(cfg, out=out, argv=argv[1:], stdout=said), open(cfg_path, "w"))
                self._serve(cfg_path, argv[0])
                text = open(said, errors="replace").read() if os.path.exists(said) else ""
                r = subprocess.CompletedProcess(argv, 0, "", text)
            else:
                json.dump(dict(cfg, out=out), open(cfg_path, "w"))
                r = sh(["gdb", "-q", "-batch", "-nx", "-x", GDB_HOOK, "--args"] + argv, self.work,
                       env=dict(self.env, ORACLE_CFG=cfg_path))
            if os.path.exists(out):
                trace = json.load(open(out))
        if not os.path.exists(out_s) or os.path.getsize(out_s) == 0 or (cfg is None and r.returncode != 0):
            raise OracleError("compile failed: " + (r.stderr or r.stdout)[-400:].strip())
        return trace

    def _serve(self, cfg_path, compiler, timeout=180):
        """One compile by the gdb this session keeps (orc_gdb.py's loop): starting gdb and
        reading the compiler's symbols costs more than the compile, and a report needs dozens."""
        p = getattr(self, "_gdb", None)
        if p is None or p.poll() is not None:
            env = {k: v for k, v in self.env.items() if k != "ORACLE_CFG"}
            p = self._gdb = subprocess.Popen(["gdb", "-q", "-batch", "-nx", "-x", GDB_HOOK, compiler], cwd=self.work, env=env,
                                             stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
                                             start_new_session=True)
            self._said = b""
        try:
            p.stdin.write((cfg_path + "\n").encode())
            p.stdin.flush()
        except OSError:
            self._stop_gdb()
            raise OracleError("gdb is gone")
        end = time.time() + timeout
        while True:
            while b"\n" in self._said:
                line, self._said = self._said.split(b"\n", 1)
                if line.startswith(b"ORACLE-DONE"):
                    if b"error" in line[:20]:
                        raise OracleError("hook: " + line.decode(errors="replace")[12:200])
                    return
            ready, _, _ = select.select([p.stdout], [], [], max(0.0, end - time.time()))
            chunk = os.read(p.stdout.fileno(), 65536) if ready else b""
            if not chunk:
                self._stop_gdb()
                raise OracleError("timeout: gdb" if not ready else "gdb ended")
            self._said += chunk

    def _stop_gdb(self):
        p = getattr(self, "_gdb", None)
        self._gdb = None
        if p is None:
            return
        try:
            p.stdin.close()
        except OSError:
            pass
        try:
            p.wait(timeout=0.5 if p.poll() is None else 0)
        except subprocess.TimeoutExpired:
            try:
                os.killpg(p.pid, signal.SIGKILL)     # its own session: gdb and the compiler under it, nothing else
            except OSError:
                pass
            p.wait()
        p.stdout.close()

    def assemble(self, tag):
        lst = tag + ".lst"
        if self.as_path:
            argv = [self.as_path, "-EL", "-march=r5900", "-mabi=eabi", tag + ".s", "-o", tag + ".o", f"-al={lst}"]
        else:
            argv = self.gcc + ["-c", f"-Wa,-al={lst}", tag + ".s", "-o", tag + ".o"]
        r = sh(argv, self.work, env=self.env)
        obj = os.path.join(self.work, tag + ".o")
        if r.returncode != 0 or not os.path.exists(obj):
            raise OracleError("assemble failed: " + r.stderr[-300:])
        blob, srelocs, funcs = match.read_object(obj, want_symbols=True)
        if not funcs:
            raise OracleError("no function in the object")
        fname, foff, fsize = funcs[0]
        fsize = max(fsize, len(blob) - foff)
        ws = match.trim_padding(list(struct.unpack_from(f"<{fsize // 4}I", blob, foff)))
        uid_at = R.listing_uids(os.path.join(self.work, lst))
        linked, unresolved = match.link_words(ws, srelocs, foff, self.addr)
        wild = self.adopt(linked, {(off - foff) // 4: srelocs[off][0] for off in unresolved if 0 <= (off - foff) // 4 < len(ws)})
        return Listing([(foff + 4 * i, w, uid_at.get(foff + 4 * i)) for i, w in enumerate(ws)], fname, foff, linked, wild)

    def adopt(self, linked, loose):
        """A word whose reference cannot be checked ({index: relocation type}: a string literal
        of the draft's own, a local label) is given the value of the original's instruction
        that equals it but for the reference, the nearest one not taken yet. Without this every
        such word looks like an instruction the original has not, and a draft that only names
        its strings would never be compared. The judge decides alone whether a compile matches."""
        target = self.padded(len(linked))
        taken = set()
        field = lambda rtype: 0x3FFFFFF if rtype == match.R_MIPS_26 else 0xFFFF
        for exact in (True, False):     # the same registers first, then whatever the registers
            for i in sorted(loose):
                if i in taken:
                    continue
                keep = ~field(loose[i]) & 0xFFFFFFFF
                same = (lambda t: match.same_ignoring_reloc(t, linked[i], loose[i])) if exact else \
                    (lambda t: R.skeleton(t & keep) == R.skeleton(linked[i] & keep))
                near = sorted((abs(j - i), j) for j, t in enumerate(target) if ("t", j) not in taken and same(t))
                if near:
                    taken.update({i, ("t", near[0][1])})
                    linked[i] = (linked[i] & keep) | (target[near[0][1]] & field(loose[i]))
        return tuple(sorted(loose))

    def judge(self, tag):
        """The project's judge on TAG.o (never on anything else): (ok, report)."""
        os.makedirs(os.path.join(ROOT, "build", "obj"), exist_ok=True)
        obj = os.path.join(ROOT, "build", "obj", f"oracle_{os.getpid()}_{os.path.basename(self.work)}_{tag}.o")
        shutil.copy(os.path.join(self.work, tag + ".o"), obj)
        try:
            return match.judge(self.addr, self.src, obj=obj)
        except SystemExit as e:
            return False, str(e)
        finally:
            if os.path.exists(obj):
                os.remove(obj)

    def dump(self, tag, name, fname=None):
        """One function's section of the dump of pass `name` (lreg, greg, rtl, sched, sched2...)."""
        # gcc 2.96 numbers its dumps (t.19.lreg), gcc 2.9 does not (t.lreg)
        paths = glob.glob(os.path.join(self.work, f"{glob.escape(tag)}.*.{name}")) or \
            glob.glob(os.path.join(self.work, f"{glob.escape(tag)}.{name}"))
        if not paths:
            return ""
        parts = R.split_functions(open(paths[0], errors="replace").read())
        if not parts:
            return ""
        fname = fname or self.fname
        names = R.asm_functions(os.path.join(self.work, tag + ".s"))
        if len(names) == len(parts) and fname in names:
            return parts[names.index(fname)][1]
        plain = re.split(r"__(?=[FQ\d])", fname)[0]
        hits = [body for head, body in parts if re.search(rf"\b{re.escape(plain)}\b", head)]
        return hits[-1] if hits else parts[-1][1]

    # ------------------------------------------------------------ the natural compile

    def natural(self):
        """Compile as the judge does (plus dumps), read the allocator's inputs from the dumps."""
        self.compile("n", dumps=("-da",))
        self.lst = self.assemble("n")
        self.fname = self.lst.fname
        self.ok, self.report = self.judge("n")
        lreg = self.dump("n", "lreg")
        greg = self.dump("n", "greg")
        self.insns, self.live_in = R.parse_insns(lreg)
        self.by_uid = {i.uid: i for i in self.insns}
        self.graph = R.conflict_graph(self.insns, self.live_in)
        self.stats = R.pseudo_stats(lreg)
        self.disp = R.dispositions(greg)
        self.order = R.global_order(greg)
        self.lines = self._lines()
        self.first = min(self.stats) if self.stats else 84
        self.first_set = {}
        for ins in self.insns:
            for p in ins.sets:
                self.first_set.setdefault(p, ins.uid)
        return self.ok

    def _lines(self):
        """{insn uid: source line}. Line notes exist only in a `-g` compile, whose uids differ (the
        notes take numbers), so the two first RTL dumps are paired insn by insn in order."""
        try:
            self.compile("g", dumps=("-g", "-dr"))
        except OracleError:
            return {}
        with_lines = R.line_notes(self.dump("g", "rtl"), keep_order=True)
        plain = R.line_notes(self.dump("n", "rtl"), keep_order=True)
        if len(with_lines) != len(plain):
            return {}
        return {uid: line for (uid, _), (_, line) in zip(plain, with_lines)}

    # ------------------------------------------------------------ votes

    def padded(self, n):
        """The original's words for a draft of n instructions: a nop the original has after my
        last instruction is alignment, as the judge takes it."""
        t = self.target
        return t[:n] if len(t) > n and not any(t[n:]) else t

    def align(self, mine):
        tgt = self.padded(len(mine))
        sm, st = [R.shape(w) for w in mine], [R.shape(w) for w in tgt]
        if len(mine) == len(tgt):
            return [(i, i) for i in range(len(mine)) if sm[i] == st[i]]
        pairs = []
        for b in difflib.SequenceMatcher(None, sm, st, autojunk=False).get_matching_blocks():
            pairs += [(b.a + k, b.b + k) for k in range(b.size)]
        return pairs

    def vote(self, lst, disp, loose=False):
        """({pseudo: Counter of wanted hard registers}, unexplained register differences): where
        an aligned pair of instructions differs only in a register field, the pseudo of that
        insn that sits in my register (as its output if the field is written, as an input
        otherwise) must sit in the original's. `loose` pairs the instructions when their order
        differs too (orc_rtl.align_words)."""
        mine = [w for _, w, _ in lst.words]
        votes = collections.defaultdict(collections.Counter)
        unexplained = []
        pairs = R.align_words(lst.linked, self.padded(len(mine))) if loose and len(lst.linked) == len(mine) \
            else self.align(mine)
        for i, j in pairs:
            km, fm = R.fields(mine[i])
            kt, ft = R.fields(self.target[j])
            if km != kt:
                continue
            if fm == ft or fm.keys() != ft.keys():
                continue
            uid = lst.words[i][2]
            ins = self.by_uid.get(uid)
            dest = R.dest_field(mine[i])
            pair = R.source_pair(mine[i])
            swapped = pair and fm[pair[0]] == ft[pair[1]] and fm[pair[1]] == ft[pair[0]] and fm[pair[0]] != fm[pair[1]]
            for f in fm:
                if fm[f] == ft[f] or (swapped and f in pair):
                    continue        # exchanged operands of a commutative instruction: not a register choice
                cands = []
                if ins is not None:
                    pool = ins.sets if f == dest else ins.uses
                    cands = [p for p in pool if p >= self.first and disp.get(p) == fm[f]]
                    if not cands:
                        cands = [p for p in (ins.sets | ins.uses) if p >= self.first and disp.get(p) == fm[f]]
                elif fm[f] not in (0, 28, 29, 31):
                    # an insn made after allocation (a reload, a split: the dump before it does not
                    # have it): the register speaks for the pseudo that lives in it, if only one does
                    cands = [p for p, h in disp.items() if h == fm[f] and p >= self.first]
                    cands = cands if len(cands) == 1 else []
                if not cands:
                    unexplained.append({"word": i, "uid": uid, "mine": R.regname(fm[f]), "original": R.regname(ft[f])})
                    continue
                for p in cands:
                    votes[p][ft[f]] += 1
        return votes, unexplained

    def score(self, report, lst):
        """Distance of a compile from the original when several passes are forced in turn: the
        judge's count plus the instructions one side has and the other has not. The second term
        lets a register move count as progress while the order is still wrong."""
        d = self.distance(report, lst)
        if d is None:
            return 10 ** 6
        return d + R.bag_distance(lst.linked, self.padded(len(lst.linked)))

    def distance(self, report, lst):
        """Instructions that differ: the judge's count, or the aligned count when that is
        smaller (the judge compares row by row: one instruction more or less and every later
        row differs). None when there is no listing."""
        d = differ(report)
        if d is None or d == 0:
            return d
        mine, target = [R.nodisp(w) for w in lst.linked], [R.nodisp(w) for w in self.padded(len(lst.linked))]
        if mine == target:
            return d        # equal but for branch displacements: the judge's rows are the truth
        blocks = difflib.SequenceMatcher(None, mine, target, autojunk=False).get_matching_blocks()
        return min(d, max(1, max(len(mine), len(target)) - sum(b.size for b in blocks)))

    def conflicts(self, final, changes):
        """{pseudo: what it would collide with} for the overrides in `changes`, given the whole
        assignment `final` they produce: a pseudo live with it in the same register, or that
        hard register itself live or set inside its life."""
        bad = {}
        for p, h in changes.items():
            for q in self.graph.get(p, ()):
                if q >= self.first:
                    if q != p and final.get(q) == h:
                        bad[p] = f"pseudo {q} is live with it in {R.regname(h)}"
                        break
                elif q == h:
                    bad[p] = f"{R.regname(h)} itself is live or set inside its life"
                    break
        return bad

    # ------------------------------------------------------------ forcing at reload

    def forced(self, tag, force, at="reload", trace="none", sched=None, untie=(), reorg=None):
        """Compile with overrides ({pseudo: hard register}) written at reload's entry (`reload`:
        nothing follows from them) or imposed where the allocator decides (`alloc`: later
        decisions follow). Returns (ok, report, listing, final dispositions, hook record)."""
        cfg = {"function": self.fname, "trace": trace, ("force_reload" if at == "reload" else "force_alloc"): force}
        if sched:
            cfg["sched"] = sched
        if reorg:
            cfg["reorg"] = reorg
        if untie:
            cfg["untie"] = [list(x) for x in untie]
        tr = self.compile(tag, cfg, dumps=("-dg",))
        lst = self.assemble(tag)
        ok, report = self.judge(tag)
        disp = R.dispositions(self.dump(tag, "greg", lst.fname))
        return ok, report, lst, disp, tr.get("functions", {}).get(self.fname, {}), tr.get("errors", [])

    def fixed_point(self, sched=None, reorg=None, start=None, loose=False, tag="r"):
        """Vote, check, force at reload, compile, compare, vote again, until the output is the
        original or nothing moves. Returns a dict (see oracle.py report). With `sched` / `reorg`
        every compile is steered that way too, and `start` is the assignment to begin from."""
        out = {"rounds": [], "force": {}, "result": "none", "differ": differ(self.report), "dropped": {}}
        force, disp, lst, report0 = dict(start or {}), dict(self.disp), self.lst, self.report
        if force or sched or reorg:
            _, report0, lst, disp, _, _ = self.forced(tag + "s", force, sched=sched, reorg=reorg)
        d0 = differ(report0)
        # loose (other passes are forced too): progress is the combined score, not the count alone
        rate = (lambda rep, l: self.score(rep, l)) if loose else (lambda rep, l: differ(rep) if differ(rep) is not None else 10 ** 6)
        best = (rate(report0, lst), dict(force), report0)
        best_lst = lst
        seen = set()
        for rnd in range(MAX_ROUNDS):
            votes, unexplained = self.vote(lst, disp, loose)
            new = {}
            for p, c in votes.items():
                h, n = c.most_common(1)[0]
                if disp.get(p) != h:
                    new[p] = h
            if not new:
                out["unexplained"] = unexplained[:20]
                break
            final = dict(disp)
            final.update(new)
            bad = self.conflicts(final, new)
            safe = {p: h for p, h in new.items() if p not in bad}
            use = safe or new      # nothing safe left: try the colliding ones once
            trial = dict(force)
            trial.update(use)
            key = tuple(sorted(trial.items()))
            if key in seen:
                break
            seen.add(key)
            force = trial
            ok, report, lst, disp, _, errors = self.forced(f"{tag}{rnd}", force, sched=sched, reorg=reorg)
            d = differ(report)
            out["rounds"].append({"forced": len(force), "added": {str(p): h for p, h in use.items()},
                                  "collisions": {str(p): why for p, why in bad.items()}, "differ": d})
            if d is not None and rate(report, lst) < best[0]:
                best = (rate(report, lst), dict(force), report)
                best_lst = lst
            if ok:
                break
        # an override that puts a pseudo where it already was is no override
        out["force"] = {str(p): [self.disp.get(p, -1), h] for p, h in sorted(best[1].items()) if self.disp.get(p, -1) != h}
        bd = differ(best[2])
        out["differ_forced"] = bd
        out["score_forced"] = best[0]
        out["result"] = "match" if bd == 0 else "closer" if out["force"] and bd is not None and bd < (out["differ"] or 10 ** 6) else "none"
        out["residual_class"] = classify(best[2])
        sw = swaps(best[2])
        if sw:
            # all that is left is which operand of a commutative instruction comes first
            words = best_lst.words
            out["result"] = "operand order"
            out["swaps"] = [{"line": self.line_of(words[i][2]) if i < len(words) else None, "original": a, "mine": b}
                            for i, a, b in sw]
        self.best_report = best[2]
        self.best_lst = best_lst
        return out

    # ------------------------------------------------------------ decisions

    @staticmethod
    def decisions(rec):
        """[(pseudo, phase, call record)] in the order the allocator decided: local-alloc block by
        block (the last call of each quantity is its decision), then global."""
        out, at = [], {}
        for c in rec.get("local", []):
            for p in c["pseudos"]:
                if p in at:
                    out[at[p]] = None
                at[p] = len(out)
                out.append((p, "local", c))
        for c in rec.get("global", []):
            p = c["pseudo"]
            if p in at:
                out[at[p]] = None
            at[p] = len(out)
            out.append((p, "global", c))
        return [x for x in out if x]

    def causal(self, want, operand_order=False, sched=None, reorg=None):
        """The smallest set of allocation decisions which, overridden where they are made, give
        the whole assignment `want` ({pseudo: hard register} at reload's entry): decisions are
        taken in the allocator's order and each later one is left to follow from the earlier
        ones, so only the ones that are really different are counted. `sched` and `reorg` are
        kept on every compile when the certificate needs those passes forced too."""
        force, steps, untie = {}, [], set()
        result, last = "stuck", None
        for k in range(MAX_DECISIONS + 1):
            ok, report, lst, disp, rec, errors = self.forced(f"c{k}", force, at="alloc", trace="full", untie=untie,
                                                             sched=sched, reorg=reorg)
            if k == 0:
                self.trace0 = rec
            ren = {int(p): h for p, h in rec.get("renumber", {}).items()}
            order = self.decisions(rec)
            ranked = [p for p, _, _ in order]
            mism = [p for p in ranked if p in want and ren.get(p) != want[p]]
            mism += sorted(p for p in want if p not in ranked and ren.get(p) != want[p])
            if operand_order and not ok and swaps(report):
                ok = True       # the accepted residual: equal up to operand order
            last = (ok, report, rec)
            if not mism:
                result = "match" if ok else "same assignment, other output"
                break
            if ok:      # fewer decisions than the assignment suggested already give the original
                result = "match"
                break
            p = next((x for x in mism if x not in force), None)
            if p is None or k == MAX_DECISIONS:
                result = "stuck" if p is None else "more"
                break
            call = next((c for q, _, c in order if q == p), None)
            phase = next((ph for q, ph, _ in order if q == p), "none")
            apart = self.ties(call, want, untie) if phase == "local" else []
            if apart:
                # one quantity here, two registers in the original: the tie is the decision
                untie.update((u, s_) for u, s_, _ in apart)
                steps += [dict(self.name(s_, rec), decision="tie", phase="local", block=call["block"], qty=call["qty"],
                               tied_to=self.name(u, rec), got=R.regname(ren.get(s_, -1)), want=R.regname(want[s_]),
                               line=self.line_of(uid),
                               why=(f"the insn that sets it lets pseudo {u} die, so local-alloc made the two one "
                                    f"quantity in one register; the original has them in {R.regname(want[u])} and "
                                    f"{R.regname(want[s_])}"),
                               need=("make the other operand the one that dies first in that expression (exchange the "
                                     "operands of the commutative operator), or use the dying value once more after it"))
                          for u, s_, uid in apart]
                continue
            steps.append(self.explain(p, ren.get(p, -1), want[p], phase, call, order, ren, want, rec))
            force[p] = want[p]
        failed = [c for c in last[2].get("local", []) + last[2].get("global", []) if c.get("force_failed")] if last else []
        return {"result": result, "decisions": steps, "force": {str(p): h for p, h in force.items()},
                "untie": sorted(map(list, untie)),
                "differ": differ(last[1]) if last else None,
                "refused": [c.get("pseudos") or [c.get("pseudo")] for c in failed]}

    def ties(self, call, want, done):
        """[(dying pseudo, set pseudo, insn uid)] inside one quantity whose two members the wanted
        assignment puts in different registers."""
        mates = set(call["pseudos"]) if call else set()
        out = []
        if len(mates) < 2:
            return out
        for ins in self.insns:
            for s_ in ins.sets & mates:
                for u in (ins.dead & ins.uses & mates) - {s_}:
                    if u in want and s_ in want and want[u] != want[s_] and (u, s_) not in done and (s_, u) not in done:
                        out.append((u, s_, ins.uid))
        return out

    # ------------------------------------------------------------ why

    @staticmethod
    def priority(refs, length, size=1):
        if not refs or not length or length <= 0:
            return 0
        return int((refs.bit_length() - 1) * refs * size / length * 10000)

    def name(self, p, rec):
        v = (rec.get("vars") or {}).get(str(p))
        st = self.stats.get(p, {})
        uid = self.first_set.get(p)
        out = {"pseudo": p, "user": bool(st.get("user")), "line": self.line_of(uid)}
        if v:
            out.update(var=v[0], declared=v[1], kind=v[2])
        return out

    def line_of(self, uid):
        """Source line of an insn; one made by a later pass takes the line of the insn before it."""
        if uid is None:
            return None
        if uid in self.lines:
            return self.lines[uid]
        if not hasattr(self, "_near"):
            self._near, line = {}, None
            for ins in self.insns:
                line = self.lines.get(ins.uid, line)
                self._near[ins.uid] = line
        return self._near.get(uid)

    def explain(self, p, got, want, phase, call, order, ren, wanted, rec):
        """One wrong decision with the inputs that decided it and what would have to change."""
        d = dict(self.name(p, rec), got=R.regname(got), want=R.regname(want), phase=phase)
        st = self.stats.get(p, {})
        d["refs"], d["live_length"], d["calls_crossed"] = st.get("refs"), st.get("length"), st.get("calls")
        index = {q: i for i, (q, _, _) in enumerate(order)}
        mine = index.get(p, len(order))
        rivals = [q for q in self.graph.get(p, ()) if q >= self.first]
        if phase == "local" and call is not None:
            # local-alloc's own notion: quantities of the block whose (scheduling-padded) ranges overlap
            rivals = sorted(set(rivals) | {q for q, ph, c in order if ph == "local" and c is not call
                                           and c["block"] == call["block"] and c["born"] < call["dead"]
                                           and call["born"] < c["dead"]})

        def describe(q):
            c = next((c for x, _, c in order if x == q), None)
            e = dict(self.name(q, rec), reg=R.regname(ren.get(q, -1)), decided="before" if index.get(q, 10 ** 6) < mine else "after")
            e["phase"] = next((ph for x, ph, _ in order if x == q), "none")
            e["refs"], e["live_length"] = self.stats.get(q, {}).get("refs"), self.stats.get(q, {}).get("length")
            if c and "birth" in c:
                e["priority"] = self.priority(c["n_refs"], c["death"] - c["birth"], c["size"])
                e["qty"], e["birth"], e["death"] = c["qty"], c["birth"], c["death"]
            elif c and "n_refs" in c:
                e["priority"] = self.priority(c["n_refs"], c["live_length"], c["size"])
            return e

        if call is None:
            d["why"] = "never offered a register (no allocation call for it)"
            return d
        if phase == "local":
            d.update(block=call["block"], qty=call["qty"], tied=call["pseudos"], birth=call.get("birth"), death=call.get("death"),
                     n_refs=call.get("n_refs"), suggested=[R.regname(h) for h in call.get("copy_sugg", []) + call.get("sugg", [])],
                     by_suggestion=bool(call.get("just_try_suggested")))
            if call.get("n_refs") is not None:
                d["priority"] = self.priority(call["n_refs"], call["death"] - call["birth"], call["size"])
            busy = set(call.get("live", []))
        else:
            d.update(n_refs=call.get("n_refs"), allocno=call.get("allocno"),
                     preferred=[R.regname(h) for h in call.get("copy_prefs", []) + call.get("prefs", [])],
                     rank=next((i for i, c in enumerate(rec.get("global", [])) if c["pseudo"] == p), None))
            if call.get("n_refs") is not None:
                d["priority"] = self.priority(call["n_refs"], call["live_length"], call["size"])
            busy = set(call.get("conflicts", []))
        holders = [q for q in rivals if ren.get(q) == want and index.get(q, 10 ** 6) < mine]
        takers = [q for q in rivals if wanted.get(q, ren.get(q)) == got and q != p]
        if want in busy:
            d["blocked"] = True
            if holders:
                d["why"] = f"{R.regname(want)} was taken: decided earlier for a value live at the same time"
                d["rivals"] = [describe(q) for q in holders]
                d["need"] = "allocate this one before the rival (higher priority, earlier birth), or shorten the overlap"
            elif want < self.first and want in self.graph.get(p, ()):
                d["why"] = f"{R.regname(want)} itself is live or set while this value is live (argument, call result, return value)"
                d["need"] = "move the statement that sets or uses that register out of this value's life"
            else:
                d["why"] = f"{R.regname(want)} was busy over this value's range"
                d["need"] = "shorten this value's life or the other's"
        else:
            d["blocked"] = False
            sugg = call.get("copy_sugg", []) + call.get("sugg", []) if phase == "local" else call.get("copy_prefs", []) + call.get("prefs", [])
            if got in sugg and want not in sugg:
                d["why"] = f"{R.regname(got)} was suggested by a copy to or from that register"
                d["need"] = "remove the copy that ties it to that register, or make the original's register the tied one"
            elif takers:
                d["why"] = (f"{R.regname(got)} was the first free register; in the original a value live at the same "
                            f"time holds it, so that one was placed first")
                d["rivals"] = [describe(q) for q in takers]
                d["need"] = "allocate the rival before this one (raise its priority or lower this one's, or let it be born first)"
            else:
                d["why"] = f"{R.regname(got)} was the first free register and {R.regname(want)} came later in the order"
                d["need"] = "something must occupy the earlier register over this range in the original (a longer-lived value, a call result)"
        return d

    # ------------------------------------------------------------ the whole report

    def report_all(self, rel=None):
        row = {"addr": f"{self.addr:08x}", "draft": rel or self.src, "sha": digest(self.src), "profile": self.profile or "default",
               "original": len(self.target)}
        self.natural()
        row.update(function=self.fname, instructions=len(self.lst.words), differ=differ(self.report),
                   natural_class=classify(self.report))
        if self.ok:
            row.update(kind="match", distance=0)
            return row
        if differ(self.report) is None:
            row.update(kind="error", error=self.report.split("\n")[0][:200])
            return row
        fp = self.fixed_point()
        row["reload"] = fp
        if len(self.lst.words) != len(self.padded(len(self.lst.words))) and row["natural_class"] != "match":
            row["natural_class"] = "length"
        if fp["result"] not in ("match", "operand order"):
            if fp["residual_class"] != "match" and len(self.lst.words) != len(self.padded(len(self.lst.words))) \
                    and fp["result"] != "closer":
                fp["residual_class"] = "length"
            row["kind"] = "allocation+other" if fp["result"] == "closer" else "other"
            row["residual_class"] = fp["residual_class"]
            row["distance"] = None
            row["gdb_runs"] = self.n_gdb
            return row
        # the whole assignment the original needs, as the allocators would leave it for reload
        rec0 = self.forced("t", {}, at="alloc", trace="light")[4]
        want = {int(p): h for p, h in rec0.get("renumber", {}).items()}
        want.update({int(p): v[1] for p, v in fp["force"].items()})
        ca = self.causal(want, operand_order=fp["result"] == "operand order")
        row["causal"] = ca
        row["kind"] = "allocation" if fp["result"] == "match" else "allocation+operand order"
        row["certified"] = True
        row["pseudos_moved"] = len(fp["force"])
        row["operand_swaps"] = len(fp.get("swaps", []))
        row["distance"] = len(ca["decisions"]) if ca["result"] == "match" else None
        if ca["result"] == "stuck":
            ca["note"] = ("the registers alone give the original, but this RTL cannot be allocated that way: the "
                          "allocator refuses the original's register for a value whose life overlaps it here, so a "
                          "value lives longer or shorter in the original (another variable is used at some site)")
        row["gdb_runs"] = self.n_gdb
        return row
