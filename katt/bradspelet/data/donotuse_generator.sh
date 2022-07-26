#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution bradspelet_mem.cpp

compile gen.py

# Sample
samplegroup
limits max_v=10
sample_manual sample01
sample_manual sample02
sample_manual sample03

group group1 20
limits max_v=10
for ((i=0;i<2;i++)); do
    tc g1-$(($i*6+1)) gen max_v=10 win=0 seed=1$i
    tc g1-$(($i*6+2)) gen max_v=10 win=1 seed=2$i
    tc g1-$(($i*6+3)) gen max_v=10 win=0 seed=3$i
    tc g1-$(($i*6+4)) gen max_v=10 win=1 seed=7$i
    tc g1-$(($i*6+5)) gen max_v=10 win=1 seed=9$i
    tc g1-$(($i*6+6)) gen max_v=10 win=1 seed=11$i
done

group group2 80
limits max_v=100
for ((i=2;i<10;i++)); do
    tc g2-$((($i-2)*6+1)) gen max_v=100 win=0 seed=11$i
    tc g2-$((($i-2)*6+2)) gen max_v=100 win=1 seed=21$i
    tc g2-$((($i-2)*6+3)) gen max_v=100 win=0 seed=31$i
    tc g2-$((($i-2)*6+4)) gen max_v=100 win=1 seed=41$i
    tc g2-$((($i-2)*6+5)) gen max_v=100 win=1 seed=45$i
    tc g2-$((($i-2)*6+6)) gen max_v=100 win=1 seed=46$i
done
