#/usr/bin/env python
import re
import sys

firstline_re = "^(0|[1-9][0-9]*) (0|[1-9][0-9]*)$"
int_re = "^(0|[1-9][0-9]*)$"

line = sys.stdin.readline()
assert re.match(firstline_re, line)

N, K = map(int, line.split())
assert 1 <= N <= 1000
assert 1 <= K <= 1000

line = sys.stdin.readline()
arr = line.split()

assert len(arr) == N
for x in arr:
    re.match(int_re, x)
    assert 1 <= int(x) <= 10**9

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
