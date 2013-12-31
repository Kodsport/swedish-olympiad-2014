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

for x in a:
    if is_cons(x) and random.random() < p:
        b = b + x + 'o' + x
    else:
        b = b + x

assert len(a) <= N
assert len(b) <= N

print a
print b
