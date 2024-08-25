#!/usr/bin/env bash


PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution arash.cpp

compile gen.py python2

# Sample
samplegroup
limits max_n=10 max_f=5000000000000
sample_manual sample01
sample_manual sample02
sample_manual sample03
sample_manual sample04

group group1 40
limits max_n=200 max_f=5000
for ((i=0;i<4;i++)); do
    tc g1-$(($i*4+1)) gen n=200 max_f=5000 seed=1$i
    tc g1-$(($i*4+2)) gen n=200 max_f=5000 seed=2$i
    tc g1-$(($i*4+3)) gen n=200 max_f=5000 seed=3$i
    tc g1-$(($i*4+4)) gen n=200 max_f=5000 seed=4$i
done


group group2 30
limits max_n=1000 max_f=1000000000000000
for ((i=4;i<7;i++)); do
    tc g2-$((($i-4)*4+1)) gen n=1000 max_f=1000000000000000 seed=11$i
    tc g2-$((($i-4)*4+2)) gen n=1000 max_f=1000000000000000 seed=21$i
    tc g2-$((($i-4)*4+3)) gen n=1000 max_f=1000000000000000 seed=31$i
    tc g2-$((($i-4)*4+4)) gen n=1000 max_f=1000000000000000 seed=41$i
done

group group3 30
limits max_n=50000 max_f=1000000000000000
include_group sample
for ((i=7;i<10;i++)); do
    tc g3-$((($i-7)*4+1)) gen n=50000 max_f=1000000000000000 seed=11$i
    tc g3-$((($i-7)*4+2)) gen n=50000 max_f=1000000000000000 seed=21$i
    tc g3-$((($i-7)*4+3)) gen n=50000 max_f=1000000000000000 seed=31$i
    tc g3-$((($i-7)*4+4)) gen n=50000 max_f=1000000000000000 seed=41$i
done