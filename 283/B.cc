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

struct cmp {
    int x, y;
    cmp() {}
    cmp(int u, int v):x(u),y(v) {}
};

bool comp(const cmp u, const cmp v) {
    return u.x<v.x || (u.x==v.x && u.y<v.y);
}

int main() {
    int n;
    int c;
    int a[int(1e5)+10];
    int b[int(1e5)+10];
    int q,p;
    map<int, int> map1;
    map<int, int>::iterator got1;
    map<int, int>::iterator got2;
    map<int, int> map2;
    vector<cmp> v;
    int sum, ans1, ans2;

    cin >> n;
    a[0]=b[0]=0;
    for(int i=1;i<=n;i++) {
        cin >> c;
        if(c==1) {
            a[i]=a[i-1]+1;
            b[i] = b[i-1];
            map1.insert(pair<int, int>(a[i],i));
        }
        else {
            b[i]=b[i-1]+1;
            a[i]=a[i-1];
            map2.insert(pair<int, int>(b[i],i));
        }
    }
    if(a[n]>b[n]) sum=a[n]; else sum=b[n];
    for(int i=1;i<=sum;i++) {
        ans1 =ans2= 0;
        p = q = 0;
        while(1) {
            p+=i;
            q+=i;
            got1 = map1.find(p);
            got2 = map2.find(q);
            if(got1==map1.end() && got2==map2.end()) break;
            if(got1==map1.end()) {
                ans2++;
                p = a[got2->second];
            }
            else if(got2==map2.end()) {
                ans1++;
                q = b[got1->second];
            }
            else if(got1->second<got2->second) {
                ans1++;
                q = b[got1->second];
            }
            else if(got1->second>got2->second) {
                ans2++;
                p = a[got2->second];
            }
        }
        if(ans1>ans2) {
            got1 = map1.find(p-i);
            if(got1!=map1.end() && got1->second == n) v.push_back(cmp(ans1,i));
        }
        if(ans1<ans2) {
            got2 = map2.find(q-i);
            if(got2!=map2.end() && got2->second == n) v.push_back(cmp(ans2,i));
        }
    }
    cout << v.size() << endl;
    if(v.size()>0) {
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++) {
            cout << v[i].x << " " <<v[i].y<<endl;
        }
    }

    return 0;
}

