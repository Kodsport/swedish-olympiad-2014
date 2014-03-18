from __future__ import division
import math
import string
import sys
import random

inputs = sys.stdin.readline().strip().split()

# D represents how far back to pick the large value from, and F represents how
# large a range [0, F*i) to pick a small value from. Together they determine
# the growth rate of the string lengths. Tweak by running lattexter_stats.cpp.
N = int(inputs[0])
Q = int(inputs[1])
D = int(inputs[2])
F = float(inputs[3])
seed = int(inputs[4])

random.seed(seed)

def rand_string():
    wordlen = random.randrange(1, 10)
    char_set = string.ascii_lowercase
    return ''.join(random.sample(char_set*wordlen, wordlen))

print(str(N) + ' ' + str(Q))
lens = []
for i in range(N):
    first = random.randrange(max(int(i * F), 1))
    second = i - 1 - random.randrange(D)
    if second < 0:
        s = rand_string()
        print('0 ' + s)
        lens.append(len(s))
    else:
        if random.choice([True, False]):
            first, second = second, first
        print(str(first+1) + ' ' + str(second+1))
        lens.append(lens[first] + lens[second])

last_len = lens[-1]
sys.stderr.write('length ' + str(last_len) + ', log10 = ' + str(math.log10(last_len)) + '\n')

for i in range(Q):
    ind = random.randrange(min(last_len, 1e18))
    print(ind+1)
