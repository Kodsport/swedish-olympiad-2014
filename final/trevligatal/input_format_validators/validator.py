#/usr/bin/env python
import re
import sys
input_re = "^[0-9]+$"

line = sys.stdin.readline()
assert re.match(input_re, line)

assert line[-1] == '\n' and len(line) <= 100001

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
