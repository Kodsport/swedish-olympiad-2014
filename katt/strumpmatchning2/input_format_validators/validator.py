#/usr/bin/env python

import re
import sys

int_re = "^[1-9][0-9]*$"
two_ints_re = "^[1-9][0-9]* [1-9][0-9]*$"

line = sys.stdin.readline()
assert re.match(two_ints_re, line)

N, K = map(int, line.split())

assert 2 <= N <= 10 * 1000
assert 2 <= 2 * K <= N

line = sys.stdin.readline()
colors = map(int, line.split())

assert len(colors) == N

for color in colors:
    assert 1 <= color <= 10 ** 15

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
