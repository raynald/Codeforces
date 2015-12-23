#!/usr/bin/ruby

str = gets.strip()
len = gets.to_i
for iter in 0..len - 1
    l, r, k = gets.split(' ')
    l = l.to_i
    r = r.to_i
    k = k.to_i
    substr = str[l-1..r-1]
    k %= substr.length
    substr = substr[-k, k] + substr[0, substr.length-k]
    substr = substr + str[r..-1]
    if l >= 2
        str = str[0..l-2] + substr
    else
        str = substr
    end
end
puts str
