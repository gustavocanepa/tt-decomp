#!/usr/bin/env python3
"""Preprocess a configured public library with its original target compiler.

The target config names `preprocess_from`, another library configuration whose
public source directory supplies the input and headers. Output remains outside
the repository, at the target configuration's `source` path.
"""
import argparse
import json
import os
import shlex
import shutil
import subprocess
import tempfile
from pathlib import Path

import libmatch
import project


def preprocess_command(compiler_command):
    command = shlex.split(os.path.expandvars(compiler_command))
    if not command or "cc_as.sh" in compiler_command or "-c" not in command:
        raise ValueError("staging requires a direct GCC compile profile")
    index = command.index("-c")
    command[index:index + 1] = ["-E", "-C"]
    return command


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("name", help="target config/libs/NAME.toml")
    args = parser.parse_args()
    target = libmatch.load_config(args.name)
    parent_name = target.get("preprocess_from")
    if not parent_name:
        parser.error("target configuration must name preprocess_from")
    parent = libmatch.load_config(parent_name)
    source, output = Path(parent["source"]).resolve(), Path(target["source"]).resolve()
    if source == output or source in output.parents:
        parser.error("output must be separate from the public input source tree")
    try:
        command = preprocess_command(project.compiler_command(target.get("compiler")))
    except ValueError as error:
        parser.error(str(error))
    for name in target["files"]:
        relative = Path(name)
        if relative.is_absolute() or ".." in relative.parts:
            parser.error(f"source file must be relative to the library: {name}")
        if not (source / relative).is_file():
            parser.error(f"missing public source: {source / relative}")
    output.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="gt4-public-library-") as temporary:
        work = Path(temporary) / "source"
        shutil.copytree(source, work)
        flags = ["-I.", "-I" + str(Path(project.ROOT) / "include/shim")]
        flags += ["-D" + value for value in target.get("defines", [])]
        for name in target["files"]:
            result = subprocess.run(command + flags + [name], cwd=work,
                                    capture_output=True, text=True, check=True)
            destination = output / name
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(result.stdout, encoding="utf-8")
    (output / "staging.json").write_text(json.dumps({
        "library": parent_name, "version": parent.get("version"),
        "public_source": str(source), "compiler": command,
        "files": target["files"], "comments_preserved": True,
    }, indent=2) + "\n", encoding="utf-8")
    print(f"Preprocessed {len(target['files'])} public {parent_name} sources in {output}")


if __name__ == "__main__":
    main()
