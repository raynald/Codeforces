#include<bits/stdc++.h>

using namespace std;

int n;
map<int, long long> s;
long long ans = 0;

int main() {
    int x;

    cin >> n;
    for (int i = 0;i < n;i ++) { 
        cin >> x;
        if (s.find(x) == s.end()) {
            s[x] = 1;
        } else s[x] ++;
    }
    for(auto &item: s) {
        for (int i = 1073741824;i >= 2 * item.first;i /= 2) {
            if (i == 2 * item.first) {
                ans += s[item.first] * (s[item.first] - 1) / 2;
            } else {
                if (s.find(i - item.first) != s.end()) {
                    ans += s[item.first] * s[i - item.first];
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}

