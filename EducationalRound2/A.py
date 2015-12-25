import sys

def isNum(x):
    if len(x) == 0:
        return False
    if len(x) > 1 and x[0] == '0':
        return False
    for ch in x:
        if ch > '9' or ch < '0':
            return False
    return True

line = sys.stdin.readline().strip()
arr = line.replace(';', ',').split(',')
num = []
nonnum = []
for item in arr:
    if isNum(item):
        num.append(item)
    else:
        nonnum.append(item)
if len(num) > 0:
    print '"' + ','.join(num) + '"'
else:
    print '-'
if len(nonnum) > 0:
    print '"' + ','.join(nonnum) + '"'
else:
    print '-'
