#!/usr/bin/env python3
"""Mechanical readability rewrites for matched sources, on the CPU only. A rewrite is kept only
when the object file it compiles to is identical to the one the current source compiles to: every
section's bytes, every relocation and every symbol (name, value, size, binding, section), not
just the function's instructions the judge compares. The judge must also still say MATCH. A
rewrite that cannot change a single byte of the object cannot change the build.

    tidy.py run [FILES...] [--rules types,vtable] [--max N] [--jobs 2] [--apply] [--out DIR]
        without --apply the rewritten text goes to --out (default build/lead/tidy) and src/ is not
        touched; with --apply a rewrite that matches replaces the source.
    tidy.py show FILE [--rules ...]    print the diff a file would get

Rules (each is a pure text rewrite):
    types   the sized-type typedefs pasted at the top of a file -> #include "types.h"
    vtable  (VEntry *)((char *)obj->vtbl + 0xN)  ->  &obj->vtbl[N / 8]   (a vtable entry is 8 bytes)
    unused  a one-line extern declaration of a name used nowhere else in the file is dropped
    names   func_ADDR written for a function whose name the project knows (config/symbol_addrs.txt,
            the entries taken from GT HD) -> that name, in the declaration and every call.
            The only rule that changes a symbol name, so the gate compares the objects with the
            old name mapped to the new one, and the judge checks that the new name resolves to the
            same address. The file's own function keeps its name (tools/organize.py renames those).
"""
import difflib
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

STD = {"s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64"}
TYPEDEF = re.compile(r"^typedef\s+[A-Za-z_ ]+?\s+(\w+);[ \t]*\n", re.M)
OBJ = r"(?:\(\([\w ]+\*\)\w+\)|[\w]+(?:(?:->|\.)\w+)*)"
VCAST = re.compile(r"\((?P<t>\w*VEntry\w*)\s*\*\)\(\(char\s*\*\)(?P<o>" + OBJ + r")->vtbl\s*\+\s*(?P<n>0x[0-9A-Fa-f]+|\d+)\)")


def rule_types(src, ctx=None):
    """Drop the pasted sized-type typedefs and include types.h, when every name a source pastes is
    one of types.h's (the judge decides whether the widths agree)."""
    head = []
    pos = 0
    for m in TYPEDEF.finditer(src):
        if m.start() != pos:
            break
        head.append(m)
        pos = m.end()
    if not head or not all(m.group(1) in STD for m in head):
        return src
    return '#include "types.h"\n' + src[pos:]


C_KEYWORDS = set("""asm auto bool break case catch char class const continue default delete do double else
enum extern float for goto if inline int long namespace new operator private protected public register
return short signed sizeof static struct switch template this throw try typedef union unsigned virtual void
volatile while true false""".split())


def load_names():
    names = {}
    for line in open(os.path.join(ROOT, "config", "symbol_addrs.txt"), encoding="utf-8"):
        # Only names with a source of their own (gthd: the GT HD symbols). The others in the file are
        # labels the tools derived (Class__virtual_22, Class__structor_1, Class__tf): they say which
        # class a function belongs to, not what it does, so func_ADDR is no worse.
        m = re.match(r"([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+);\s*//\s*type:func\s+gthd\b", line)
        if m and m.group(1) not in C_KEYWORDS and not m.group(1).startswith("__"):
            a = int(m.group(2), 16)
            names.setdefault(a, set()).add(m.group(1))
    return {a: next(iter(n)) for a, n in names.items() if len(n) == 1}


def rule_names(src, ctx):
    """Rename func_ADDR to the project's name for ADDR (see the module doc)."""
    names, own = ctx["names"], ctx["addr"]
    renames = {}
    for m in re.finditer(r"\bfunc_([0-9A-Fa-f]{8})\b", src):
        a = int(m.group(1), 16)
        new = names.get(a)
        if new and a != own and not re.search(r"\b%s\b" % re.escape(new), src):
            renames[m.group(0)] = new
    for old, new in renames.items():
        src = re.sub(r"\b%s\b" % old, new, src)
    ctx.setdefault("renames", {}).update(renames)
    return src

UNUSED_DECL = re.compile(r'^extern[ \t]+(?:"C"[ \t]+)?[^;{}\n]*?\b([A-Za-z_]\w*)[ \t]*'
                         r'(?:\([^;{}\n]*\)[ \t]*(?:throw\(\)[ \t]*)?|\[[^\]\n]*\][ \t]*)?;[ \t]*$', re.M)


def rule_unused(src, ctx=None):
    """Drop a one-line extern declaration of a name that appears nowhere else in the file."""
    out, last = [], 0
    for m in UNUSED_DECL.finditer(src):
        line = m.group(0)
        # `extern char A[], B[];` declares several names (only the last is captured), and a
        # declaration before an #include or with throw() can change the code the headers produce
        if "," in re.sub(r"\([^()]*\)", "", line) or "throw" in line or "memmove" in line:
            continue
        if len(re.findall(r"\b%s\b" % re.escape(m.group(1)), src)) == 1:
            out.append(src[last:m.start()])
            last = m.end() + (1 if src[m.end():m.end() + 1] == "\n" else 0)
    out.append(src[last:])
    return "".join(out)


