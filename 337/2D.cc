#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 2e5 + 10;
typedef long long LL;

struct LINE {
    int left;
    int right;
    int high;
    int loc;
};

struct TreeNode {
    int lbound;
    int rbound;
    int left;
    int right;
    int count;
    int len;
};

vector<LINE> line;
vector<int> pos;
int n;
TreeNode T[4 * MAXN];
LL ans;

bool comp(LINE &x, LINE &y) {
    return x.high < y.high;
}

void build(int num, int l, int r) {
    T[num].left = l;
    T[num].right = r;
    T[num].lbound = pos[l];
    T[num].rbound = pos[r];
    T[num].count = 0;
    T[num].len = 0;
    if (l + 1 == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * num + 1, l, mid);
    build(2 * num + 2, mid, r);
}

void update(int num, LINE x) {
    if (T[num].lbound == x.left && T[num].rbound == x.right) {
        T[num].count += x.loc;
        if (T[num].count == 0) {
            if (T[num].right == T[num].left + 1) T[num].len = 0;
            else T[num].len = T[2 * num + 1].len + T[2 * num + 2].len;
        } else {
            T[num].len = T[num].rbound - T[num].lbound;
        }
    } else {
        if (x.right <= T[2 * num + 1].rbound) update(2 * num + 1, x);
        else if (x.left >= T[2 * num + 2].lbound)  update(2 * num + 2, x);
        else {
            LINE tmp = x;
            tmp.right = T[2 * num + 1].rbound;
            update(2 * num + 1, tmp);
            tmp = x;
            tmp.left = T[2 * num + 2].lbound;
            update(2 * num + 2, tmp);
        }
        if (T[num].count == 0) {
            if (T[num].right == T[num].left + 1) T[num].len = 0;
            else T[num].len = T[2 * num + 1].len + T[2 * num + 2].len;
        } else {
            T[num].len = T[num].rbound - T[num].lbound;
        }
    }
}

int main() {
    int a, b, c, d;
    
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0;i < n;i ++) {
        cin >> a >> b >> c >> d;
        if (a == c) { if (b > d) swap(b, d); }
        if (b == d) { if (a > c) swap(a, c); }
        c ++;
        d ++;
        line.push_back({a, c, b, 1});
        line.push_back({a, c, d, -1});
        pos.push_back(a);
        pos.push_back(c);
    }
    sort(line.begin(), line.end(), comp);
    sort(pos.begin(), pos.end());
    build(0, 0, 2 * n - 1);
    ans = 0;
    update(0, line[0]);
    for (int i = 1;i < 2 * n;i ++) {
        ans += (line[i].high - line[i - 1].high) * LL(T[0].len);
        update(0, line[i]);
    }
    cout << ans << endl;
    return 0;
}

