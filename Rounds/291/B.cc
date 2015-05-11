#include<bits/stdc++.h>

using namespace std;

#define EPS (1e-9)
#define INF ((int)2e9)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i=0;i<(int)(n);++i)
#define ford(i, n) for (int i= (int)(n)-1; i>=0;--i)
#define fore(i, a, b) for(int i= (int)(a);i<=(int)(b);++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vill;
typedef vector<vill> vvill;

unordered_set<int> sset;

int main() {
    int n, x0, y0, x1, y1;
    int t;

    cin >> n >> x0 >> y0;
    for(int i=0;i<n;i++) {
        cin >> x1 >> y1;
        x1 = x1 - x0;
        y1 = y1 - y0;
        if (x1==0) {
            y1 = 1;
        } else if (y1==0) {
            x1 = 1;
        } else {
            t = __gcd(abs(x1), abs(y1));
            x1 /= t;
            y1 /= t;
            if(x1<0) {
                x1 = -x1;
                y1 = -y1;
            }
        }
        auto got = sset.find(x1*10001+y1);
        if(got==sset.end()) {
            sset.insert(10001*x1+y1);
        }
    }
    cout << sset.size() << endl;
    return 0;
}

