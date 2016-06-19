import sys

f = sys.stdin
n, k = map(int, f.readline().strip().split(' '))
ans = (n / k + 1) * k
print(ans)
