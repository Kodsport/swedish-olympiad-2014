#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution joshua.cpp

compile gen.py


samplegroup
limits maxn=10
sample sample1
sample sample2

group group1 60
limits maxn=100
include_group sample
for ((i=0;i<10;i++)); do
    tc g1-$i gen n=100 seed=$i
done

group group2 40
limits maxn=1000
include_group group1
for ((i=0;i<10;i++)); do
    tc g2-$i gen n=1000 seed=$i
done
