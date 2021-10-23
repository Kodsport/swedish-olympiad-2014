#/usr/bin/env python
import re
import sys

interval_re = "\d\d:\d\d-\d\d:\d\d"
int_re = "(0|[1-9][0-9]*)"

first_re = "^" + int_re + "$"

line = sys.stdin.readline()
assert re.match(first_re, line)
N = int(line)

assert 1 <= N <= 1000

for i in xrange(N):
    line = sys.stdin.readline()
    intervals = line.split()
    assert len(intervals) > 0
    assert re.match(first_re, intervals[0])
    k = int(intervals[0])

    temp_re = "^" + int_re
    if k > 0:
        temp_re = temp_re + " "
    for j in xrange(k):
        if j != 0:
            temp_re = temp_re + " "
        temp_re = temp_re + interval_re
    temp_re = temp_re + "$"

    # match entire line at once \o/
    #assert re.match(temp_re, line)

    assert 0 <= k <= 1440
    assert len(intervals) == k+1

    times = []

    for j in xrange(1,k+1):
        word = intervals[j]
        sword = intervals[j].split('-')

        sh, sm = map(int, sword[0].split(':'))
        eh, em = map(int, sword[1].split(':'))

        assert 0 <= sh <= 23
        assert 0 <= eh <= 23

        assert 0 <= sm <= 60
        assert 0 <= em <= 60

        s = sh * 60 + sm
        e = eh * 60 + em
        times.append((s,e))

    for i in xrange(len(times)):
        if i > 0:
            assert times[i-1][0] < times[i][1]


line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
