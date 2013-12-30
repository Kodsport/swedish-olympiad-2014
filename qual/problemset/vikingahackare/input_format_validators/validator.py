#/usr/bin/env python
import re
import sys

char_re = "^[a-zA-Z0-9]$"
bin_re = "^[01]+$"
int_re = "^(0|[1-9][0-9]*)$"

line = sys.stdin.readline()
assert re.match(int_re, line)
T = int(line)
assert T >= 0 and T <= 16
for i in xrange(T):
	line = sys.stdin.readline()
	split = line.split()
	assert re.match(char_re, split[0])
	assert re.match(bin_re, split[1])
	assert len(split[1]) == 4
line = sys.stdin.readline()
assert re.match(bin_re, line)
assert len(line.strip()) % 4 == 0
line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
