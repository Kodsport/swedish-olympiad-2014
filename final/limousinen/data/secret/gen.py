import sys
import random

# N - number of persons
# amplitude - max coordinate amplitude
# fraction - fraction of people who will make it (roughly)
# seed - random seed

inputs = sys.stdin.readline().strip().split()

N = int(inputs[0])
amplitude = int(inputs[1])
fraction = float(inputs[2])
seed = int(inputs[3])

random.seed(seed)

coords = []
S = 0
for i in xrange(N):
    x = random.randrange(-amplitude, amplitude)
    y = random.randrange(-amplitude, amplitude)
    coords.append((x,y))
    S = S + abs(x) + abs(y);

print N, min(int(2*S * fraction), 10**9)

for c in coords:
    print c[0], c[1]
