#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, l, v1, v2, k;
    double ans;
    int times;

    cin >> n >> l >> v1 >> v2 >> k;
    if (v1 >= v2) {
        ans = l * 1.0 / v1;
    } else {
        if (n % k == 0) times = n / k; else times = n / k + 1;
        ans = l * 1.0 / (v2 + 1.0 * 2.0 * v1 * v2 / (v2 + v1) * (times - 1));
        ans *= (times + (v2 - v1) * 1.0 / (v1 + v2) * (times - 1));
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;

    return 0;
}

