#include<bits/stdc++.h>

using namespace std;

int main() {
    long long ans, n, m;
    long long x, y, t;
    set<long long > col, row;
    int diff;

    cin >> n >> m;
    ans = n * n;
    for(long long i = 0;i < m;i ++) {
        cin >> x >> y;
        t = 0;
        diff = 0;
        if (row.find(x) == row.end()) {
            t += n - col.size();
            diff ++;
        }
        if (col.find(y) == col.end()) {
            t += n - row.size();
            diff ++;
        }
        row.insert(x);
        col.insert(y);
        ans -= t;
        if (diff == 2) ans ++;
        cout << ans << " \n"[i == m - 1];
    }
    return 0;
}
