import sys
import random

# N - number of fishes
# h - height
# mode - ["lowdist"|"noeat"|"nomideat"|"hardest"]
# seed - random seed

MODES = ["lowdist", "noeat", "nomideat", "hardest"]

inputs = sys.stdin.readline().strip().split()

N = int(inputs[0])
h = int(inputs[1])
mode = str(inputs[2])
seed = int(inputs[3])

assert N >= 2
assert N <= 100 * 1000
assert 20 <= h and h <= 50
assert mode in MODES

difficulty = MODES.index(mode)
difficulty_nomideat = MODES.index('nomideat')
difficulty_noeat = MODES.index('noeat')

# Well you will almost always go above xAim, so lets undershoot
xAim = 10 * 1000 if mode == 'lowdist' else int(1e17)

random.seed(seed)


def transition_factor(size_from, size_to):
    gets_smaller = size_from >= size_to  # or as big
    if gets_smaller:
        return 1
    elif size_to == 1:  # It must be mid eats small
        return (1 * (difficulty <= difficulty_nomideat)) + 1
    elif size_from == 0:  # large eats small
        # So if we have nomideat, mediums could be generated as well, so we
        # can't return a total sum of 1 then.
        v = 2 if difficulty <= difficulty_noeat else mode == 'nomideat'
        return v + 1
    elif size_from == 1:  # large eats mid
        return (0.5 * (difficulty <= difficulty_noeat)) + 1
    assert False


def round_up(x, size):
    val = [2, 2, 6][size]
    return x + (val - (x % val))  # I think bug is ok


def lessen_ambition(x, old_size, new_size):
    if new_size == 0:
        return 0
    if transition_factor(old_size, new_size) > 1.1 and x >= xAim:
        # I *think* you might aswell just return 0 here
        return lessen_ambition(x, old_size, new_size - 1)
    return new_size


def tail_height(size):
    return [1, 2, 4][size]


fishes = []
x = 0
last_smallest = 2  # 2 == Stor
HEIGHT_OF_US = 7

while len(fishes) < N:
    max_size = lessen_ambition(x, last_smallest, random.randint(0, 2))
    xInc = int(x * (transition_factor(last_smallest, max_size) - 1))
    xInc += random.randint(1, 100)
    if mode == 'hardest' and random.randint(1, 100) >= 90:
        # If mode is hardest, then transition_factor() will never return > 1
        xInc += random.randint(1, 123456789)
    x += xInc
    x = round_up(x, max_size)
    y = random.randint(0, h)
    smallest_outputted = 2
    while y < h and len(fishes) < N:
        size = random.randint(0, max_size)
        ok = y - tail_height(size) >= 0 and y + tail_height(size) < h
        large_fish_is_at_top = size == 2 and y >= h - 4 - HEIGHT_OF_US - 1
        # To ensure we always can survive by hiding at top square
        ok = ok and not large_fish_is_at_top
        if ok:
            fishes.append((size, x, y + 1))
            smallest_outputted = min(smallest_outputted, size)
        y += max(4 + tail_height(size) + 1, random.randint(0, h))
    last_smallest = smallest_outputted

random.shuffle(fishes)

print N, h
for fish in fishes:
    (size, x, y) = fish
    print ['L', 'M', 'S'][size], x, y
