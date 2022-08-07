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

n = int(cmdlinearg('n'))
random.seed(int(cmdlinearg('seed')))

seen = set()

print(n)
for i in range(n):
    while True:
        num = random.randint(1, 1000)
        if num not in seen:
            seen.add(num)
            print(num)
            break