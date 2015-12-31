import sys

f = sys.stdin
month = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
week = [52, 52, 52, 52, 53, 53, 52]
inp = f.readline().strip().split(' ')
i = int(inp[0])
if inp[2] == 'month':
    ans = 0
    for m in month:
        if i <= m:
            ans += 1
    print ans
else:
    ans = 0
    print week[i - 1]
