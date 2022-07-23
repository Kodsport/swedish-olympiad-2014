#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution sol_osk.cc

compile gen_yes.py
compile gen_no.py
compile gen_random.py

# Sample
samplegroup
sample_manual fotografen.1
sample_manual fotografen.2
sample_manual fotografen.3

group group1 10
tc g1-1  gen_random n=10 ratio=0.5 seed=10
tc g1-2  gen_random n=10 ratio=0.5 seed=11
tc g1-3  gen_yes    n=10 ratio=0.95 seed=12
tc g1-4  gen_yes    n=10 ratio=0.95 seed=13
tc g1-5  gen_yes    n=10 ratio=0.5 seed=14
tc g1-6  gen_yes    n=10 ratio=0.5 seed=15
tc g1-7  gen_yes    n=10 ratio=1   seed=16
tc g1-8  gen_yes    n=10 ratio=1   seed=17
tc g1-9  gen_no     n=10 ratio=0.9 seed=18
tc g1-10 gen_no     n=10 ratio=0.9 seed=19

group group2 40
tc g2-1  gen_random n=5000 ratio=0.1  seed=110
tc g2-2  gen_random n=5000 ratio=0.1  seed=111
tc g2-3  gen_yes    n=5000 ratio=1    seed=112
tc g2-4  gen_yes    n=5000 ratio=1    seed=113
tc g2-5  gen_yes    n=5000 ratio=0.77 seed=114
tc g2-6  gen_yes    n=5000 ratio=0.77 seed=115
tc g2-7  gen_random n=5000 ratio=0.1  seed=116
tc g2-8  gen_random n=5000 ratio=0.1  seed=117
tc g2-9  gen_no     n=5000 ratio=0.07 seed=118
tc g2-10 gen_no     n=5000 ratio=0.07 seed=119

group group3 50
tc g3-1  gen_random n=100000 ratio=0.1    seed=6942010
tc g3-2  gen_random n=100000 ratio=0.1    seed=6942011
tc g3-3  gen_yes    n=100000 ratio=1      seed=6942012
tc g3-4  gen_yes    n=100000 ratio=1      seed=6942013
tc g3-5  gen_yes    n=100000 ratio=0.5    seed=6942014
tc g3-6  gen_yes    n=100000 ratio=0.5    seed=6942015
tc g3-7  gen_yes    n=100000 ratio=0.97   seed=6942016
tc g3-8  gen_yes    n=100000 ratio=0.97   seed=6942017
tc g3-9  gen_no     n=100000 ratio=0.0036 seed=6942018
tc g3-10 gen_no     n=100000 ratio=0.0036 seed=6942019