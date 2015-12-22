import sys

n, bx = sys.stdin.readline().split(" ")
n = int(n)
bx = int(bx)
arrx = sys.stdin.readline().split(" ")
m, by = sys.stdin.readline().split(" ")
m = int(m)
by = int(by)
arry = sys.stdin.readline().split(" ")
ansx = 0
for item in arrx:
    ansx = ansx * bx + int(item)
ansy = 0
for item in arry:
    ansy = ansy * by + int(item)
if ansx > ansy:
    print ">"
elif ansx < ansy:
    print "<"
else:
    print "="

