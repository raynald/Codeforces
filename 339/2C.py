import sys

f = sys.stdin
pi = 3.14159265358979

n, x, y = map(int, f.readline().strip().split(' '))
maxh = 0
minh = 1000000000000
for it in xrange(n):
    a, b = map(int, f.readline().strip().split(' '))
    a -= x
    b -= y
    if it == 0:
        na = a
        nb = b
    t = a * a + b * b
    if minh > t:
        minh = t
    if maxh < t:
        maxh = t
    if it > 0:
        A = old_a * old_a + old_b * old_b
        B = (old_a - a) * (old_a - a) + (old_b - b) * (old_b - b)
        if A + B > t and t + B > A:
            tmp = A - (A + B - t) * (A + B - t) / 4.0 / B
            if tmp < minh:
                minh = tmp
    old_a = a
    old_b = b

A = na * na + nb * nb
B = (old_a - na) * (old_a - na) + (old_b - nb) * (old_b - nb)
if A + B > t and t + B > A:
    tmp = A - (A + B - t) * (A + B - t) / 4.0 / B
    if tmp < minh:
        minh = tmp

print pi * (maxh - minh)
