# Sourcea denna
#
# Innan du kör igång så gör följande:
#
# (cd submissions/time_limit_exceeded && g++ -O2 flygbussar_simon.cpp)
# (cd submissions/accepted && javac Solver.java)

fisk () {
  echo $@ | python data/secret/gen.py
}

sol () {
  (cd submissions && ./sol)
}

wa () {
  (cd submissions && ./wa)
}

arash () {
  (cd submissions/accepted && ./$0)
}

marten () {
  (cd submissions/accepted  && ./$0)
}


# Kör båda
boda () {
  fisk $@ | arash
  fisk $@ | marten
}

same () {
  [[ $(fisk $@ | arash) == $(fisk $@ | marten) ]]
}

not_same () {
  same $@
  [[ $? != 0 ]]
}

cas='4 30
L 30 10
S 48 15
L 30 16
L 36 12
'

cas2='5 30
L 28 7
L 30 8
M 28 13
L 24 10
S 30 18
'

cas3='5 30
L 28 7
L 30 8
M 28 13
L 26 10
S 30 18
'

cas4='7 30
M 10000042 7
L 10000032 16
L 10000028 17
S 10000048 17
M 10000060 19
L 10000028 23
M 10000042 23
'

# M 10000042 7
# L 10000032 16
# L 10000028 17
# S 10000048 17
# M 10000060 19
# L 10000028 23
# M 10000042 23


# sen kan du typ köra
#
#   $ boda 3 11 1000 2 1 
#   16
#   16
#
# och se indatat med
#
#   $ flyg 4 11 1000 2 1 
#   4 11
#   5 31 31 15
