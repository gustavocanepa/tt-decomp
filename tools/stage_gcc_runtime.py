#!/usr/bin/env python3
"""Stage public GCC 2000-10-03 runtime sources for the GT4 library matcher.

Run under Linux/WSL with the original EE compiler installed. The source tree
and staging output stay outside the repository; no game files are copied.
"""
import argparse
import difflib
import json
import shutil
import subprocess
from pathlib import Path

import project


STDDEF = """#ifndef GT4_RUNTIME_STDDEF
#define GT4_RUNTIME_STDDEF
typedef unsigned int size_t;
typedef int ptrdiff_t;
#define NULL 0
#endif
"""

TARGET = """#ifndef GT4_RUNTIME_TCONFIG
#define GT4_RUNTIME_TCONFIG
#include "gansidecl.h"
#define BITS_PER_UNIT 8
#define UNITS_PER_WORD 8
#define MIN_UNITS_PER_WORD 8
#define LONG_LONG_TYPE_SIZE 128
#define LONG_DOUBLE_TYPE_SIZE 64
#define WORDS_BIG_ENDIAN 0
#define DWARF2_UNWIND_INFO 1
#define FIRST_PSEUDO_REGISTER 122
#define DWARF_FRAME_REGISTERS 122
#define STACK_GROWS_DOWNWARD 1
#define inhibit_libc 1
#endif
"""

THREADS = """/* Reconstructed EE semaphore ABI used by the public GCC frame runtime.
   These adapters describe the observed calls. The SDK implementations remain
   external functions in the original image. */
#ifndef GT4_GTHR_RUNTIME
#define GT4_GTHR_RUNTIME
typedef int __gthread_mutex_t;
#define __GTHREAD_MUTEX_INIT 0
extern int func_005ADCE0(int);
extern int func_005ADCC0(int);
static inline int __gthread_mutex_lock(__gthread_mutex_t *mutex)
{ return func_005ADCE0(*mutex); }
static inline int __gthread_mutex_unlock(__gthread_mutex_t *mutex)
{ return func_005ADCC0(*mutex); }
#endif
"""


def copy_files(source, output, names):
    output.mkdir(parents=True, exist_ok=True)
    for name in names:
        shutil.copyfile(source / name, output / Path(name).name)


def preprocess(compiler, directory, source, target, defines=()):
    command = [str(compiler), "-E", "-C", "-I.",
               "-I" + str(Path(project.ROOT) / "include/shim")]
    command += ["-D" + define for define in defines]
    result = subprocess.run(command + [source], cwd=directory,
                            capture_output=True, text=True, check=True)
    (directory / target).write_text(result.stdout, encoding="utf-8")


def ps2_softfloat(source):
    """The target omits the single-precision multiply/divide rounding guards.

    Keep the public implementation around these two blocks unchanged. Each
    resulting routine is still checked against the original machine code.
    """
    for condition in ("if ((high & GARDMASK) == GARDMSB)",
                      "if ((quotient & GARDMASK) == GARDMSB)"):
        if source.count(condition) != 1:
            raise ValueError(f"unexpected fp-bit.c rounding block: {condition}")
        start = source.index(condition)
        opening = source.index("{", start)
        depth = 0
        for end in range(opening, len(source)):
            depth += (source[end] == "{") - (source[end] == "}")
            if depth == 0:
                source = source[:start] + source[end + 1:]
                break
        else:
            raise ValueError("unterminated fp-bit.c rounding block")
    return source


