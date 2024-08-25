#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution tvtittande_osk.py python2

compile rand_gen.cpp

samplegroup
limits maxn=10
sample sample1
sample sample2

group group1 70
limits maxn=100
include_group sample
for ((i=0;i<10;i++)); do
    tc g1-$(($i*3+1)) rand_gen 100 0.01 1$i
    tc g1-$(($i*3+2)) rand_gen 100 0.5  2$i
    tc g1-$(($i*3+3)) rand_gen 100 0.99 3$i
done

group group2 30
limits maxn=1000
include_group group1
for ((i=0;i<10;i++)); do
    tc g2-$(($i*3+1)) rand_gen 1000 0.01 1$i
    tc g2-$(($i*3+2)) rand_gen 1000 0.5  2$i
    tc g2-$(($i*3+3)) rand_gen 1000 0.99 3$i
done