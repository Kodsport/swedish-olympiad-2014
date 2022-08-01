#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution dansmatta_dp_js.cc

compile gen_multi_move.cpp

samplegroup
limits single=0 maxn=10000
sample sample01
sample sample02

group group1 20
limits single=1 maxn=10
tc single-small1 gen_multi_move 1 1
tc single-small3 gen_multi_move 10 1
tc single-small4 gen_multi_move 10 1
tc single-small5 gen_multi_move 10 1
tc single-small6 gen_multi_move 10 1
tc single-small7 gen_multi_move 10 1
tc single-small8 gen_multi_move 10 1

group group2 30
limits single=1 maxn=10000
include_group group1
tc single1 gen_multi_move 4564 1
tc single2 gen_multi_move 5555 1
tc single3 gen_multi_move 6666 1
tc single4 gen_multi_move 7234 1
tc single5 gen_multi_move 8002 1
tc single6 gen_multi_move 8004 1
tc single7 gen_multi_move 8007 1
tc single8 gen_multi_move 9996 1
tc single9 gen_multi_move 9993 1

group group3 50
limits single=0 maxn=10000
include_group sample
include_group group2
tc full1 gen_multi_move 4564 0
tc full2 gen_multi_move 5555 0
tc full3 gen_multi_move 6666 0
tc full4 gen_multi_move 7234 0
tc full5 gen_multi_move 8002 0
tc full6 gen_multi_move 8004 0
tc full7 gen_multi_move 8007 0
tc full8 gen_multi_move 9996 0
tc full9 gen_multi_move 9993 0
