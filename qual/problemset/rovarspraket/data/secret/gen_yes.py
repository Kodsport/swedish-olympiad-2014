import string
import sys
import random

def is_cons(c):
    return c not in ("a","e","i","o","u","y")

line = sys.stdin.readline().strip().split()

N = int(line[0])
p = float(line[1])
a = ''.join(random.choice(string.ascii_lowercase) for x in range(N/3))
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

print areal
print b
