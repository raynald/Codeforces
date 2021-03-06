import sys

f = sys.stdin
origin = f.readline().strip()
n = len(origin)
m = {}
for ch in origin:
    if ch in m:
        m[ch] += 1
    else:
        m[ch] = 1
rank = []
for key, value in m.items():
    if value % 2:
        rank.append(key)
rank = sorted(rank)
for i in xrange(len(rank) / 2):
    m[rank[i]] += 1
    m[rank[-1-i]] -= 1
if len(rank) % 2:
    mid = rank[len(rank)/2]
else:
    mid = '-'
rank = sorted(m.keys())
out = ''
for item in rank:
    out += item * (m[item] / 2)
if mid != '-':
    out = '%s%s%s' % (out, mid, out[::-1])
else:
    out = '%s%s' % (out, out[::-1])
print out