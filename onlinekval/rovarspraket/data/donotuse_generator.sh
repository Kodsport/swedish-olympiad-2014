#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution lindholm_greedy.cpp

compile gen_lolol_ja.py
compile gen_lolol_nej.py
compile gen_yes.py
compile gen_no.py

samplegroup
limits maxn=20
sample rovarspraket1
sample rovarspraket2
sample rovarspraket3

group group1 20
limits maxn=20
include_group sample
tc_manual ../manual_tests/fail1
tc_manual ../manual_tests/fail2
for ((i=0;i<2;i++)); do
    tc g1-$(($i*5+1)) gen_yes n=20 p=0   seed=1$i
    tc g1-$(($i*5+2)) gen_yes n=20 p=0.5 seed=2$i
    tc g1-$(($i*5+3)) gen_no  n=20 p=0.5 seed=3$i
    tc g1-$(($i*5+4)) gen_yes n=20 p=0.5 seed=4$i
    tc g1-$(($i*5+5)) gen_no  n=20 p=1   seed=5$i
done

group group2 30
limits maxn=100
include_group group1
tc g2-1 gen_lolol_ja  n=100
tc g2-2 gen_lolol_nej n=100
for ((i=2;i<5;i++)); do
    tc g2-$(($i*4+3)) gen_yes n=100 p=0.5 seed=1$i
    tc g2-$(($i*4+4)) gen_no  n=100 p=0.5 seed=3$i
    tc g2-$(($i*4+5)) gen_yes n=100 p=1   seed=4$i
    tc g2-$(($i*4+6)) gen_no  n=100 p=0.5 seed=5$i
done

group group3 50
limits maxn=1000
include_group group2
tc g3-1 gen_lolol_ja  n=1000
tc g3-2 gen_lolol_nej n=1000
for ((i=5;i<10;i++)); do
    tc g3-$(($i*4+3)) gen_yes n=1000 p=0.2  seed=1$i
    tc g3-$(($i*4+4)) gen_no  n=1000 p=0.3  seed=3$i
    tc g3-$(($i*4+5)) gen_yes n=1000 p=1    seed=4$i
    tc g3-$(($i*4+6)) gen_no  n=1000 p=0.99 seed=5$i
done