def rule_vtable(src, ctx=None):
    def sub(m):
        n = int(m.group("n"), 0)
        if n % 8:
            return m.group(0)
        return "&%s->vtbl[%d]" % (m.group("o"), n // 8)
    return VCAST.sub(sub, src)


RULES = {"types": rule_types, "vtable": rule_vtable, "names": rule_names, "unused": rule_unused}


def read_elf(path, rename=None):
    """Everything in a MIPS ELF32 .o that can reach the link, without what only names the source
    file or the compiler (.comment, .mdebug, .debug*, file symbols): the sections' type, flags,
    alignment and bytes, the relocations as (offset, type, symbol name) and the symbols."""
    import struct
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]

    def cstr(base, off):
        return d[base + off:d.index(b"\0", base + off)].decode("latin-1")

    names = [cstr(secs[shstrndx][4], s[0]) for s in secs]
    out = {}
    symtab = next((i for i, s in enumerate(secs) if s[1] == 2), None)
    syms = []
    if symtab is not None:
        st = secs[symtab]
        strs = secs[st[6]][4]
        for i in range(st[5] // 16):
            nm, val, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, st[4] + i * 16)
            if info & 0xF == 4:                                   # STT_FILE
                syms.append(None)
                continue
            nm = cstr(strs, nm)
            syms.append((rename.get(nm, nm) if rename else nm, val, size, info, other, names[shndx] if 0 < shndx < len(names) else shndx))
    out["symbols"] = [x for x in syms if x]
    for i, s in enumerate(secs):
        n = names[i]
        if n in (".comment", ".mdebug", ".shstrtab", ".strtab", ".symtab") or n.startswith((".debug", ".rel", ".gnu.linkonce.wi")):
            if s[1] == 9:                                         # SHT_REL
                rels = []
                for r in range(s[5] // 8):
                    off, info = struct.unpack_from("<II", d, s[4] + r * 8)
                    sym = syms[info >> 8] if (info >> 8) < len(syms) else None
                    rels.append((off, info & 0xFF, sym[0] if sym else "FILE"))
                out["rel:" + names[s[7]]] = rels
            continue
        out[n] = (s[1], s[2], s[8], d[s[4]:s[4] + s[5]] if s[1] != 8 else s[5])   # NOBITS: size only
    return out


def same_object(a, b, rename=None):
    """None when the two objects are identical for the link, else a short reason. rename maps the
    symbol names of a (the current source) to those b is expected to use."""
    x, y = read_elf(a, rename), read_elf(b)
    for key in sorted(set(x) | set(y)):
        if x.get(key) != y.get(key):
            return f"{key} differs"
    return None


def rewrite(src, rules, ctx=None):
    ctx = ctx if ctx is not None else {}
    for r in rules:
        src = RULES[r](src, ctx)
    return src


def parse(argv):
    opts = {"rules": list(RULES), "max": 0, "jobs": 2, "apply": False, "out": os.path.join(ROOT, "build", "lead", "tidy")}
    files = []
    i = 0
    while i < len(argv):
        a = argv[i]
        if a == "--rules":
            opts["rules"] = argv[i + 1].split(","); i += 1
        elif a == "--max":
            opts["max"] = int(argv[i + 1]); i += 1
        elif a == "--jobs":
            opts["jobs"] = int(argv[i + 1]); i += 1
        elif a == "--out":
            opts["out"] = argv[i + 1]; i += 1
        elif a == "--apply":
            opts["apply"] = True
        else:
            files.append(a)
        i += 1
    return opts, files


def main(argv):
    if not argv:
        print(__doc__)
        return 1
    cmd, opts, files = argv[0], *parse(argv[1:])
    os.chdir(ROOT)
    import match
    import project
    srcs = project.sources(refresh=True)                 # {address: path}
    byrel = {os.path.relpath(str(p), ROOT).replace(os.sep, "/"): a for a, p in srcs.items()}
    rels = [os.path.relpath(f, ROOT).replace(os.sep, "/") for f in files] or sorted(byrel)
    if cmd == "show":
        text = open(rels[0], encoding="utf-8").read()
        new = rewrite(text, opts["rules"], {"names": load_names(), "addr": byrel.get(rels[0], -1)})
        sys.stdout.writelines(difflib.unified_diff(text.splitlines(True), new.splitlines(True), rels[0], rels[0]))
        return 0
    names = load_names() if "names" in opts["rules"] else {}
    todo = []
    for rel in rels:
        if rel not in byrel:
            continue
        text = open(rel, encoding="utf-8", newline="").read()
        ctx = {"names": names, "addr": byrel[rel]}
        new = rewrite(text, opts["rules"], ctx)
        if new != text:
            todo.append((rel, byrel[rel], new, ctx.get("renames", {})))
        if opts["max"] and len(todo) >= opts["max"]:
            break
    os.makedirs(opts["out"], exist_ok=True)
    pairs, newtext = [], {}
    for rel, addr, new, renames in todo:
        tmp = os.path.join(opts["out"], "%08x_%s" % (addr, os.path.basename(rel)))
        open(tmp, "w", encoding="utf-8", newline="").write(new)
        pairs.append((addr, tmp))
        newtext[tmp] = rel, new, renames
    kept = bad = 0
    for k in range(0, len(pairs), 100):
        part = pairs[k:k + 100]
        both = match.compile_many([newtext[t][0] for _, t in part] + [t for _, t in part], opts["jobs"])
        for addr, tmp in part:
            rel, new, renames = newtext[tmp]
            a, b = both.get(rel), both.get(tmp)
            why = "compile failed" if not (a and b) else same_object(a, b, renames)
            if why is None:
                ok, report = match.judge(addr, tmp, b)       # judge removes b
                why = None if ok else "judge: " + report.splitlines()[0][:80]
            if why is None:
                kept += 1
                if opts["apply"]:
                    open(rel, "w", encoding="utf-8", newline="").write(new)
            else:
                bad += 1
                print("rejected:", rel, "-", why)
        import shutil
        for o in both.values():
            if o:
                shutil.rmtree(os.path.dirname(o), ignore_errors=True)
                break
    print(f"{len(todo)} rewritten, {kept} identical object + MATCH, {bad} rejected" + (" (applied)" if opts["apply"] else " (not applied)"))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
