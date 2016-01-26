#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

map<pii, bool> m;
vector<pii> v;
int n;
ll X1, Y1, x2, y2;
ll ans, t;

ll calc(ll a, ll b, ll c, ll d) {
    return (a - c) * (a - c) + (b - d) * (b - d);
}

int main() {
    ll a, b;

    cin >> n >> X1 >> Y1 >> x2 >> y2;
    for (int i = 0;i < n;i ++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 0;i < n;i ++) {
        for (int j = i + 1;j < n;j ++) {
            if (calc(v[i].fi, v[i].se, X1, Y1) > calc(v[j].fi, v[j].se, X1, Y1)) {
                swap(v[i], v[j]);
            }
        }
    }
    ans = 0;
    for (int i = 0;i < n;i ++) {
        t = calc(v[i].fi, v[i].se, x2, y2);
        if (t > ans) ans = t;
    }
    for (int i = 0;i < n;i ++)  {
        cerr << "V: " << i << " " << v[i].fi << " " << v[i].se << endl;
        a = calc(v[i].fi, v[i].se, X1, Y1);
        t = 0;
        for (int j = i + 1;j < n;j ++) {
            b = calc(v[j].fi, v[j].se, x2, y2);
            if (t < b) t = b;
        }
        cerr << a << " " << t << " " << ans << endl;
        if (a + t < ans) ans = a + t;
    }
    cout << ans << endl;

    return 0;
}
