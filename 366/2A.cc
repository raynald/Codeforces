#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string ans;

    ios::sync_with_stdio(false);
    cin >> n;
    ans = "I hate";
    for(int i = 0;i < (n - 1) / 2;i ++) {
        ans += " that I love that I hate";
    }
    if (n % 2 == 0) ans += " that I love";
    ans += " it";
    cout << ans << endl;

    return 0;
}
