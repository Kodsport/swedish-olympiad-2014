#/usr/bin/env python

import re
import sys

first_re = "^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*$"
relation_re = "^[1-9][0-9]* (<|=|<=) [1-9][0-9]*$"

line = sys.stdin.readline()
assert re.match(first_re, line)

N, M, R = map(int, line.split())

assert 1 <= N <= 100000
assert 1 <= M <= 100000
assert 1 <= R <= 500000

# TODO: use relation_re here

sys.exit(42)
