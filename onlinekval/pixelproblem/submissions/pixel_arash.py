#!/usr/bin/python3
# Arash Rouhani
# Testa alla dimensioner, survival of fittest, O(N*log(N))

from sys import stdin
from collections import namedtuple
import random
num_pixels = int(stdin.readline())
flat_pixels = map(lambda x: int(x), stdin.readline().split())
RGB = namedtuple('RGB', ['r', 'g', 'b'])
Picture = namedtuple('Picture', ['num_pixels', 'rgbs'])

random.seed(0)

max_width = num_pixels / 5
pre_coords = range(num_pixels - max_width)
random.shuffle(pre_coords)


def splitEvery(xs, n):
    return [xs[i:(i + n)] for i in range(0, len(xs), n)]


def square(x):
    return x * x


def compare(a, b):
    return square(a.r - b.r) + square(a.g - b.g) + square(a.b - b.b)


def score(w, takes, pic):
    coords = pre_coords[0:takes]
    return sum([compare(pic.rgbs[i], pic.rgbs[i + w]) for i in coords])

pixels = splitEvery(flat_pixels, 3)
rgbs = map(lambda triple: RGB(*triple), pixels)
pic = Picture(num_pixels, rgbs)
assert(pic.num_pixels == len(rgbs))

takes = 10
widths = range(5*5, (max_width + 1) / 5)

while len(widths) > 1:
    wp = [(s, w) for w in widths for s in [score(w, takes, pic)]]
    wp.sort()
    widths = [w for (_s, w) in wp[0:(len(wp) / 2)]]
    takes *= 2

print(widths[0])
