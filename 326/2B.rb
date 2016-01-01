n = gets.to_i
a = 1
for i in 2..999999
    if n < i
        break
    end
    f = 1
    while n % i == 0
        f = 0
        n /= i
    end
    if f == 0
        a *= i
    end
end
puts a * n
