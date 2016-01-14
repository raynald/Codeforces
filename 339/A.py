import sys
f = sys.stdin
l, r, k = map(int, f.readline().split(' '))
ans = 1
v = []
while ans < l:
    ans *= k
while ans <= r:
    v += [ans]
    ans *= k
if len(v) == 0:
    print -1
else:
    print ' '.join(str(it) for it in v)
