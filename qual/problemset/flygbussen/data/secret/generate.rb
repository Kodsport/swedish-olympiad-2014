min_n, k, max_t, max_group_size, max_duplicate, seed = gets.split.map(&:to_i)

srand seed # Deterministisk! (Och dynamisk! / osk)

def assert(b)
  if not b then
    puts "Assertion failed yao!"
    exit(1)
  end
end

n = min_n # It will always become at least as much as n

t = 0

arrivals = []

while n > 0 do
  t += rand > 0.7 ? rand(k*20) : rand(k*1) # Såhär vi skapar klungor
  t %= max_t - (4*k) # I wanted just max_t, but we are comforty here
  group_size = rand(max_group_size)
  group_size.times {
    arrivals += [ t + rand(2*k) ] * (rand(max_duplicate) + 1)
  }
  n -= group_size
end

arrivals.shuffle!
# arrivals.sort! # TODO remove

puts "#{arrivals.size} #{k}"
puts arrivals.join(" ")
