a = Array.new(8)
c = [0] * 8
for x in 0..7
    a[x] = gets
end
flag = 0
for x in 0..7
    for y in 0..7
        if a[x][y] == "W" and c[y] == 0
            w = x;
            flag = 1;
            break;
        end
        if a[x][y] == "B"
            c[y] = 1;
        end
    end
    if flag == 1
        break
    end
end
c = [0] * 8
flag = 0
for x in 0..7
    for y in 0..7
        if a[7 - x][y] == 'B' and c[y] == 0
            b = x;
            flag = 1;
            break;
        end
        if a[7 - x][y] == 'W'
            c[y] = 1;
        end
    end
    if flag == 1
        break;
    end
end
if w > b
    print "B\n"
else
    print "A\n"
end
