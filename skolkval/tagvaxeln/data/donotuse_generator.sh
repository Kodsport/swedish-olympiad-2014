#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution tagvaxeln_js.cpp

compile gen.py

samplegroup
limits no_collision=0
sample sample1
sample sample2

group group1 30
limits no_collision=1
tc g1-1 gen collide=0 seed=100
tc g1-2 gen collide=0 seed=101
tc g1-3 gen collide=0 seed=102
tc g1-4 gen collide=0 seed=103



group group2 70
limits no_collision=0
include_group sample
include_group group1
for ((i=1;i<10;i++)); do
    tc g2-$i gen collide=0 seed=$i
done
for ((i=10;i<20;i++)); do
    tc g2-$i gen collide=1 seed=$i
done
