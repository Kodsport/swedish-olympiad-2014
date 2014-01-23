# Sourcea denna
#
# Innan du kör igång så gör följande:
#
# (cd submissions/time_limit_exceeded && g++ -O2 flygbussar_simon.cpp)
# (cd submissions/accepted && javac Solver.java)

flyg () {
  echo $@ | ruby generate.rb
}

simon () {
  (cd submissions/time_limit_exceeded && ./a.out)
}

erik () {
  (cd submissions/accepted && java Solver)
}

# Kör båda
boda () {
  flyg $@ | simon
  flyg $@ | erik
}

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
