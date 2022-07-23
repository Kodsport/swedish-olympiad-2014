#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution arash.cpp

compile gen_random.py

# Sample
samplegroup
sample_manual orientering.1
sample_manual orientering.2
sample_manual orientering.3

# n,m=200
group group1 50
tc g1-1  gen_random n=200 m=200 seed=10
tc g1-2  gen_random n=200 m=200 seed=11
tc g1-3  gen_random n=200 m=200 seed=12
tc g1-4  gen_random n=200 m=200 seed=13
tc g1-5  gen_random n=200 m=200 seed=14
tc g1-6  gen_random n=200 m=200 seed=15
tc g1-7  gen_random n=200 m=200 seed=16
tc g1-8  gen_random n=200 m=200 seed=17
tc g1-9  gen_random n=200 m=200 seed=18
tc g1-10 gen_random n=200 m=200 seed=19

# n,m=800
group group2 50
tc g2-1  gen_random n=800 m=800 seed=110
tc g2-2  gen_random n=800 m=800 seed=111
tc g2-3  gen_random n=800 m=800 seed=112
tc g2-4  gen_random n=800 m=800 seed=113
tc g2-5  gen_random n=800 m=800 seed=114
tc g2-6  gen_random n=800 m=800 seed=115
tc g2-7  gen_random n=800 m=800 seed=116
tc g2-8  gen_random n=800 m=800 seed=117
tc g2-9  gen_random n=800 m=800 seed=118
tc g2-10 gen_random n=800 m=800 seed=119
