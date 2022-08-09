#!/usr/bin/env python3
import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

w_low = int(cmdlinearg('w_low'))
w_high = int(cmdlinearg('w_high'))
random.seed(int(cmdlinearg('seed')))

def add(arr, seen, c):
    while True:
        a = random.randint(0,len(arr)-1)
        if a not in seen:
            seen.append(a)
            arr[a] = c
            return

# Does not always generate a winnable map
w = random.randint(w_low,w_high)
print(w,1)
line = ['.' for i in range(w)]
seen = []
add(line,seen,'B')
add(line,seen,'S')
add(line,seen,'U')
print("".join(line))
