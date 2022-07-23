#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution oversattning_emanuel.py

compile gen_random.py
compile gen_worst.py

# Sample
samplegroup
sample_manual oversattning.1

# n=100
group group1 40
tc g1-1 gen_random words=30 ent=100 leaf=100000 sentlen=100 seed=20
tc g1-2 gen_random words=30 ent=100 leaf=100000 sentlen=100 seed=21
tc g1-3 gen_random words=50 ent=100 leaf=10     sentlen=100 seed=22
tc g1-4 gen_random words=50 ent=100 leaf=10     sentlen=100 seed=23
tc g1-5 gen_random words=20 ent=100 leaf=10     sentlen=100 seed=24
tc g1-6 gen_random words=20 ent=100 leaf=10     sentlen=100 seed=25
tc g1-7 gen_worst  ent=100 leaf=30 sentlen=100 seed=10
tc g1-8 gen_worst  ent=100 leaf=30 sentlen=100 seed=11
tc g1-9 gen_worst  ent=50  leaf=3  sentlen=100 seed=12
tc g1-10 gen_worst ent=50  leaf=3  sentlen=100 seed=13

# n=5e4, m=100
group group2 30
tc g2-1 gen_random words=70  ent=1000 leaf=10   sentlen=100000 seed=20
tc g2-2 gen_random words=70  ent=1000 leaf=10   sentlen=100000 seed=21
tc g2-3 gen_random words=100 ent=1000 leaf=1000 sentlen=100000 seed=22
tc g2-4 gen_random words=100 ent=1000 leaf=1000 sentlen=100000 seed=23
tc g2-5 gen_random words=100 ent=1000 leaf=2    sentlen=100000 seed=24
tc g2-6 gen_random words=100 ent=1000 leaf=2    sentlen=100000 seed=25
tc g2-7 gen_worst  ent=1000 leaf=200 sentlen=100000 seed=10
tc g2-8 gen_worst  ent=1000 leaf=200 sentlen=100000 seed=11
tc g2-9 gen_worst  ent=500  leaf=150 sentlen=100000 seed=12
tc g2-10 gen_worst ent=500  leaf=150 sentlen=100000 seed=13

# n=5e4
group group3 30
tc g3-1 gen_random words=1000 ent=50000 leaf=10   sentlen=100000 seed=20
tc g3-2 gen_random words=1000 ent=50000 leaf=10   sentlen=100000 seed=21
tc g3-3 gen_random words=1000 ent=50000 leaf=1000 sentlen=100000 seed=22
tc g3-4 gen_random words=1000 ent=50000 leaf=1000 sentlen=100000 seed=23
tc g3-5 gen_random words=1000 ent=50000 leaf=2    sentlen=100000 seed=24
tc g3-6 gen_random words=1000 ent=50000 leaf=2    sentlen=100000 seed=25
tc g3-7 gen_worst  ent=50000 leaf=4000  sentlen=100000 seed=10
tc g3-8 gen_worst  ent=50000 leaf=4000  sentlen=100000 seed=11
tc g3-9 gen_worst  ent=49999 leaf=20000 sentlen=100000 seed=12
tc g3-10 gen_worst ent=49999 leaf=20000 sentlen=100000 seed=13
