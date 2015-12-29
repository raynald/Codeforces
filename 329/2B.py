import sys

f = sys.stdin

n = int(f.readline())
x1, x2 = [int(x) for x in f.readline().split(' ')]
y = []
for x in xrange(n):
    k, b = [int(x) for x in f.readline().split(' ')]
    y.append([x1 * k + b, x2 * k + b])
y = sorted(y, key = lambda x: (x[0], x[1]))
for it in xrange(n-1):
    if y[it][0] < y[it + 1][0] and y[it][1] > y[it + 1][1]:
        print "YES"
        sys.exit()
print "NO"
