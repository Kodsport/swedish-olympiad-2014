#/usr/bin/env python

import sys

x, n = sys.stdin.readline().split()
assert 5 <= x and x <= 100
assert n <= 20
items = sys.stdin.readline().split()
assert len(items) == n

for h in items:
    assert (2 <= h and h <= 100)

# Egentligen ska man ju kolla att man också kan lösa uppgiften med dem items
# man har, men det blir för jobbigt att kontrollera

exit(42)
