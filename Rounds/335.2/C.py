import sys

n = int(sys.stdin.readline())
arr = sys.stdin.readline().strip().split(' ')
dct = {}
ans = 0
for it in arr:
    item = int(it)
    if item - 1 in dct:
        dct[item] = dct[item-1] + 1
    else:
        dct[item] = 1
    if dct[item] > ans:
        ans = dct[item]
print n - ans
