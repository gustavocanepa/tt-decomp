#!/usr/bin/env python3
"""Recover SGI STL sorting helpers using the original public template bodies.

Example: stl_algo.py --size 44 --key-offset 40 --key-type int
Each exact code candidate is judged again with address-specific type names so
separately placed instantiations cannot alias each other's linker symbols.
"""
import argparse
from dataclasses import dataclass
import json
import re
from pathlib import Path
import struct
import subprocess
import sys

import libmatch
import match
import project
import stl

OUT = Path(project.ROOT) / "build" / "stl_algo"
MEMBERS = {
    "push_heap": ("void", "__push_heap", "V *, D, D, V"),
    "adjust_heap": ("void", "__adjust_heap", "V *, D, D, V"),
    "make_heap": ("void", "__make_heap", "V *, V *, V *, D *"),
    "sort_heap": ("void", "sort_heap", "V *, V *"),
    "insertion_sort": ("void", "__insertion_sort", "V *, V *"),
    "unguarded_linear_insert": ("void", "__unguarded_linear_insert", "V *, V"),
    "unguarded_insertion_sort_aux": ("void", "__unguarded_insertion_sort_aux", "V *, V *, V *"),
    "unguarded_insertion_sort": ("void", "__unguarded_insertion_sort", "V *, V *"),
    "final_insertion_sort": ("void", "__final_insertion_sort", "V *, V *"),
    "introsort_loop": ("void", "__introsort_loop", "V *, V *, V *, D"),
    "partial_sort": ("void", "__partial_sort", "V *, V *, V *, V *"),
    "unguarded_partition": ("V *", "__unguarded_partition", "V *, V *, V"),
    "sort": ("void", "sort", "V *, V *"),
}


@dataclass(frozen=True)
class Spec:
    size: int
    key_offset: int = 0
    key_type: str = "int"
    comparator: str = "member"
    distance: str = "int"
    descending: bool = False
    alignment: int = 4

    def validate(self):
        if self.alignment not in (4, 8, 16) or self.size % self.alignment:
            raise ValueError("value size must be a multiple of its supported alignment")
        if self.size < 4 or self.size % 4:
            raise ValueError("value size must be a positive multiple of four")
        if self.key_type not in ("int", "unsigned int", "float"):
            raise ValueError("unsupported key type")
        if self.comparator not in ("member", "external", "pointer"):
            raise ValueError("unsupported comparator")
        if self.comparator == "member" and (self.key_offset < 0 or
                self.key_offset % 4 or self.key_offset + 4 > self.size):
            raise ValueError("key must be an aligned word within the value")
        if self.distance not in ("int", "long"):
            raise ValueError("unsupported distance type")


def source(spec, member, tag):
    spec.validate()
    value, compare = f"SortValue_{tag}", f"SortCompare_{tag}"
    alignment = "" if spec.alignment == 4 else f" __attribute__((aligned({spec.alignment})))"
    if spec.comparator == "member":
        fields = (f"char prefix[{spec.key_offset}]; " if spec.key_offset else "")
        fields += f"{spec.key_type} key; "
        tail = spec.size - spec.key_offset - 4
        if tail:
            fields += f"char suffix[{tail}]; "
        op = ">" if spec.descending else "<"
        fields += f"bool operator<(const {value} &o) const {{ return key {op} o.key; }}"
        declarations = f"struct {value} {{ {fields} }}{alignment};\n"
    else:
        declarations = f"struct {value} {{ int words[{spec.size // 4}]; }}{alignment};\n"
        if spec.comparator == "external":
            declarations += (f'extern "C" bool sort_compare_{tag}(const {value} *, const {value} *);\n'
                f"struct {compare} {{ char state; bool operator()(const {value} &a, const {value} &b) const "
                f"{{ return sort_compare_{tag}(&a, &b); }} }};\n")
        else:
            declarations += f"typedef bool (*{compare})(const {value} &, const {value} &);\n"
    result, name, params = MEMBERS[member]
    if spec.comparator != "member":
        # These helpers put the comparator ahead of their type-deduction pointers.
        if member == "make_heap":
            params = f"V *, V *, {compare}, V *, D *"
        else:
            params += f", {compare}"
    params = re.sub(r"\b[VD]\b", lambda m: value if m.group() == "V" else spec.distance, params)
    result = re.sub(r"\bV\b", value, result)
    return ("/* compiler: ee-gcc2.96-stl */\n"
            "/* SGI STL public sorting templates instantiated by tools/stl_algo.py.\n"
            f"   Value: {spec.size} bytes, alignment {spec.alignment}; comparator: {spec.comparator}; "
            f"key: {spec.key_type} at {spec.key_offset}; member: {member}. */\n"
            "#include <stl_algobase.h>\n#include <stl_iterator.h>\n"
            "#include <stl_construct.h>\n#include <stl_uninitialized.h>\n"
            "#include <limits.h>\n#include <stdlib.h>\n#include <stl_tempbuf.h>\n"
            "#include <stl_algo.h>\n" + declarations +
            f"template {result} {name}({params});\n")


