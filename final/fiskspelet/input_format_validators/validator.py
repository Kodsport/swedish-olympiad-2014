#/usr/bin/env python
import re
import sys
import collections
int_re = "^(0|\-?[1-9][0-9]*)$"
two_ints_re = "^(0|\-?[1-9][0-9]*) (0|\-?[1-9][0-9]*)$"
fish_re = "^(L|M|S) (0|\-?[1-9][0-9]*) (0|\-?[1-9][0-9]*)$"

# Initialize mode
MODES = ["lowdist", "noeat", "nomideat", "hardest"]
assert len(sys.argv) == 1
mode = sys.argv[0]
assert mode in MODES
difficulty = MODES.index(mode)
difficulty_nomideat = MODES.index('nomideat')
difficulty_noeat = MODES.index('noeat')

# Start reading from stdin
line = sys.stdin.readline()
words = line.split()
assert re.match(two_ints_re, line)

N, h = map(int, words)

assert 1 <= N <= 100000
assert 20 <= h <= 50

# I must sort them later, so I do this now
Fish = collections.namedtuple('Fish', ['x', 'y', 'size'])
fishes = []


def tail_height(size):
    return [1, 2, 4][size]

for i in xrange(N):
    l = sys.stdin.readline()
    assert re.match(fish_re, l)
    size, x, y = l.split()
    size = {'L': 0, 'M': 1, 'S': 2}[size]
    assert 1 <= x <= (10 ** 18)
    assert 1 + tail_height(size) <= y <= h - tail_height(size)
    if size == 2:
        # No large fish may be in top (see the note in the generator)
        assert y <= h - 7 - 4
    assert x % (2 if size <= 1 else 6) == 0
    fishes.append(Fish(x, y, size))

# TODO, check that the eating properties are filled and
# TODO, check no overlapping fishes

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
