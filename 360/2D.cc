#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k, c, r, s, t;

    ios::sync_with_stdio(0);
    cin >> n >> k;
    r = 1;
    for(int i = 0;i < n;i ++) {
        cin >> c;
        t = __gcd(k, c / __gcd(c, r));
        k /= t;
        r *= t;
    }
    if (k == 1) puts("Yes"); else puts("No");
    return 0;
}

