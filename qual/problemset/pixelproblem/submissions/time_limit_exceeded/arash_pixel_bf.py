# Arash Rouhani
# Testa alla dimensioner, ranka alla pixlar mot nedanstraende, O(N*2)

from sys import stdin
from collections import namedtuple
num_pixels = int(stdin.readline())
flat_pixels = map(lambda x: int(x), stdin.readline().split())
RGB = namedtuple('RGB', ['r', 'g', 'b'])
Picture = namedtuple('Picture', ['num_pixels', 'rgbs'])


def splitEvery(xs, n):
    return [xs[i:(i + n)] for i in range(0, len(xs), n)]


def square(x):
    return x * x


def compare(a, b):
    return square(a.r - b.r) + square(a.g - b.g) + square(a.b - b.b)


def score(w, pic):
    h = pic.num_pixels / w

    def get(y, x):
        return pic.rgbs[(y * w) + x]

    def rating_down(y, x):
        return compare(get(y, x), get(y + 1, x))

    def rating_row(y):
        return sum([rating_down(y, x) for x in range(w)])

    num_comparisions = (h - 1) * w

    return sum([rating_row(y) for y in range(h - 1)]) / num_comparisions

pixels = splitEvery(flat_pixels, 3)
rgbs = map(lambda triple: RGB(*triple), pixels)
pic = Picture(num_pixels, rgbs)
assert(pic.num_pixels == len(rgbs))

scores = \
    [(s, w) for w in range(5, (num_pixels / 5) + 2) for s in [score(w, pic)]]

scores.sort()

print (scores[0][1])
