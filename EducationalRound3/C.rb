n = gets.to_i
m = gets.split(' ').map{ |x| x.to_i }
msum = m.inject{|sum,x| sum+x}
avg = msum / n
ans1 = ans2 = 0
for iter in m
    if iter < avg
        ans1 += avg - iter
    end
    if iter > avg 
        ans2 += iter - avg - 1
    end
end
puts [ans1, ans2].max
