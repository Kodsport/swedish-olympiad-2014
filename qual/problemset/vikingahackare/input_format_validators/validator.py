#/usr/bin/env python
import re
import sys

char_re = "^[a-zA-Z0-9]$"
bin_re = "^[01]+$"
int_re = "^(0|[1-9][0-9]*)$"
pair_re = "^[a-zA-Z0-9] [01]+$"

line = sys.stdin.readline()
assert re.match(int_re, line)
T = int(line)
assert T >= 1 and T <= 16
used = []
for i in xrange(T):
	line = sys.stdin.readline()
	assert re.match(pair_re, line)
	assert len(line.split()) == 2
	c, bits = line.split()
	assert bits not in used
	used.append(bits)
	assert re.match(char_re, c)
	assert re.match(bin_re, bits)
	assert len(bits) == 4
line = sys.stdin.readline()
assert re.match(bin_re, line)
assert len(line.strip()) % 4 == 0
assert len(line.strip()) >= 4
line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
