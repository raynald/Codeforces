#include<bits/stdc++.h>

using namespace std;

int dp[510][510];

int n, k;
vector<int> c;
bool flag;

int main() {
    cin >> n >> k;
    c.resize(n);
    for(int i = 0;i < n;i ++) {
        cin >> c[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    sort(c.begin(), c.end());
    flag = 0;
    for(int t = 0;t < n;t ++) {
        for(int i = k;i >= c[t];i --) {
            for(int j = 0;j <= k;j ++) {
                if(dp[i - c[t]][j]) {
                    dp[i][j] = 1;
                    if(j + c[t] <= k) dp[i][j + c[t]] = 1;
                }
            }
        }
    }
    int cc = 0, at = 0;
    for(int i = 0;i <= k;i ++) if(dp[k][i]) cc ++;
    cout << cc << endl;
    for(int i = 0;i <= k;i ++) {
        if(dp[k][i]) {
            cout << i;
            at ++;
            if (at < cc) cout << " ";
        }
    }
    cout << endl;
    return 0;
}
