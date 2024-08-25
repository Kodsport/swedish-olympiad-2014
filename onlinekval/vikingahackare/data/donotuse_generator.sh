#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution vikingahackare_js.py python2

compile gen.py

samplegroup
limits t_one=0
sample sample01
sample sample02

group group1 30
limits t_one=1
for ((i=0;i<5;i++)); do
    tc g1-$(($i*3+1)) gen t=1 n=1000 seed=1$i
    tc g1-$(($i*3+2)) gen t=1 n=1000 seed=2$i
    tc g1-$(($i*3+3)) gen t=1 n=1000 seed=3$i
done

group group2 70
limits t_one=0
include_group sample
include_group group1
for ((i=0;i<3;i++)); do
    tc g2-$(($i*5+1)) gen t=3  n=1000 seed=1$i
    tc g2-$(($i*5+2)) gen t=4  n=1000 seed=2$i
    tc g2-$(($i*5+3)) gen t=7  n=1000 seed=3$i
    tc g2-$(($i*5+4)) gen t=12 n=1000 seed=4$i
    tc g2-$(($i*5+5)) gen t=15 n=1000 seed=5$i
done