n, m = gets.split(' ').map(&:to_i);
a = [];
n.times {
    a += [(gets.split(' ').map(&:to_i).min)];
}
puts a.max;
