#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution osk.cc

compile gen.py

# Sample
samplegroup
limits max_n=10 max_coord=500
sample 1
sample 2
sample 3

group group1 20
limits max_n=10 max_coord=1000
tc g1-1 gen n=10 amplitude=1000 fraction=0.2 seed=10
tc g1-2 gen n=10 amplitude=1000 fraction=0.2 seed=11
tc g1-3 gen n=10 amplitude=1000 fraction=0.5 seed=12
tc g1-4 gen n=10 amplitude=1000 fraction=0.5 seed=13
tc g1-5 gen n=10 amplitude=600  fraction=0.8 seed=14
tc g1-6 gen n=10 amplitude=600  fraction=0.8 seed=15
tc g1-7 gen n=10 amplitude=100  fraction=1   seed=16
tc g1-8 gen n=10 amplitude=100  fraction=1   seed=17

group group2 30
limits max_n=1000 max_coord=1000000
tc g2-1 gen n=1000 amplitude=1000000 fraction=0.2 seed=110
tc g2-2 gen n=1000 amplitude=1000000 fraction=0.2 seed=111
tc g2-3 gen n=1000 amplitude=100000  fraction=0.5 seed=112
tc g2-4 gen n=1000 amplitude=100000  fraction=0.5 seed=113
tc g2-5 gen n=999  amplitude=10000   fraction=0.8 seed=114
tc g2-6 gen n=999  amplitude=10000   fraction=0.8 seed=115
tc g2-7 gen n=777  amplitude=100000  fraction=1   seed=116
tc g2-8 gen n=777  amplitude=100000  fraction=1   seed=117

group group3 50
limits max_n=100000 max_coord=100000000
include_group sample
tc g3-1 gen n=100000 amplitude=10000000 fraction=0.2  seed=69110
tc g3-2 gen n=100000 amplitude=10000000 fraction=0.2  seed=69111
tc g3-3 gen n=100000 amplitude=50000    fraction=0.5  seed=69112
tc g3-4 gen n=100000 amplitude=50000    fraction=0.5  seed=69113
tc g3-5 gen n=99034  amplitude=1000     fraction=0.8  seed=69114
tc g3-6 gen n=99034  amplitude=1000     fraction=0.8  seed=69115
tc g3-7 gen n=100000 amplitude=100      fraction=0.91 seed=69116
tc g3-8 gen n=100000 amplitude=100      fraction=0.91 seed=69117