from __future__ import division
import math
import string
import sys
import random

inputs = sys.stdin.readline().strip().split()

lim = int(1e18)

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

# D represents how far back to pick the large value from, and F represents how
# large a range [0, F*i) to pick a small value from. Together they determine
# the growth rate of the string lengths. Tweak by running lattexter_stats.cpp.

# small, n, q, d, f
restrict_string_length = bool(int(cmdlinearg('small')))
N = int(cmdlinearg('n'))
Q = int(cmdlinearg('q'))
D = int(cmdlinearg('d'))
F = float(cmdlinearg('f'))
nstrings = 5

random.seed(int(cmdlinearg('seed')))

def rand_string():
    wordlen = random.randrange(1, 10)
    char_set = string.ascii_lowercase
    return ''.join(random.sample(char_set*wordlen, wordlen))

print(str(N) + ' ' + str(Q))
lens = []
for i in range(N):
    first = random.randrange(max(int(i * F), 1))
    second = i - 1 - random.randrange(D)
    if second < 0 or i < nstrings:
        s = rand_string()
        print('0 ' + s)
        lens.append(len(s))
    else:
        if random.choice([True, False]):
            first, second = second, first
        print(str(first+1) + ' ' + str(second+1))
        l = lens[first] + lens[second]
        if l > lim and restrict_string_length:
            sys.stderr.write('TOO LARGE STRING')
            sys.exit()
        lens.append(l)

last_len = lens[-1]
#sys.stderr.write('length ' + str(last_len) + ', log10 = ' + str(math.log10(last_len)) + '\n')

for i in range(Q):
    ind = random.randrange(min(last_len, lim))
    print(ind+1)
