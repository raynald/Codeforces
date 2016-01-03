n, x = gets.split(' ').map(&:to_i)
pre = 0
ans = 0
n.times do
    l, r = gets.split(' ').map(&:to_i)
    ans += (l - pre - 1) % x + r - l + 1
    pre = r
end
print ans, "\n";
