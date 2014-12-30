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
/*
 * list
 * set
 * deque
 * stack
 * bitset
 * functional
 * numeric
 * utility
 * ctime
 * memory.h
 * cassert
 */

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

#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vill;
typedef vector<vill> vvill;

const int MAXH = int(1e7);

int main() {
    int v[510];
    int W[510];
    int b[1010];
    int pos[510];
    vector<int> p;
    int n, m;
    int ans;
    int tmp;

    cin >> n >> m;
    p.clear();
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++) cin >> W[i];
    for(int i=0;i<m;i++) {
        cin >> b[i];
        if(!v[b[i]]) {
            p.push_back(b[i]);
            pos[b[i]]=p.size()-1;
            v[b[i]]=1;
        }
    }
    ans = 0;
    for(int i=0;i<m;i++) {
        tmp = b[i];
        for(int j=pos[b[i]];j>0;j--) {
            p[j] = p[j-1];
            ans += W[p[j]];
            pos[p[j]]++;
        }
        p[0] = tmp;
        pos[b[i]]=0;
    }
    cout << ans << endl;
    return 0;
}

