# To slow, that's why there is also a C version.
n = gets.to_i
b = gets.chomp.split(' ').map(&:to_i)
ary = Array.new(1000030, 0)
for c in b
    ary[c] += 1
end
sum = 0
for x in (0..1000028)
    ary[x + 1] += ary[x] / 2
    ary[x] = ary[x] % 2
    sum += ary[x]
end
puts sum
