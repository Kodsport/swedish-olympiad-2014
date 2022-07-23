#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution arash.cpp

compile gen.py
compile gen_hard.py

# Sample
samplegroup
sample_manual fiskspelet.1
sample_manual fiskspelet.2
sample_manual fiskspelet.3
sample_manual fiskspelet.4
sample_manual fiskspelet.5
sample_manual fiskspelet.6
sample_manual fiskspelet.7

group group1 20
tc g1-1  gen n=1000 h=50 mode=lowdist seed=10
tc g1-2  gen n=1000 h=50 mode=lowdist seed=11
tc g1-3  gen n=1000 h=50 mode=lowdist seed=12
tc g1-4  gen n=1000 h=50 mode=lowdist seed=13
tc g1-5  gen n=1000 h=50 mode=lowdist seed=14
tc g1-6  gen n=1000 h=50 mode=lowdist seed=15
tc g1-7  gen n=1000 h=50 mode=lowdist seed=16
tc g1-8  gen n=1000 h=50 mode=lowdist seed=17

group group2 20
tc g2-1  gen n=50000 h=50 mode=noeat seed=1210
tc g2-2  gen n=50000 h=50 mode=noeat seed=1211
tc g2-3  gen n=50000 h=50 mode=noeat seed=1212
tc g2-4  gen n=50000 h=50 mode=noeat seed=1213
tc g2-5  gen n=50000 h=50 mode=noeat seed=1214
tc g2-6  gen n=50000 h=50 mode=noeat seed=1215
tc g2-7  gen n=50000 h=50 mode=noeat seed=1216
tc g2-8  gen n=50000 h=50 mode=noeat seed=1217

group group3 20
tc g3-1  gen n=50000 h=50 mode=nomideat seed=13010
tc g3-2  gen n=50000 h=50 mode=nomideat seed=13011
tc g3-3  gen n=50000 h=50 mode=nomideat seed=13012
tc g3-4  gen n=50000 h=50 mode=nomideat seed=13013
tc g3-5  gen n=50000 h=50 mode=nomideat seed=13014
tc g3-6  gen n=50000 h=50 mode=nomideat seed=13015
tc g3-7  gen n=50000 h=50 mode=nomideat seed=13016
tc g3-8  gen n=50000 h=50 mode=nomideat seed=13017

group group4 20
tc g4-1  gen n=50000 h=50 mode=hardest seed=12413010
tc g4-2  gen n=50000 h=50 mode=hardest seed=12413011
tc g4-3  gen n=50000 h=50 mode=hardest seed=12413012
tc g4-4  gen n=50000 h=50 mode=hardest seed=12413013
tc g4-5  gen n=50000 h=50 mode=hardest seed=12413014
tc g4-6  gen n=50000 h=50 mode=hardest seed=12413015
tc g4-7  gen n=50000 h=50 mode=hardest seed=12413016
tc g4-8  gen n=50000 h=50 mode=hardest seed=12413017

group group5 20
tc g5-1 gen n=50000 h=1000 mode=noeat    seed=472567
tc g5-2 gen n=50000 h=1000 mode=noeat    seed=472561
tc g5-3 gen n=50000 h=1000 mode=nomideat seed=472562
tc g5-4 gen n=50000 h=1000 mode=hardest  seed=472563
tc g5-5 gen n=50000 h=50   mode=hardest    seed=472564
tc g5-6 gen_hard case=1
tc g5-7 gen_hard case=2
tc g5-8 gen_hard case=3
tc g5-9 gen_hard case=4