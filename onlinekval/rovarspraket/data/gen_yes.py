import string
import sys
import random

def is_cons(c):
    return c not in ("a","e","i","o","u","y")

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
areal = ""

for x in a:
    if is_cons(x) and random.random() < p:
        b = b + x + 'o' + x
        areal = areal + x
    else:
        if is_cons(x) and random.random() < 0.3:
            areal = areal + x + 'o' + x
            b = b + x + 'o' + x
        else:
            areal = areal + x
            b = b + x

assert len(areal) <= N
assert len(b) <= N

print(areal)
print(b)
