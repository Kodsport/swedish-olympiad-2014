#!/usr/bin/python3

import re
import sys

int_re = "^[1-9][0-9]*$"
two_ints_re = "^[1-9][0-9]* [1-9][0-9]*$"

line = sys.stdin.readline()
assert re.match(two_ints_re, line)

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print(("missing parameter", name))
        exit(1)
    return default

max_n = int(cmdlinearg('max_n'))
max_f = int(cmdlinearg('max_f'))
 

N, K = list(map(int, line.split()))

assert 2 <= N <= max_n
assert 2 <= 2 * K <= N

line = sys.stdin.readline()
colors = list(map(int, line.split()))

assert len(colors) == N

for color in colors:
    assert 1 <= color <= max_f

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
