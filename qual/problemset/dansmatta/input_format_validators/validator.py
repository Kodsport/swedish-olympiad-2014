#/usr/bin/env python
import re
import sys

char_re = "^[UNVH]{1,2}$"
int_re = "^(0|[1-9][0-9]*)$"

line = sys.stdin.readline()
assert re.match(int_re, line)
n = int(line)
assert 1 <= n <= 100000

for i in xrange(n):
	line = sys.stdin.readline()
	assert re.match(char_re, line)
	if len(line.strip()) == 2:
		assert line[0] != line[1]

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
