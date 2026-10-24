#!/usr/bin/env python3
"""Keep real translation-unit context around a mechanically varied C function."""
import argparse
from pathlib import Path
import libmatch


def function_span(source, name):
    lines = source.splitlines(keepends=True)
    definitions = libmatch.find_definitions([(line.rstrip("\r\n"), "context.c") for line in lines])
    found = [d for d in definitions if d.kind == "func" and d.name == name]
    if len(found) != 1:
        raise ValueError(f"expected one definition of {name}, found {len(found)}")
    definition = found[0]
    return lines, definition.sig_start, definition.body_end + 1


def restore(context, candidate, name):
    original, first, last = function_span(context, name)
    varied, new_first, new_last = function_span(candidate, name)
    return "".join(original[:first] + varied[new_first:new_last] + original[last:])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("context")
    parser.add_argument("candidate")
    parser.add_argument("name")
    parser.add_argument("output")
    args = parser.parse_args()
    result = restore(Path(args.context).read_text(), Path(args.candidate).read_text(), args.name)
    Path(args.output).write_text(result)


if __name__ == "__main__":
    main()
