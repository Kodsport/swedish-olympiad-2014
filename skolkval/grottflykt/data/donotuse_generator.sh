#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution Solver.java

compile gen_line.py

samplegroup
limits product_max=25 h_one=0
sample sample01
sample sample02
sample sample03

group group1 20
limits product_max=64 h_one=1
tc line-1 gen_line w_low=3 w_high=64 seed=463
tc line-2 gen_line w_low=3 w_high=64 seed=2



group group2 30
limits product_max=25 h_one=0
include_group sample
tc small-1 gen_line w_low=3 w_high=25 seed=43874685
tc small-2 gen_line w_low=3 w_high=5 seed=4135
tc small-3 gen_line w_low=3 w_high=7 seed=2483
tc_manual ../manual_tc/secret01.in
tc_manual ../manual_tc/secret02.in
tc_manual ../manual_tc/secret03.in

group group3 50
limits product_max=64 h_one=0
include_group group1
include_group group2
include_group sample
tc_manual ../manual_tc/secret04.in

