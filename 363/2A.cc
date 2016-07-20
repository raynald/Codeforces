#include<bits/stdc++.h>

using namespace std;

int n;
string dire;
vector<int> v;
int ans;

int main() {
    cin >> n;
    cin >> dire;
    v.resize(n);
    for(auto &item: v) cin >> item;
    ans = INT_MAX;
    for(int i = 1;i < n;i ++) {
        if (dire[i] == 'L' && dire[i - 1] == 'R') {
            ans = min(ans, abs(v[i] - v[i - 1]) / 2);
        }
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
