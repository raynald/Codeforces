n = gets.to_i
min = 109
sum = 0
n.times do
    a, b = gets.split(' ').map(&:to_i)
    if b < min
        min = b
    end
    sum += min * a
end
print sum, "\n"
