#/usr/bin/env python

import re
import sys

int_re = "^[1-9][0-9]*$"
two_ints_re = "^[1-9][0-9]* [1-9][0-9]*$"

line = sys.stdin.readline()
assert re.match(two_ints_re, line)

A,B = map(int, line.split())

assert A <= 500
assert B <= 500

sys.exit(42)
