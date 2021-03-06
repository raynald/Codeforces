import sys

MAXN = 10 ** 9 + 7

def calc(string):
    ans = 0
    for ch in string:
        ans = (ans * 4 + ord(ch) - 96) % MAXN
    return ans

def check(string):
    tmp = calc(string)
    order = 1
    for i in xrange(len(string)-1, -1, -1):
        if string[i] == 'a':
            temp = (tmp + order) % MAXN
            if temp in H:
                if string[:i] + 'b' + string[i+1:] in H[temp]:
                    return 1
            temp = (tmp + 2 * order) % MAXN
            if temp in H:
                if string[:i] + 'c' + string[i+1:] in H[temp]:
                    return 1
        if string[i] == 'b':
            temp = (tmp + order) % MAXN
            if temp in H:
                if string[:i] + 'c' + string[i+1:] in H[temp]:
                    return 1
            temp = (tmp - order) % MAXN
            if temp in H:
                if string[:i] + 'a' + string[i+1:] in H[temp]:
                    return 1
        if string[i] == 'c':
            temp = (tmp - order) % MAXN
            if temp in H:
                if string[:i] + 'b' + string[i+1:] in H[temp]:
                    return 1
            temp = (tmp - 2 * order) % MAXN
            if temp in H:
                if string[:i] + 'a' + string[i+1:] in H[temp]:
                    return 1
        order = (order * 4) % MAXN
    return 0

f = sys.stdin
n, m = [int(x) for x in f.readline().split(' ')]
H = {}
for i in xrange(n):
    string = f.readline().strip()
    tmp = calc(string)
    if tmp in H:
        H[tmp].append(string)
    else:
        H[tmp] = [string]
for j in xrange(m):
    string = f.readline().strip()
    if check(string):
        print("YES")
    else:
        print("NO")