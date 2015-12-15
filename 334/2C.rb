#!/usr/bin/ruby 

len = gets.to_i
score = gets.strip()
char = '-'
alter = 0
for ch in 0..len - 1
    if char == '-' or char != score[ch]
        char = score[ch]
        alter += 1
    end
end
puts [alter + 2, len].min

=begin
min(len, maxi + 2)
=end
