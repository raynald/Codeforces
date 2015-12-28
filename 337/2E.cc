/*
 * Trick: The 'flush' in each node. Keep the complexity of modifying O(log n) rather than O(n)
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 2e5 + 10;
typedef long long LL;

struct TreeNode {
    int lbound;
    int rbound;
    int left;
    int right;
    int flush;
    int count[10][10];
};

int n, m, k;
string str;
TreeNode T[4 * MAXN];
int ans;

void build(int num, int l, int r) {
    T[num].left = l;
    T[num].right = r;
    T[num].flush = -1;
    T[num].lbound = str[l] - 'a';
    T[num].rbound = str[r] - 'a';
    if (l == r) {
        memset(T[num].count, 0, sizeof(T[num].count));
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * num + 1, l, mid);
    build(2 * num + 2, mid + 1, r);
    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            T[num].count[i][j] = T[2 * num + 1].count[i][j] + T[2 * num + 2].count[i][j];
        }
    }
    T[num].count[T[2 * num + 1].rbound][T[2 * num + 2].lbound] ++;
}

void flush(int num, int ch) {
        memset(T[num].count, 0, sizeof(T[num].count));
        T[num].lbound = ch;
        T[num].rbound = ch;
        T[num].flush = ch;
}

void update(int num, int l, int r, int ch) {
    if (T[num].left  == l && r == T[num].right) {
        flush(num, ch);
    } else {
        if (T[num].flush > -1) {
            flush(num * 2 + 1, T[num].flush);
            flush(num * 2 + 2, T[num].flush);
            T[num].flush = -1;
        }
        if (r <= T[2 * num + 1].right) update(2 * num + 1, l, r, ch);
        else if (l >= T[2 * num + 2].left)  update(2 * num + 2, l, r, ch);
        else {
            update(2 * num + 1, l, T[2 * num + 1].right, ch);
            update(2 * num + 2, T[2 * num + 2].left, r, ch);
        }
        for(int i = 0;i < k;i ++) {
            for(int j = 0;j < k;j ++) {
                T[num].count[i][j] = T[2 * num + 1].count[i][j] + T[2 * num + 2].count[i][j];
            }
        }
        T[num].lbound = T[2 * num + 1].lbound;
        T[num].rbound = T[2 * num + 2].rbound;
        T[num].count[T[2 * num + 1].rbound][T[2 * num + 2].lbound] ++;
    }
}

int main() {
    int indicator;
    int a, b;
    char c;
    string d;
    
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> str;
    build(0, 0, n - 1);
    for (int i = 0;i < m;i ++) {
        cin >> indicator;
        if (indicator == 1) {
            cin >> a >> b >> c;
            update(0, a - 1, b - 1, c - 'a');
        } else {
            cin >> d;
            ans = 0;
            for(int j = 0;j < d.length();j ++) {
                for(int t = j + 1;t < d.length();t ++) {
                    ans += T[0].count[d[j] - 'a'][d[t] - 'a'];
                }
            }
            cout << n - ans << endl;
        }
    }

    return 0;
}