def compile_source(path, text):
    path.write_text(text)
    obj = match.compile_c(str(path))
    try:
        blob, relocs, funcs = match.read_object(obj, want_symbols=True)
        if len(funcs) != 1:
            raise ValueError(f"expected one instantiated function, found {len(funcs)}")
        name, offset, size = funcs[0]
        size = max(size, len(blob) - offset)
        words = match.trim_padding(list(struct.unpack_from(f"<{size // 4}I", blob, offset)))
        relocs = {o - offset: (r[0], r[1]) for o, r in relocs.items()
                  if offset <= o < offset + len(words) * 4}
        return name, words, relocs
    finally:
        Path(obj).unlink(missing_ok=True)


def recover(spec, members, tag, only=None, exclude=()):
    OUT.mkdir(parents=True, exist_ok=True)
    done = project.done_addresses() | set(exclude)
    text_addr, text = match.load_text()
    results = []
    for member in members:
        path = OUT / f"{tag}_{member}.cpp"
        try:
            _, words, relocs = compile_source(path, source(spec, member, tag))
        except (SystemExit, ValueError) as exc:
            print(f"{member}: compile failed: {str(exc)[-600:]}", flush=True)
            results.append({"member": member, "status": "does not compile"})
            continue
        candidates = ([only] if only is not None else
                      stl.candidates(words, relocs, done, text_addr, text))
        candidates = [addr for addr in candidates if addr not in done and addr >= 0x005547E8]
        print(f"{member}: {len(words) * 4} bytes, {len(candidates)} exact code candidates", flush=True)
        for addr in candidates:
            # The diary is retained with each probe, including failed judge details.
            diary = subprocess.run([sys.executable, "tools/attempts.py", "show", f"{addr:08X}"],
                                   capture_output=True, text=True, check=True)
            (OUT / f"{addr:08x}_{member}.diary").write_text(diary.stdout)
            candidate = OUT / f"{addr:08x}_{member}.cpp"
            name, target_words, target_relocs = compile_source(candidate, source(spec, member, f"{addr:08X}"))
            orig = match.words_at(text_addr, text, addr, len(target_words) * 4)
            diff = libmatch.differing(target_words, target_relocs, orig)
            if diff:
                status = f"renamed instantiation differs: {diff}"
            else:
                calls = stl.jal_addresses(orig, target_relocs, addr)
                _, status = stl.judge_candidate(stl.Spec("int", 0, None, None, "pod", 4),
                        member, tag, str(candidate), target_words, target_relocs,
                        name, addr, orig, calls)
            matched = status == "MATCH"
            if matched:
                stl.keep(addr, str(candidate))
                done.add(addr)
            else:
                (OUT / f"{addr:08x}_{member}.diff").write_text(stl.judge(addr, str(candidate))[1])
            hypothesis = (f"Public SGI STL {member}: {spec.size}-byte aggregate; "
                          f"{spec.comparator} comparator; {spec.key_type} key at {spec.key_offset}; "
                          f"{spec.distance} distance; descending={spec.descending}; alignment={spec.alignment}; exact template body")
            log_command = [sys.executable, "tools/attempts.py", "log", f"{addr:08X}",
                "--hypothesis", hypothesis, "--result", "match" if matched else "differs",
                "--of", str(len(target_words)), "--file", str(candidate),
                "--compiler", "ee-gcc2.96-stl", "--who", "stl-algorithm-family"]
            if matched or diff:
                log_command += ["--diff", str(diff)]
            subprocess.run(log_command, check=True)
            print(f"  {addr:08X}: {status}", flush=True)
            results.append({"member": member, "address": f"{addr:08x}", "status": status})
    return results


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--size", type=int, required=True)
    parser.add_argument("--key-offset", type=int, default=0)
    parser.add_argument("--key-type", choices=["int", "unsigned int", "float"], default="int")
    parser.add_argument("--comparator", choices=["member", "external", "pointer"], default="member")
    parser.add_argument("--distance", choices=["int", "long"], default="int")
    parser.add_argument("--descending", action="store_true")
    parser.add_argument("--alignment", type=int, choices=[4, 8, 16], default=4)
    parser.add_argument("--member", choices=list(MEMBERS), action="append")
    parser.add_argument("--address", type=lambda x: int(x, 16))
    parser.add_argument("--exclude", type=lambda x: int(x, 16), action="append", default=[])
    args = parser.parse_args()
    spec = Spec(args.size, args.key_offset, args.key_type, args.comparator, args.distance, args.descending, args.alignment)
    spec.validate()
    tag = (f"n{spec.size}_k{spec.key_offset}_{spec.key_type.replace(' ', '_')}_"
           f"{spec.comparator}_{spec.distance}_{int(spec.descending)}_a{spec.alignment}")
    results = recover(spec, args.member or list(MEMBERS), tag, args.address, args.exclude)
    (OUT / f"{tag}.json").write_text(json.dumps(results, indent=2) + "\n")


if __name__ == "__main__":
    main()
