# -*- coding: UTF-8 -*-
#/usr/bin/env python3
import re
import sys
input_re = "^[1-9][0-9]*$"

line = sys.stdin.readline()
assert re.match(input_re, line)

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


max_n = int(cmdlinearg('max_n'))
small_ans= int(cmdlinearg('small_ans'))

assert line[-1] == '\n'
assert len(line) <= max_n


def m3(n):
    return ((n % 3) + 3) % 3

# Lösning stulen från simon.cpp
# Gör alla beräkningar utan mod och kolla om svar < mod
if small_ans:
    assert len(line) <= 21
    line = reversed(line[:-1])

    dp = [0]*3
    next = [0]*3
    dp[0] = 1
    res = 0
    for c in line:
        d = ord(c)-ord('0')
        if d!=0:
            res = (res+dp[m3(-d)])
        else:
            res += 1

        next = list([i for i in dp])

        for i in range(3):
            next[m3(i+d)] = next[m3(i+d)]+dp[i]

        next, dp = dp, next

    assert res < 10**9



line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
