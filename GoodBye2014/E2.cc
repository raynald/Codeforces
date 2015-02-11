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

const int MAXH = int(2e5+10);

int A[MAXH];
int B[MAXH];
 
struct cmp {
    int x;
    int y;
    cmp() {}
    cmp(int u, int v):x(u),y(v) {}
};

bool comp(const cmp &u, const cmp &v) {
    return u.x<v.x || u.x==v.x && u.y>v.y;
}

vector<cmp> p;
map<int, int> mmap;
map<int, int>::iterator got;
map<int, int>::iterator got2;

int main() {
    int n;
    int a, b;
    int q;
    int gap;
    int loc;
    cin >> n;
    p.clear();
    mmap.clear();
    for(int i=1;i<=n;i++) {
        cin >> a>> b;
        A[i] = a;
        B[i] = b;
        p.push_back(cmp(A[i], A[i]+B[i]));
    }
    sort(p.begin(), p.end(), comp);
    gap = 0;
    loc=p[0].y;
    mmap.insert(pair<int, int>(p[0].x, gap));
    mmap.insert(pair<int, int>(p[0].y, gap));
    for(int i = 1;i<p.size();i ++) {
        if(loc<p[i].x) gap+=p[i].x-loc;
        if(mmap.find(p[i].x)==mmap.end()) 
            mmap.insert(pair<int, int>(p[i].x, gap));
        if(mmap.find(p[i].y)==mmap.end()) 
            mmap.insert(pair<int, int>(p[i].y, gap));
        if(loc<p[i].y) loc=p[i].y;
    }
    cin >> q;
    for(int i=1;i<=q;i++) {
        cin >> a >> b;
        if(A[a]+B[a]>=A[b]) cout << 0 << endl;
        else {
            got = mmap.find(A[b]);
            got2 = mmap.find(A[a]+B[a]);
            cout <<  got->second-got2->second<< endl;
        }
    }
    return 0;
}
