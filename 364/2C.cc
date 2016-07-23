#include<bits/stdc++.h>

using namespace std;

string str;
int n;
map<char, int> m;
set<char> s;
int ans;
int minh, maxh;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> str;
    for(auto &ch: str) {
        s.insert(ch);
    }
    ans = 100010;
    for(int i = 0;i < n;i ++) {
        m[str[i]] = i;
        if (m.size() == s.size()) {
            minh = 100010;
            maxh = -1;
            for(auto &item: m) {
                minh = min(item.second, minh);
                maxh = max(item.second, maxh);
            }
            ans = min(ans, maxh - minh + 1);
        }
    }
    cout << ans << endl;

    return 0;
}
