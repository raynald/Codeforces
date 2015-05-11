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
#include<set>
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
#define forn(i, n) for (int i=0;i<(int)(n);++i)
#define ford(i, n) for (int i= (int)(n)-1; i>=0;--i)
#define fore(i, a, b) for(int i= (int)(a);i<=(int)(b);++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vill;
typedef vector<vill> vvill;

set<int> mmap;
set<int>::iterator got;

int main() {
    int n, t;
    int a, b;
    int x[66010];
    int deg[66010];
    int sum = 0;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        sum +=a;
        if(a==1) mmap.insert(i);
        x[i]= b;
        deg[i] = a;
    }
    sum/=2;
    cout << sum <<endl;
    while(mmap.size()>0) {
        got = mmap.begin();
        int tmp = *got;
        if(deg[tmp]==1) {
            cout << tmp <<  " " << x[tmp] << endl;
            deg[tmp]--;
            deg[x[tmp]]--;
            x[x[tmp]] ^= tmp;
            if(deg[x[tmp]] == 1) {
                mmap.insert(x[tmp]);
            }
        }
        mmap.erase(got);
   }
    return 0;
}