def ps2_pack(source, *, single):
    """Preserve the target's flush/truncate packing and single exponent range."""
    opening = "      if (src->normal_exp < NORMAL_EXPMIN)"
    closing = "\n    }\n\n  /* We previously used bitfields"
    if source.count(opening) != 1 or source.count(closing) != 1:
        raise ValueError("unexpected fp-bit.c pack body")
    start = source.index(opening)
    end = source.index(closing, start)
    if single:
        body = """      if (src->normal_exp < NORMAL_EXPMIN)
        {
          fraction = 0;
        }
      else if (src->normal_exp > EXPBIAS + 1)
        {
          exp = EXPMAX;
          fraction = 0;
        }
      else
        {
          exp = src->normal_exp + EXPBIAS;
          if (src->normal_exp == EXPBIAS + 1 && (SItype) fraction < 0)
            {
              exp = EXPMAX;
              fraction = 0;
            }
          else
            fraction >>= NGARDS;
        }"""
    else:
        body = """      if (src->normal_exp < NORMAL_EXPMIN)
        {
          fraction = 0;
        }
      else if (src->normal_exp > EXPBIAS)
        {
          exp = EXPMAX;
          fraction = 0;
        }
      else
        {
          exp = src->normal_exp + EXPBIAS;
          fraction >>= NGARDS;
        }"""
    return source[:start] + body + source[end:]


