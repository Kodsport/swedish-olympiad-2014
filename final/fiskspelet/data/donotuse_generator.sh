#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution joshua.cpp

compile gen.py
compile gen_hard.py

# Sample
samplegroup
limits max_n=10 max_h=50 mode=hardest
sample 1
sample 2
sample 3
sample 4
sample 5
sample 6
sample 7

group group1 20
limits max_n=1000 max_h=50 mode=lowdist
tc g1-1 gen n=1000 h=50 mode=lowdist
tc g1-2 gen n=1000 h=50 mode=lowdist
tc g1-3 gen n=1000 h=50 mode=lowdist
tc g1-4 gen n=1000 h=50 mode=lowdist
tc g1-5 gen n=1000 h=50 mode=lowdist
tc g1-6 gen n=1000 h=50 mode=lowdist
tc g1-7 gen n=1000 h=50 mode=lowdist
tc g1-8 gen n=1000 h=50 mode=lowdist

group group2 20
limits max_n=50000 max_h=50 mode=noeat
tc g2-1  gen n=50000 h=50 mode=noeat
tc g2-2  gen n=50000 h=50 mode=noeat
tc g2-3  gen n=50000 h=50 mode=noeat
tc g2-4  gen n=50000 h=50 mode=noeat
tc g2-5  gen n=50000 h=50 mode=noeat
tc g2-6  gen n=50000 h=50 mode=noeat
tc g2-7  gen n=50000 h=50 mode=noeat
tc g2-8  gen n=50000 h=50 mode=noeat

group group3 20
limits max_n=50000 max_h=50 mode=nomideat
tc g3-1  gen n=50000 h=50 mode=nomideat
tc g3-2  gen n=50000 h=50 mode=nomideat
tc g3-3  gen n=50000 h=50 mode=nomideat
tc g3-4  gen n=50000 h=50 mode=nomideat
tc g3-5  gen n=50000 h=50 mode=nomideat
tc g3-6  gen n=50000 h=50 mode=nomideat
tc g3-7  gen n=50000 h=50 mode=nomideat
tc g3-8  gen n=50000 h=50 mode=nomideat

group group4 20
limits max_n=50000 max_h=50 mode=hardest
tc g4-1  gen n=50000 h=50 mode=hardest
tc g4-2  gen n=50000 h=50 mode=hardest
tc g4-3  gen n=50000 h=50 mode=hardest
tc g4-4  gen n=50000 h=50 mode=hardest
tc g4-5  gen n=50000 h=50 mode=hardest
tc g4-6  gen n=50000 h=50 mode=hardest
tc g4-7  gen n=50000 h=50 mode=hardest
tc g4-8  gen n=50000 h=50 mode=hardest

group group5 20
limits max_n=50000 max_h=1000 mode=hardest
include_group sample
tc g5-1 gen n=50000 h=1000 mode=noeat
tc g5-2 gen n=50000 h=1000 mode=noeat
tc g5-3 gen n=50000 h=1000 mode=nomideat
tc g5-4 gen n=50000 h=1000 mode=hardest
tc g5-5 gen n=50000 h=50   mode=hardest
tc g5-6 gen_hard case=1
tc g5-7 gen_hard case=2
tc g5-8 gen_hard case=3
tc g5-9 gen_hard case=4