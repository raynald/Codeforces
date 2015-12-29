#!/usr/bin/python

import sys

f = sys.stdin
n, m = f.readline().strip().split(' ')
n = int(n)
m = int(m)
ans = 0
for it in xrange(n):
    arr = [int(x) for x in f.readline().strip().split(' ')]
    for sit in xrange(m):
        if arr[2 * sit] + arr[2 * sit + 1] > 0:
            ans += 1
print ans

