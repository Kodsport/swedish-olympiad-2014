#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution sol_osk.cc

compile gen_yes.py
compile gen_no.py
compile gen_random.py
compile gen_worstcase.py

# Sample
samplegroup
limits max_n=10
sample 1
sample 2
sample 3

group group1 10
limits max_n=10
tc g1-1  gen_random n=10 ratio=0.5
tc g1-2  gen_random n=10 ratio=0.5
tc g1-3  gen_yes    n=10 ratio=0.95
tc g1-4  gen_yes    n=10 ratio=0.95
tc g1-5  gen_yes    n=10 ratio=0.5
tc g1-6  gen_yes    n=10 ratio=0.5
tc g1-7  gen_yes    n=10 ratio=1
tc g1-8  gen_yes    n=10 ratio=1
tc g1-9  gen_no     n=10 ratio=0.9
tc g1-10 gen_no     n=10 ratio=0.9

group group2 40
limits max_n=5000
tc g2-1  gen_random n=5000 ratio=0.1
tc g2-2  gen_random n=5000 ratio=0.1
tc g2-3  gen_yes    n=5000 ratio=1
tc g2-4  gen_yes    n=5000 ratio=1
tc g2-5  gen_yes    n=5000 ratio=0.77
tc g2-6  gen_yes    n=5000 ratio=0.77
tc g2-7  gen_random n=5000 ratio=0.1
tc g2-8  gen_random n=5000 ratio=0.1
tc g2-9  gen_no     n=5000 ratio=0.07
tc g2-10 gen_no     n=5000 ratio=0.07

group group3 50
limits max_n=400000
include_group sample
tc g3-1  gen_random n=400000 ratio=0.1
tc g3-2  gen_random n=400000 ratio=0.1
tc g3-3  gen_yes    n=400000 ratio=1
tc g3-4  gen_yes    n=400000 ratio=1
tc g3-5  gen_yes    n=400000 ratio=0.5
tc g3-6  gen_yes    n=400000 ratio=0.5
tc g3-7  gen_yes    n=400000 ratio=0.97
tc g3-8  gen_yes    n=400000 ratio=0.97
tc g3-9  gen_no     n=400000 ratio=0.0036
tc g3-10 gen_no     n=400000 ratio=0.0036
tc g3-11 gen_worstcase
