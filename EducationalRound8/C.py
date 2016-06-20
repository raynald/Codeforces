import sys

f = sys.stdin

def check(x, y):
    ans = 0
    for ch1, ch2 in zip(x, y):
        ans += abs(ord(ch1)-ord(ch2))
    return ans

n, k = map(int, f.readline().strip().split(' '))
string = f.readline().strip()
new_string = ""
left = k
for ch in string:
    l = ord(ch) - ord('a')
    r = ord('z') - ord(ch)
    if left > max(l, r):
        if l > r:
            new_string += 'a'
            left -= l
        else:
            new_string += 'z'
            left -= r
    else:
        if l > r:
            new_string += chr(ord(ch) - left)
            left = 0
        else:
            new_string += chr(ord(ch) + left)
            left = 0
if left:
    print(-1)
else:
    print(new_string)
