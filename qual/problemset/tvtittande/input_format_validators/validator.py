#/usr/bin/env python
import re
import sys

first_re = "^\d$"
interval_re = "\d\d:\d\d-\d\d:\d\d"
int_re = "(0|[1-9][0-9]*)"

line = sys.stdin.readline()
assert re.match(first_re, line)
N = int(line)

for i in xrange(N):
    line = sys.stdin.readline()
    stuff = line.split()
    assert len(stuff) > 0
    assert re.match(int_re, stuff[0])
    k = int(stuff[0])
    assert len(stuff) == k+1
    for j in xrange(1,k+1):
        assert re.match(interval_re, stuff[j])

sys.exit(42)
