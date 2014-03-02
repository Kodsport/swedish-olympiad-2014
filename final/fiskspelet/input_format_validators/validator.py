#/usr/bin/env python
import re
import sys
import collections
int_re = "^(0|\-?[1-9][0-9]*)$"
two_ints_re = "^(0|\-?[1-9][0-9]*) (0|\-?[1-9][0-9]*)$"
fish_re = "^(L|M|S) (0|\-?[1-9][0-9]*) (0|\-?[1-9][0-9]*)$"

# Initialize mode
MODES = ["lowdist", "noeat", "nomideat", "hardest"]
assert len(sys.argv) == 2
mode = sys.argv[1]
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
    x, y = map(int, [x, y])
    assert 1 <= x <= (10 ** 18)
    if mode == 'lowdist':
        assert x <= 10 ** 4
    assert 1 + tail_height(size) <= y <= h - tail_height(size)
    if size == 2:
        # No large fish may be in top (see the note in the generator)
        assert y <= h - 7 - 4
    assert x % (2 if size <= 1 else 6) == 0
    fishes.append(Fish(x, y, size))

line = sys.stdin.readline()
assert len(line) == 0

fishes.sort()

# Check non-overlapping-ness (a y dimensional property)
i = 0
while i < N:
    j = i
    f0 = fishes[i]
    y_highest = -100
    while j < N and f0.x == fishes[j].x:
        f = fishes[j]
        y_low = f.y - tail_height(f.size)
        y_high = f.y + tail_height(f.size)
        assert y_highest < y_low
        y_highest = y_high
        j += 1
    i = j

# Check eatness-constraints (a x dimensional property)
i = 0
righest_liten = 0
righest_mellan = 0
while i < N:
    j = i
    f0 = fishes[i]
    rl = righest_liten
    rm = righest_mellan
    while j < N and f0.x == fishes[j].x:
        f = fishes[j]
        if f.size == 0:
            rl = f.x
        elif f.size == 1:
            if difficulty <= difficulty_nomideat:
                assert righest_liten * 2 < f.x
            rm = f.x
        elif f.size == 2:
            if difficulty <= difficulty_noeat:
                assert righest_liten * 3 < f.x
                assert righest_mellan * 1.5 < f.x
        j += 1

    # Update globals
    righest_stor = rl
    righest_mellan = rm
    i = j


sys.exit(42)
