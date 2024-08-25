#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution ipadresser_osk.cc


samplegroup
limits no_zero=0
sample sample1
sample sample2
sample sample3
sample sample4


group group1 30
limits no_zero=1
tc_manual ../tc_manual/ipadresser1.in
tc_manual ../tc_manual/ipadresser2.in
tc_manual ../tc_manual/ipadresser3.in
tc_manual ../tc_manual/ipadresser4.in
tc_manual ../tc_manual/ipadresser5.in



group group2 70
limits no_zero=0
include_group group1
include_group sample
tc_manual ../tc_manual/ipadresser6.in
tc_manual ../tc_manual/ipadresser7.in
