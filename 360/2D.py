import sys
from fractions import gcd

f = sys.stdin

n, k = map(int, f.readline().strip().split(' '))
c = f.readline().strip().split(' ')
r = 1
for item in c:
    item = int(item)
    t = gcd(k, item / gcd(item, r))
    k /= t
    r *= t
if k == 1:
    print "Yes"
else:
    print "No"

