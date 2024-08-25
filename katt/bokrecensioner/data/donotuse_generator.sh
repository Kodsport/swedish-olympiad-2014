#!/usr/bin/env bash


PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution bokrecensioner_simon.cpp

compile gen.py

# Sample
samplegroup
limits allowed=all
sample_manual sample01
sample_manual sample02
sample_manual sample03
sample_manual sample04

group group1 30
limits allowed=less
for ((i=0;i<3;i++)); do
    tc g1-$(($i*6+1)) gen mode=a yesno=yes n=100000 m=100   r=500000 components=-1 seed=1$i
    tc g1-$(($i*6+2)) gen mode=a yesno=yes n=100000 m=10000 r=500000 components=-1 seed=2$i
    tc g1-$(($i*6+3)) gen mode=a yesno=no1 n=100000 m=100   r=500000 components=-1 seed=3$i
    tc g1-$(($i*6+4)) gen mode=a yesno=no2 n=100000 m=100   r=500000 components=-1 seed=4$i
    tc g1-$(($i*6+5)) gen mode=a yesno=no2 n=100000 m=10    r=500000 components=-1 seed=5$i
    tc g1-$(($i*6+6)) gen mode=a yesno=no2 n=100000 m=1000  r=500000 components=-1 seed=6$i
done

group group2 30
limits allowed=equal_and_less
for ((i=3;i<6;i++)); do
    tc g2-$((($i-3)*6+1)) gen mode=b yesno=yes n=100000 m=100   r=500000 components=50000 seed=1$i
    tc g2-$((($i-3)*6+2)) gen mode=b yesno=yes n=100000 m=10000 r=500000 components=90000 seed=2$i
    tc g2-$((($i-3)*6+3)) gen mode=b yesno=no1 n=100000 m=100   r=500000 components=70000 seed=3$i
    tc g2-$((($i-3)*6+4)) gen mode=b yesno=no2 n=100000 m=100   r=500000 components=80000 seed=4$i
    tc g2-$((($i-3)*6+5)) gen mode=b yesno=no2 n=100000 m=10    r=500000 components=80000 seed=5$i
    tc g2-$((($i-3)*6+6)) gen mode=b yesno=no2 n=100000 m=1000  r=500000 components=80000 seed=6$i
done

group group3 40
limits allowed=all
include_group sample
for ((i=6;i<10;i++)); do
    tc g3-$((($i-6)*6+1)) gen mode=c yesno=yes n=100000 m=10000 r=500000 components=-1    seed=1$i
    tc g3-$((($i-6)*6+2)) gen mode=c yesno=yes n=100000 m=100   r=500000 components=10000 seed=2$i
    tc g3-$((($i-6)*6+3)) gen mode=c yesno=no1 n=100000 m=100   r=500000 components=30000 seed=3$i
    tc g3-$((($i-6)*6+4)) gen mode=c yesno=no2 n=100000 m=100   r=500000 components=30000 seed=4$i
    tc g3-$((($i-6)*6+5)) gen mode=c yesno=no2 n=100000 m=10    r=500000 components=30000 seed=5$i
    tc g3-$((($i-6)*6+6)) gen mode=c yesno=no2 n=100000 m=1000  r=500000 components=30000 seed=6$i
done