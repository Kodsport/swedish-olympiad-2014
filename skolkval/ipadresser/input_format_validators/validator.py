#/usr/bin/env python
import re
import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

input_re = "^\d{4,12}$"
line = sys.stdin.readline()
assert re.match(input_re, line)


if int(cmdlinearg('no_zero')):
    assert("0" not in line)
line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
