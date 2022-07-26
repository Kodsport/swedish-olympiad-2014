#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution lattexter_simon.cpp

compile gen_hard.py python2
compile gen_large_tree.py python2

# Sample
samplegroup
limits max_n=10 max_q=10 small=1
sample_manual sample01
sample_manual sample02

group group1 20
limits max_n=5000 max_q=10000 small=1
for ((i=0;i<2;i++)); do
    tc g1-$(($i*4+1)) gen_hard small=1 n=5000 q=8000 d=20  f=0.01 seed=1$i
    tc g1-$(($i*4+2)) gen_hard small=1 n=5000 q=8000 d=100 f=0.8  seed=2$i
    tc g1-$(($i*4+3)) gen_hard small=1 n=5000 q=8000 d=3   f=0.6  seed=3$i
    tc g1-$(($i*4+4)) gen_hard small=1 n=5000 q=8000 d=1   f=0.4  seed=4$i
done


group group2 60
limits max_n=500000 max_q=80000 small=1
for ((i=2;i<8;i++)); do
    tc g2-$((($i-2)*4+1)) gen_hard small=1 n=500000 q=80000 d=20 f=0.01 seed=1$i
    tc g2-$((($i-2)*4+2)) gen_hard small=1 n=500000 q=80000 d=3  f=0.2  seed=2$i
    tc g2-$((($i-2)*4+3)) gen_hard small=1 n=500000 q=80000 d=2  f=0.15 seed=3$i
    tc g2-$((($i-2)*4+4)) gen_hard small=1 n=500000 q=80000 d=1  f=0.15 seed=4$i
done

group group3 20
limits max_n=500000 max_q=80000 small=0
for ((i=8;i<10;i++)); do
    tc g3-$((($i-8)*6+1)) gen_hard small=0 n=500000 q=80000 d=20 f=0.01  seed=1$i
    tc g3-$((($i-8)*6+2)) gen_hard small=0 n=500000 q=80000 d=4  f=1     seed=2$i
    tc g3-$((($i-8)*6+3)) gen_hard small=0 n=500000 q=80000 d=3  f=0.2   seed=3$i
    tc g3-$((($i-8)*6+4)) gen_hard small=0 n=500000 q=80000 d=2  f=0.15  seed=4$i
    tc g3-$((($i-8)*6+5)) gen_hard small=0 n=500000 q=80000 d=1  f=0.25  seed=5$i
    tc g3-$((($i-8)*6+6)) gen_large_tree n=500000 q=80000                seed=6$i
done