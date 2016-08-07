#include<bits/stdc++.h>

using namespace std;

int main() {
    int n , c;
    int ans = 0;

    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0;i < n;i ++) {
        cin >> c;
        if (c % 2 == 0) ans ^= 1; else ans ^= 0;
        if (ans == 0) puts("2"); else puts("1");
    }

    return 0;
}
