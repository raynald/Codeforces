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

const int MAXH = int(1e5+10);

bool v[MAXH];
int deg[MAXH];

struct cmp {
    int to;
    int next;
    int w;
};

struct cmp2 {
    int a;
    int b;
    int c;
    double d;
};


cmp d[2*MAXH];
cmp2 mat[MAXH];
int start[MAXH];
int edge;

double comb(int x) {
    if(x<2) return 0;
    else return 1.0*x*(x-1)*(x-2)/6;
}

void dfs(int x) {
    v[x] = 1;
    deg[x] = 1;
    for(int i=start[x];i!=-1;i=d[i].next) {
        if(!v[d[i].to]) {
            dfs(d[i].to);
            deg[x] += deg[d[i].to];
        }
    }
}

int main() {
    int n, q;
    int a, b, c;

    cin >> n;
    memset(start,-1,sizeof(start));
    memset(v,0,sizeof(v));
    edge= 0;
    for(int i=1;i<n;i++) {
        cin >> a >> b >> c;
        mat[i].a = a;
        mat[i].b = b;
        mat[i].c = c;
        edge++;
        d[edge].to = b;
        d[edge].w = c;
        d[edge].next = start[a];
        start[a] = edge;

        edge++;
        d[edge].to = a;
        d[edge].w = c;
        d[edge].next = start[b];
        start[b] = edge;
    }
    dfs(1);
    /*
    for(int i=1;i<=n;i++) {
        cout << deg[i]<<endl;
    }
    */
    double bbig = comb(n);
    double sum = 0;
    for(int i=1;i<n;i++) {
        int u, v;
        u = deg[mat[i].a];
        v = deg[mat[i].b];
        if(u<v) swap(u,v);

        mat[i].d = 2.0*(1.0 - (comb(n-v)+comb(v))/bbig);
        //cout << mat[i].d << " " << mat[i].c<<endl;
        sum += mat[i].d * mat[i].c;
    }
    cin >> q;
    for(int i=1;i<=q;i++) {
        cin >> a >> b;
        sum -= mat[a].d * (mat[a].c-b);
        mat[a].c = b;
        printf("%.9lf\n", sum);
    }
    return 0;
}
