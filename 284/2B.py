n, m = map(int, raw_input().strip().split(' '))
ma = {}
for it in xrange(m):
    a, b = raw_input().strip().split(' ')
    if len(a) > len(b):
        ma[a] = b
    else:
        ma[b] = a
ans = []
inp = raw_input().strip().split(' ')
for x in inp:
    if x in ma:
        ans.append(ma[x])
    else:
        ans.append(x)
print ' '.join(ans)

