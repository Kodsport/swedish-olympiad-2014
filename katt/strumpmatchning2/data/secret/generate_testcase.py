import sys
import random

N, max_color, seed = map(int, sys.stdin.readline().split(" "))

random.seed(seed)

K = random.randint(1, N / 2)
l = [random.randrange(1, max_color) for _ in xrange(N)]

print N, K
print ' '.join(map(str, l))
