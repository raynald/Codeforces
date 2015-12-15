import sys

lucky = sys.stdin.readline().strip()
li = list(lucky)
length = len(li)
ans = 0
for rn in xrange(length):
    ans += pow(2, rn)
    if li[rn] == '7':
        ans += pow(2, length-1-rn)
print ans
# 4 7 44 47 74 77 444 447 474 477 744
