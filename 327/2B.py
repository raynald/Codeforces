import sys

f = sys.stdin
n, m = [int(x) for x in f.readline().strip().split(' ')]
string = f.readline().strip()
Map = {chr(97+x):chr(97+x) for x in xrange(26)}
for it in xrange(m):
    x, y = f.readline().strip().split(' ')
    t = Map[y]
    Map[y] = Map[x]
    Map[x] = t
remap = {value:key for key, value in Map.items()}
new_string = "".join([remap[x] for x in string])
print new_string
