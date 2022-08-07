#!/usr/bin/env python2
import string
import sys
import random

def is_cons(c):
    return c not in ("a","e","i","o","u","y")

line = sys.stdin.readline().strip().split()

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

N = int(cmdlinearg('n'))
p = float(cmdlinearg('p'))
s = cmdlinearg('seed')

s_int = 1337 
for x in s:
    s_int += ord(x)

random.seed(s_int)

a = ''.join([random.choice(string.ascii_lowercase) for x in range(N//3)])
b = ""



for x in a:
    if is_cons(x) and random.random() < p:
        b = b + x + 'o' + x
    else:
        b = b + x

# fuck it up
pos = random.randrange(len(b))

b = b[:pos] + random.choice(string.ascii_lowercase) + b[pos:]

assert len(a) <= N
assert len(b) <= N

print(a)
print(b)
