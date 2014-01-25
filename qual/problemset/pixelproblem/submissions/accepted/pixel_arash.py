# Arash Rouhani
# Testa alla dimensioner, ranka alla pixlar mot nedanstraende, O(N)

##### SENARE # Testa alla dimensioner, survival of fittest, O(N*log(N))

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


def score(w, pic):
    coords = pre_coords[0:100]
    return sum([compare(pic.rgbs[i], pic.rgbs[i + w]) for i in coords])

pixels = splitEvery(flat_pixels, 3)
rgbs = map(lambda triple: RGB(*triple), pixels)
pic = Picture(num_pixels, rgbs)
assert(pic.num_pixels == len(rgbs))

widths = range(5, max_width + 1)

scores = [(s, w) for w in widths for s in [score(w, pic)]]

scores.sort()

print (scores[0][1])
