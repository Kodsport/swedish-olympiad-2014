#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution simon.cpp

compile gen.py
compile trevligatal_overflow.cpp

# Sample
samplegroup
limits max_n=5
sample_manual trevligatal.1
sample_manual trevligatal.2
sample_manual trevligatal.3
sample_manual trevligatal.4
sample_manual trevligatal.5
sample_manual trevligatal.6

# n=6
group group1 20
tc g1-1 gen n=6 seed=10
tc g1-2 gen n=3 seed=20
tc g1-3 gen n=5 seed=30
tc g1-4 gen n=6 seed=40
tc g1-5 gen n=6 seed=11
tc g1-6 gen n=3 seed=21
tc g1-7 gen n=5 seed=31
tc g1-8 gen n=6 seed=41

# n=20
group group2 20
tc g2-1 gen n=16 seed=10
tc g2-2 gen n=13 seed=20
tc g2-3 gen n=20 seed=30
tc g2-4 gen n=19 seed=40
tc g2-5 gen n=16 seed=11
tc g2-6 gen n=13 seed=21
tc g2-7 gen n=20 seed=31
tc g2-8 gen n=19 seed=41

# n=1000
group group3 20
tc g3-1 gen n=822 seed=10
tc g3-2 gen n=205 seed=20
tc g3-3 gen n=1000 seed=30
tc g3-4 gen n=678 seed=40
tc g3-5 gen n=822 seed=11
tc g3-6 gen n=205 seed=21
tc g3-7 gen n=1000 seed=31
tc g3-8 gen n=678 seed=41

# n=1e5
group group4 40
tc g4-1  gen n=16923  seed=10
tc g4-2  gen n=92952  seed=20
tc g4-3  gen n=100000 seed=30
tc g4-4  gen n=32949  seed=40
tc g4-5  gen n=16923  seed=11
tc g4-6  gen n=92952  seed=21
tc g4-7  gen n=100000 seed=31
tc g4-8  gen n=32949  seed=41
tc g4-9  gen n=16923  seed=12
tc g4-10 gen n=92952  seed=22
tc g4-11 gen n=100000 seed=32
tc g4-12 gen n=32949  seed=42
tc g4-13 gen n=16923  seed=13
tc g4-14 gen n=92952  seed=23
tc g4-15 gen n=100000 seed=33
tc g4-16 gen n=32949  seed=43
tc g4-17 trevligatal_overflow
