#!/usr/bin/python
from sys import stdin
import sys
import re

integer = "(0|-?[1-9]\d*)"
line = stdin.readline()
assert re.match(integer + "\n", line)
N=int(line)
assert (N>0 and N<=1000)
taken=[]
for i in range(N):
    line = stdin.readline()
    assert re.match(integer + "\n", line)
    k=int(line)
    assert (k>0 and k<=1000)
    assert(not k in taken)
    taken.append(k)
line = stdin.readline()
assert len(line)==0
# Nothing to report
sys.exit(42)

