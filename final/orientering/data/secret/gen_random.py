import sys
import random

# N hojd
# M bredd
# seed

inp = sys.stdin.readline().strip().split()
N, M, seed = map(int, inp)

random.seed(seed)
values = ['^', '>', 'v', '<'] + (random.randint(0, 8) * ['.'])

# vary N and M a bit
N -= random.randint(0, 5)
M -= random.randint(0, 5)

# We dont know if this is reachable or not, but hopefully it is.
# Otherwise validator will find out! :)
R = random.randint(1, N)
C = random.randint(1, M)


print N, M, R, C

for i in xrange(N):
    print ''.join([random.choice(values) for _ignore in xrange(M)])