def ps2_unpack(source, *, single):
    """Adapt public special-value handling to the independently matched parts."""
    signature = "unpack_d (FLO_union_type * src, fp_number_type * dst)"
    if source.count(signature) != 1:
        raise ValueError("unexpected fp-bit.c unpack signature")
    start = source.index(signature)
    end = source.index("#endif /* L_unpack_df || L_unpack_sf */", start)
    body = source[start:end]
    condition = "  else if (exp == EXPMAX)\n    {"
    if body.count(condition) != 1:
        raise ValueError("unexpected fp-bit.c maximum-exponent branch")
    if single:
        first = body.index(condition)
        opening = body.index("{", first)
        depth = 0
        for last in range(opening, len(body)):
            depth += (body[last] == "{") - (body[last] == "}")
            if depth == 0:
                break
        else:
            raise ValueError("unterminated fp-bit.c maximum-exponent branch")
        body = body[:first] + body[last + 1:]
    else:
        body = body.replace(condition, condition + "\n      dst->normal_exp = EXPBIAS;")
        assignment = "\t  dst->class = CLASS_INFINITY;"
        if body.count(assignment) != 1:
            raise ValueError("unexpected fp-bit.c infinity class assignment")
        body = body.replace(assignment, assignment + "\n          dst->fraction.ll = IMPLICIT_1;")
    return source[:start] + body + source[end:]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--gcc-tree", type=Path, required=True)
    parser.add_argument("--output", type=Path,
                        default=Path(project.ROOT).parent /
                        "gt4-thirdparty/gcc-runtime-20001003")
    default_compiler = Path(project.CONFIG["compiler"]["dir"]).expanduser() / "bin/ee-gcc"
    parser.add_argument("--compiler", type=Path, default=default_compiler)
    args = parser.parse_args()
    gcc = args.gcc_tree.resolve() / "gcc"
    output = args.output.resolve()
    compiler = args.compiler.expanduser().resolve()
    required = [gcc / "cp/exception.cc", gcc / "libgcc2.c",
                gcc / "frame-dwarf2.c", gcc / "config/fp-bit.c", compiler]
    for path in required:
        if not path.is_file():
            parser.error(f"missing source or compiler: {path}")

    exception = output / "exception"
    copy_files(gcc / "cp", exception,
               ["new.cc", "new1.cc", "new2.cc", "exception.cc"])
    copy_files(gcc / "cp/inc", exception,
               [p.name for p in sorted((gcc / "cp/inc").iterdir()) if p.is_file()])
    copy_files(gcc, exception, ["eh-common.h", "gansidecl.h"])
    copy_files(gcc.parent / "include", exception, ["ansidecl.h"])
    (exception / "tconfig.h").write_text("#define BITS_PER_UNIT 8\n", encoding="ascii")
    (exception / "stddef.h").write_text(STDDEF, encoding="ascii")

    unwind = output / "unwind"
    copy_files(gcc, unwind, ["libgcc2.c", "libgcc2.h", "frame-dwarf2.c", "frame.c",
                              "frame.h", "dwarf2.h", "tsystem.h", "machmode.h",
                              "machmode.def", "defaults.h", "gansidecl.h", "eh-common.h"])
    copy_files(gcc.parent / "include", unwind, ["ansidecl.h"])
    (unwind / "stddef.h").write_text(STDDEF, encoding="ascii")
    (unwind / "tconfig.h").write_text(TARGET, encoding="ascii")
    (unwind / "gthr.h").write_text(THREADS, encoding="ascii")
    # The EE layout is inferred from independently matching field accesses:
    # base_offset=0x10, reg_or_offset=0x20, cfa_reg=0x3f8, saved=0x3fc,
    # indirect=0x477, sizeof(frame_state)=0x478.
    frame = (unwind / "frame.h").read_text()
    before = "  long cfa_offset;\n  long args_size;"
    after = "  long base_offset;\n  char indirect;"
    if frame.count(before) != 1 or frame.count(after) != 1:
        parser.error("frame.h does not have the expected public snapshot layout")
    frame = frame.replace(before, "  long cfa_offset;\n  long base_offset;\n  long args_size;")
    frame = frame.replace(after, "  char indirect;")
    (unwind / "frame.h").write_text(frame, encoding="utf-8")
    preprocess(compiler, unwind, "libgcc2.c", "libgcc-eh.c", ["L_eh"])
    preprocess(compiler, unwind, "frame-dwarf2.c", "frame-runtime.c", ["L_eh"])

    softfloat = output / "softfloat"
    copy_files(gcc / "config", softfloat, ["fp-bit.c", "fp-bit.h"])
    original_fp = (softfloat / "fp-bit.c").read_text()
    target_fp = ps2_unpack(ps2_pack(ps2_softfloat(original_fp), single=True), single=True)
    target_double = ps2_unpack(ps2_pack(original_fp, single=False), single=False)
    (softfloat / "fp-bit-ps2.c").write_text(target_fp, encoding="utf-8")
    (softfloat / "fp-bit-ps2-double.c").write_text(target_double, encoding="utf-8")
    (softfloat / "ps2-rounding.patch").write_text("".join(difflib.unified_diff(
        original_fp.splitlines(keepends=True), target_fp.splitlines(keepends=True),
        fromfile="public/fp-bit.c", tofile="gt4/fp-bit-ps2.c")), encoding="utf-8")
    (softfloat / "ps2-double.patch").write_text("".join(difflib.unified_diff(
        original_fp.splitlines(keepends=True), target_double.splitlines(keepends=True),
        fromfile="public/fp-bit.c", tofile="gt4/fp-bit-ps2-double.c")), encoding="utf-8")
    preprocess(compiler, softfloat, "fp-bit-ps2-double.c", "double.c",
               ["US_SOFTWARE_GOFAST", "NO_DENORMALS", "FLOAT_BIT_ORDER_MISMATCH"])
    preprocess(compiler, softfloat, "fp-bit-ps2.c", "float.c",
               ["US_SOFTWARE_GOFAST", "FLOAT", "NO_NANS", "NO_DENORMALS",
                "FLOAT_BIT_ORDER_MISMATCH"])
    (output / "runtime-staging.json").write_text(json.dumps({
        "source": str(args.gcc_tree.resolve()), "compiler": str(compiler),
        "snapshot": "2000-10-03", "frame_registers": 122,
        "frame_layout_adjustment": "base_offset moved before args_size",
        "thread_interface": "reconstructed semaphore ABI; SDK functions remain external",
        "float_adjustments": "no NaN handling, extended exponent range, flush/truncate packing, no multiply/divide guard rounding",
        "double_adjustments": "flush/truncate packing; unpack infinity retains exponent bias and implicit fraction",
        "preprocessor": "original ee-gcc -E -C; public copyright notices retained",
    }, indent=2) + "\n", encoding="utf-8")
    print(f"Staged public GCC allocation, exception, unwind and softfloat sources in {output}")


if __name__ == "__main__":
    main()
