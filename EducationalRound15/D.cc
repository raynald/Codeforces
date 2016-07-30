#include<bits/stdc++.h>

using namespace std;

int main() {
    long long d,k,a,b,t,X;
    long long ans;

    cin >> d >> k >> a >> b >> t;
    if( d > k && (a - b) * k + t > 0) {
        cout << (a - b) *k + b * d << endl;
    } else {
        X = d / k;
        if (X > 0) ans = ((a - b)* k + t) * X + b * d - t;
        else ans = b * d;
        ans = min(ans, (a * k + t) * X + d % k * a);
        cout << ans << endl;
    }

    return 0;
}
