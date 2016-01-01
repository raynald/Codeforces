n = gets.to_i
ans = nil
m = []
n.times do
    m += [gets.to_i]
    m = m.sort
end
case n
when 4
    if (m[3] - m[0]) * 2 == m[1] + m[2] and m[1] + m[2] == m[0] + m[3]
        ans = []
    end
when 3
    if m[0] * 3 >= m[2] and m[0] * 4 == m[1] + m[2]
        ans = [m[0] * 3]
    elsif m[2] + m[2] / 3 == m[0] + m[1]
        ans = [m[2] / 3]
    elsif m[2] == m[0] * 3
        ans = [m[0] * 4 - m[1]]
    end
when 2
    if m[0] * 3 >= m[1]
        ans = [m[0] * 3, m[0] * 4 - m[1]]
    end
when 1
    ans = [m[0], m[0] * 3, m[0] * 3]
when 0
    ans = [1, 1, 3, 3]
end
if ans != nil
    puts "YES"
    puts ans
else
    puts "NO"
end
