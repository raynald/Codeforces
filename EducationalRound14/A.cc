#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0;
    bool x;

    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0;i < n;i ++) {
        cin >> x;
        if(x) ans++;
    }
    if ((n == 1 && ans == n) || (n > 1 && n - ans == 1)) {
        puts("YES");
    } else puts("NO");
    return 0;
}
