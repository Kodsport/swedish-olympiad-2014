#!/usr/bin/python3

from sys import stdin
import sys
import re

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

maxn = int(cmdlinearg('maxn'))

integer = "(0|-?[1-9]\d*)"
line = stdin.readline()
assert re.match(integer + "\n", line)
N=int(line)
assert (N>0 and N<=maxn)
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

