# To slow for judge

n = input()
v = [0] * n
d = [0] * n
p = [0] * n
for it in xrange(n):
    v[it], d[it], p[it] = map(int, raw_input().strip().split(' '))
ans = []
def cry(x):
    for k in xrange(x + 1, n):
        if p[k] >= 0:
            p[k] -= d[x]
            if p[k] < 0:
                cry(k)

for i in xrange(n):
    if p[i] >= 0:
        ans += [str(i + 1)]
        cnt = 0
        cry_list = []
        for j in xrange(i + 1, n):
            if v[i] - cnt  == 0:
                break
            if p[j] >= 0:
                p[j] -= v[i] - cnt
                if p[j] < 0:
                    cry_list.append(j)
                cnt += 1
        for it in cry_list:
            cry(it)
print len(ans)
print ' '.join(ans)
