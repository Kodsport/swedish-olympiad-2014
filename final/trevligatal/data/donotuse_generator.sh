#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution simon.cpp

compile gen.py
compile trevligatal_overflow.cpp

# Sample
samplegroup
limits max_n=12 small_ans=1 
sample 1
sample 2
sample 3
sample 4
sample 5
sample 6

# n=6
group group1 20
limits max_n=7 small_ans=1
tc g1-1 gen n=6 seed=610
tc g1-2 gen n=3 seed=620
tc g1-3 gen n=5 seed=630
tc g1-4 gen n=6 seed=640
tc g1-5 gen n=6 seed=611
tc g1-6 gen n=3 seed=621
tc g1-7 gen n=5 seed=631
tc g1-8 gen n=6 seed=641

# n=20
group group2 20
limits max_n=21 small_ans=1
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
limits max_n=1001 small_ans=0
tc g3-1 gen n=822  seed=110
tc g3-2 gen n=205  seed=120
tc g3-3 gen n=1000 seed=130
tc g3-4 gen n=678  seed=140
tc g3-5 gen n=822  seed=111
tc g3-6 gen n=205  seed=121
tc g3-7 gen n=1000 seed=131
tc g3-8 gen n=678  seed=141

# n=1e5
group group4 40
limits max_n=100001 small_ans=0
include_group sample
tc g4-1  gen n=16923  seed=310
tc g4-2  gen n=92952  seed=320
tc g4-3  gen n=100000 seed=330
tc g4-4  gen n=32949  seed=340
tc g4-5  gen n=16923  seed=311
tc g4-6  gen n=92952  seed=321
tc g4-7  gen n=100000 seed=331
tc g4-8  gen n=32949  seed=341
tc g4-9  gen n=16923  seed=312
tc g4-10 gen n=92952  seed=322
tc g4-11 gen n=100000 seed=332
tc g4-12 gen n=32949  seed=342
tc g4-13 gen n=16923  seed=313
tc g4-14 gen n=92952  seed=323
tc g4-15 gen n=100000 seed=333
tc g4-16 gen n=32949  seed=343
tc g4-17 trevligatal_overflow
