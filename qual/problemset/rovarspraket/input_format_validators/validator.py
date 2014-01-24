#/usr/bin/env python
import re
import sys
input_re = "^[a-z]+$"

line = sys.stdin.readline()
assert re.match(input_re, line)
assert 1 <= len(line) <= 1000
line = sys.stdin.readline()
assert re.match(input_re, line)
assert 1 <= len(line) <= 1000

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
