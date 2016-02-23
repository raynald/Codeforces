import sys

f = sys.stdin
n = f.readline().strip()
arr = f.readline().split(' ')
ans = 0
b = []
for it in arr:
    t = int(it)
    if t % 2 == 0:
        ans += t
    else:
        b += [t]
ans += sum(b)
if len(b) % 2:
    ans -= min(b)
print ans
