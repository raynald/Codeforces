#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;
    v.resize(n);
    for (auto &item: v) {
        cin >> item;
    }
    int ans = 0;
    int old = -1;
    int res = -1;
    for (auto &item: v) {
        if (item > old) {
            ans ++;
            if (ans > res) res = ans;
        } else {
            ans = 1;
        }
        old = item;
    }
    cout << res << endl;

    return 0;
}

