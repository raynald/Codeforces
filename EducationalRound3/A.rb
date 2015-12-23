n = gets.to_i
m = gets.to_i
a = Array.new(n)
for i in 0..n-1
    a[i] = gets.to_i
end
a = a.sort {|x,y| y <=> x}
k = 0
for item in a
    if m <= 0
        break
    end
    k += 1
    m -= item
end
puts k
    
