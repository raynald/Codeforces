import sys

f = sys.stdin

line = f.readline().strip()
print line + line[::-1]
