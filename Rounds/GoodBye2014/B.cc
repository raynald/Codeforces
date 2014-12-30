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

class ds {
    private:
        vector<int> p;
    public:
        ds (int n) {
            for(int i=0;i<n;i++) {
                p.push_back(-1);
            }
        }
        int find(int x) {
            if(p[x]<0) return x; 
            p[x] = find(p[x]);
            return p[x];
        }
        int uni(int x, int y) {
            int rx = find(x);
            int ry = find(y);
            if(rx==ry) return -1;
            p[rx] += p[ry];
            p[ry] = rx;
            return 0;
        }
        int get_size(int x) {
            int rx = find(x);
            return -p[rx];
        }
        ~ds() {
            p.clear();
        }
};

int main() {
    int n;
    int A[310];
    //int mat[310][310];
    char c;

    cin >> n;
    ds d(n);
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> c;
            while(c!='0' && c!='1') cin >> c;
            if(c=='1') {
                d.uni(i,j);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(d.find(i)==d.find(j) && A[i]>A[j]) {
                swap(A[i],A[j]);
            }
        }
    }
    for(int i=0;i<n-1;i++) {
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    return 0;
}
