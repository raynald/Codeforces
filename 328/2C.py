#!/usr/bin/python

from fractions import gcd
import sys

f = sys.stdin
inp = [int(x) for x in f.readline().split(' ')]
if inp[1] > inp[2]:
    inp[1], inp[2] = inp[2], inp[1]
lcm = inp[1] / gcd(inp[1], inp[2]) * inp[2]
ans = inp[1] * (inp[0] /  lcm) + min(inp[0] % lcm,  inp[1] - 1)
gc = gcd(ans, inp[0])
print "%d/%d" % (ans / gc, inp[0] / gc)
