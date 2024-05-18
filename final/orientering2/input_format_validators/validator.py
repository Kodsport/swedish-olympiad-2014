#/usr/bin/env python

import re
import sys

line1_re = "^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]* [1-9][0-9]*$"
rest_lines_re = "^[\.\^\<\>v]+$"

line = sys.stdin.readline()
assert re.match(line1_re, line)

h, b, y_dest, x_dest = list(map(int, line.strip().split()))

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print(("missing parameter", name))
        exit(1)
    return default


max_n = int(cmdlinearg('max_n'))
max_m = int(cmdlinearg('max_m'))


assert 1 <= h <= max_n
assert 1 <= b <= max_m
assert 1 <= y_dest <= h
assert 1 <= x_dest <= b

for i in range(h):
    line = sys.stdin.readline().strip()
    assert re.match(rest_lines_re, line)
    assert len(line) == b

line = sys.stdin.readline()
assert len(line) == 0

# validator.cpp checks whether the instance is solvable

sys.exit(42)
