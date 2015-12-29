#!/usr/bin/ruby

n, k = gets.strip().split(" ")
n = n.to_i
k = k.to_i
a = gets.strip().split(" ")
a = a.map(&:to_i)
b = gets.strip().split(" ")
b = b.map(&:to_i)
m = n / k;
ans = 1;
for i in 0..m - 1
    if b[i] == 0  
        tmp = 10 ** (k - 1)
        mul = (tmp * 10 - 1) / a[i] - tmp / a[i] + 1
        if tmp % a[i] > 0
            mul -= 1
        end
    else
        tmp = 10 ** (k - 1) 
        mul = (tmp * 10 - 1) / a[i] - tmp * (b[i] + 1) / a[i] + 1 + (tmp * b[i] - 1) / a[i] + 1
        if tmp * (b[i] + 1) % a[i] > 0
            mul -= 1
        end
    end
    ans = ans * mul
    ans %= 10 ** 9 + 7
end
print ans, "\n"
