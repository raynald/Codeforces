import sys

class Comp:
    def __init__(self, pos, num):
        self.pos = int(pos)
        self.num = int(num)

num_of_tree = int(sys.stdin.readline())
T = []
for item in xrange(0, num_of_tree):
    mPos, mNum = sys.stdin.readline().split(' ')
    T += [Comp(mPos, mNum)]
T_sorted = sorted(T, key=lambda Comp:Comp.pos)
if T_sorted[0].pos > 0:
    print T_sorted[0].num
else:
    pos_i = len(T) - 1
    for x in xrange(0, len(T)-1):
        if T_sorted[x].pos < 0 and T_sorted[x+1].pos>0:
            pos_i = x
            break
    pos_j = pos_i + 1
    ans = 0
    while pos_i >= 0 and pos_j < len(T):
        ans += T_sorted[pos_i].num + T_sorted[pos_j].num
        pos_i -= 1
        pos_j += 1
    if pos_i >= 0:
        ans += T_sorted[pos_i].num
    if pos_j < len(T):
        ans += T_sorted[pos_j].num
    print ans

