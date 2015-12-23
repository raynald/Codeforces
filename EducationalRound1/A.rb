#!/usr/bin/ruby

len = gets.to_i
for iter in 0..len - 1
    t = gets.to_i
    pow = (Math.log(t) / Math.log(2)).to_i
    puts t * (t + 1) / 2 - (2 ** (pow + 1) - 1) * 2
end
