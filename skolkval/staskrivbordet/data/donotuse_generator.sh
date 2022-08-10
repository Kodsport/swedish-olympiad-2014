#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution staskrivbordet_arash.cpp


samplegroup
limits small=1
sample sample1
sample sample2


group group1 30
limits small=1
tc_manual ../tc_manual/staskrivbordet.01.in
tc_manual ../tc_manual/staskrivbordet.02.in


group group2 70
limits small=0
include_group group1
include_group sample
tc_manual ../tc_manual/staskrivbordet.03.in
