"""
Grundy number and Sprague-Grundy's Theorem
    The smallest whole number which is not the Grundy number of any state that can be reached in the next step
    Losing if Grundy number is 0
case 1) k is even
    f(0) = 0, f(1) = 1, f(2) = 2, f(3) = 0, f(4) = 1
    for n >= 2, f(2n-1) = 0, f(2n) = 1
case 2) k is odd
    f(0) = 0, f(1) = 1, f(2) = 0, f(3) = 1, f(4) = 2, f(5) = 0, f(6) = 2,
    for n >= 2, f(2n) > 0, f(2n + 1) = 0
"""

import sys

def mex(x):
    if x == 0:
        return 1
    if x == 1:
        return 2
    return 1

def find(x, k):
    if k % 2:
        if x == 0:
            return 0
        if x == 1:
            return 1
        if x == 2:
            return 0
        if x == 3:
            return 1
        if x == 4:
            return 2
        if x % 2:
            return 0
        else:
            return mex(find(x / 2, k))
    else:
        if x == 0:
            return 0
        if x == 1:
            return 1
        if x == 2:
            return 2
        return (x + 1) % 2

line = sys.stdin.readline()
n, k = line.strip().split(" ")
n = int(n)
k = int(k)
line = sys.stdin.readline()
array = line.strip().split(" ")
ans = -1
for item in array:
    item = int(item)
    x = find(item, k)
    if ans == -1:
        ans = x
    else:
        ans ^= x
if ans == 0:
    print "Nicky"
else:
    print "Kevin"
