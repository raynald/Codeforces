import sys

f = sys.stdin
n = int(f.readline())
old_arr = [[1]]
for it in xrange(n):
    new_arr = []
    for arr in old_arr:
        new_arr.append(arr + arr)
        new_arr.append(arr + [1 - x for x in arr])
    old_arr = new_arr
for arr in old_arr:
    rep = ""
    for e in arr:
        if e:
            rep += "+"
        else:
            rep += "*"
    print rep

