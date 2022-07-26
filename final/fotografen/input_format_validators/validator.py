#/usr/bin/env python

import re
import sys

line1_re = "^[1-9][0-9]* [1-9][0-9]*$"
line2_re = "^[UNVH]+$"

line = sys.stdin.readline()
assert re.match(line1_re, line)

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


max_n = int(cmdlinearg('max_n'))

N, k = map(int, line.strip().split())

assert 1 <= N <= max_n
assert 1 <= k <= N

line = sys.stdin.readline()
assert re.match(line2_re, line)

assert len(line) == N+1

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
