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

struct cmp {
    int pos;
    int speed;
    cmp() {}
    cmp(int x,int y):pos(x),speed(y) {}
};

int n, d;
int m;
int x;
static    int f[30010][30010];
static    bool v[30010][30010];

void dfs() {
    int p[30010];

    stack<cmp> sta;
    int speed, pos;
    
    /* init */
    memset(p, 0, sizeof(p));
    memset(v, -1, sizeof(v));
    memset(f, 0, sizeof(f));
    m = 0;
    for(int i=0;i<n;++i) {
        cin >> x;
        p[x]++;
        if(x>m) m = x;
    }

    /* actual DFS */

    sta.push(cmp(d,d));
    while(sta.size()>0) {
        pos = sta.top().pos;
        speed = sta.top().speed;
        if(v[pos][speed]) {
            sta.pop();
            f[pos][speed] = p[pos] + max(f[pos+speed-1][speed-1]
                , max(f[pos+speed][speed], f[pos+speed+1][speed+1]));
            continue;
        } else {
            v[pos][speed] = 1;
            int a, b, c;
            a = b = c = 0;
            if(pos<=m) {
                if(speed>1) sta.push(cmp(pos+speed-1, speed-1));
                sta.push(cmp(pos+speed, speed));
                sta.push(cmp(pos+speed+1, speed+1));
            }
        }
    }
    cout << f[d][d] << endl;
}

int main() {
    cin >> n >> d;
    dfs();
    return 0;
}
