n, m = gets.split(' ')
array = gets.split(' ')
sta = Array.new(m.to_i, 0)
for item in array
    sta[item.to_i - 1] += 1
end
ans = 0
for i in 0..m.to_i-1
    for j in i+1..m.to_i-1
        ans += sta[i] * sta[j]
    end
end
puts ans
