#/usr/bin/env python
import re
import sys

int_re = "^(0|[1-9][0-9]*)$"

line = sys.stdin.readline()
assert re.match(int_re, line)

N = int(line)
assert 1 <= N <= 250000

line = sys.stdin.readline()
arr = line.split()

assert len(arr) == 3*N
for x in arr:
    re.match(int_re, x)
    assert 0 <= int(x) <= 255

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
