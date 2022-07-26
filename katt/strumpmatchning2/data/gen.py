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

random.seed(int(cmdlinearg('seed')))
N = int(cmdlinearg('n'))
max_color = int(cmdlinearg('max_f'))


K = random.randint(1, N / 2)
l = [random.randrange(1, max_color) for _ in xrange(N)]

print N, K
print ' '.join(map(str, l))
