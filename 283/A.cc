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
    int n, m;
    int f;
    bool flag;
    bool v[110];
    bool v2[110];
    int cc;

    string mat[110];

    cin >>n>>m;
    memset(v,0,sizeof(v));
    memset(v2,0,sizeof(v2));
    for(int i=0;i<n;i++) {
        cin >> mat[i];
    }
    f = m;
    for(int i=0;i<m;i++) {
        flag = 1;
        for(int j=0;j<n-1;j++) {
            if(mat[j][i]>mat[j+1][i]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            f = i;
            break;
        }
    }
    for(int i=0;i<n-1;i++) {
        if(mat[i][f]==mat[i+1][f]) v2[i]=1;
    }
    for(int j=f+1;j<m;j++) {
        for(int i=0;i<n-1;i++) {
            if(v2[i]) {
                if(mat[i][j]>mat[i+1][j]) {
                    v[j]=1;
                    break;
                }
            }
        }
        if(!v[j]) {
            for(int i=0;i<n-1;i++)
                if(v2[i] && mat[i][j]<mat[i+1][j]) v2[i]=0;
        }
    }
    cc = f;
    for(int i=f+1;i<m;i++)
        if(v[i]) {
            cc++;
        }
    cout << cc << endl;
    return 0;
}

