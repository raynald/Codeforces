#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<list>
#include<set>
#include<deque>
#include<stack>
#include<bitset>

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

int n1,n2,k1,k2;
int v[51][51][2];

bool search(int x, int y, bool z) {
    if(v[x][y][z]>-1) return v[x][y][z];
    if(z==0) {
        if(x==0) {
            v[x][y][z] = 0;
            return 0;
        }
        for(int i=1;i<=k1;i++) {
            if(x==i) break;
            if(search(x-i, y, 1)) {
                v[x][y][z] = 1;
                return 1;
            }
        }
        v[x][y][z] = 0;
        return 0;
    } else {
        if(y==0) {
            v[x][y][z] = 0;
            return 0;
        }
        for(int i=1;i<=k2;i++) {
            if(y==i) break;
            if(search(x, y-i, 0)==0) {
                v[x][y][z] = 0;
                return 0;
            }
        }
        v[x][y][z] = 1;
        return 1;
    }
}

int main() {
    memset(v, -1, sizeof(v));
    cin >> n1 >> n2 >> k1 >> k2;
    if(search(n1, n2, 0)) cout << "First" << endl; else cout << "Second" << endl;
    /*
    for(int i=0;i<=n1;i++) {
        for(int j=0;j<=n2;j++) {
            for(int k=0;k<=1;k++) {
                cout << i  << " " << j <<" " << v[i][j][k] << endl;
            }
        }
    }
    */
    return 0;
}

