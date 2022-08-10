#!/usr/bin/env python
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


n_max = 12 if int(cmdlinearg('small')) else 20

line = sys.stdin.readline()

# No leading zeros
assert(line.split()[0][0]!='0' and line.split()[1][0]!='0')

x, n = map(int, line.split())
assert 5 <= x and x <= 100
assert n <= n_max
items = map(int, sys.stdin.readline().split())
assert len(items) == n

for h in items:
    assert (2 <= h and h <= 100)

line = sys.stdin.readline()
assert len(line) == 0

exit(42)
