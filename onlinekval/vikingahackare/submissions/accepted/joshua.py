#!/usr/bin/python3

from textwrap import wrap
n = int(input())
dabois = {}
for i in range(n):
    binary, val = [i for i in input().split()]
    dabois[val] = binary

binstring = input()
binstring = wrap(binstring, 4)


out = ""
for i in binstring:
    if i not in dabois:
        out += "?"
    else:
        out += dabois[i]

print(out)
