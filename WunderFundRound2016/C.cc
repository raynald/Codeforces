#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> x;
vector<ll> y;
ll a, b, c;
int sum_i;
int zz;
long double sum;
long double tmp;

ll calc(ll ia, ll ib) {
    return (x[ia] - x[ib])*(x[ia]-x[ib])+(y[ia]-y[ib])*(y[ia]-y[ib]);
}

long double get(int ind) {
    ll xa, xb;
    long double cos_;
    xa = calc(0, ind);
    xb = calc(zz, ind);
    cos_ = (long double)((xa - xb + c) * 1.0);
    cos_ *= 1.0 * ((xa - xb + c) / c);
    cos_ /= 4;
    return sqrt(xa - cos_);
}

bool colinear(int ind) {
    return (x[0] - x[ind]) * (y[zz] - y[ind]) - (y[0] - y[ind]) * (x[zz] - x[ind]) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a>> b;
        x.push_back(a);
        y.push_back(b);
    }
    ll ss = 9e18;
    for(int i=1;i<n;i++) {
        if (calc(0,i) < ss) {
            ss = calc(0, i);
            zz = i;
        }
    }
    c = ss;
    sum = 9e18;
    sum_i = 1;
    for(int i=1;i<n;i++) {
        if (i == zz) continue;
        if (!colinear(i) && get(i) < sum) {
            sum = get(i);
            sum_i = i;
        }
    }
    cout << 1 << " " << zz + 1 << " " << sum_i + 1 << endl;
    return 0;
}
