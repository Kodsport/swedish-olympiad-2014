#/usr/bin/env python
import re
import sys
input_re = "^[a-z]+$"

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

maxn = int(cmdlinearg('maxn'))

line = sys.stdin.readline()
assert re.match(input_re, line)
assert 1 <= len(line) <= maxn
line = sys.stdin.readline()
assert re.match(input_re, line)
assert 1 <= len(line) <= maxn

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
