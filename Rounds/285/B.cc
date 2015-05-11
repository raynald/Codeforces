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

int n;
int t;
int q[200010];
int p[200010];

class BIT {
private:
    int A[200010];
    int c[200010];
    int n;
public:
    BIT() {}

    int lowBit(int t) {
        return t&(-t);
    }

    void build(int x) {
        n = x;
        memset(A,0, sizeof(A));
        for(int i=1;i<=n;i++) {
            c[i] = A[i];
            for(int j=i-1;j>i-lowBit(i);j-=lowBit(j))
                c[i] += c[j];
        }
    }

    void build2(int x) {
        n = x;
        for(int i=1;i<=n;i++) {
            c[i] = 1;
            for(int j=i-1;j>i-lowBit(i);j-=lowBit(j))
                c[i] += c[j];
        }
    }


    void modify(int t, int delta) {
        while(t<=n) {
            c[t]+=delta;
            t+=lowBit(t);
        }
    }

    int getResult(int t) {
    //return sum_{i=1}^{t} A[i]
        int num = 0;
        while(t>0) {
            num+=c[t];
            t-=lowBit(t);
        }
        return num;
    }
    
    int get(int x, int y) {
        return getResult(y) - getResult(x-1);
    }

    int get2(int t) {
        int ans = t;
        int w = 1;
        while(c[w]<ans) {
            if(w+lowBit(w)<=n && c[w+lowBit(w)]<ans) {
                w+=lowBit(w);
            }
            else {
                ans-=c[w];
                w++; 
            }
        }
        return w;
    }
};

int main() {
    cin >> n;
    BIT s;
    s.build(n);
    for(int i=0;i<n;i++) {
        cin >> t;
        p[i] = t - s.getResult(t+1);
        s.modify(t+1, 1);
    }
    s.build(n);
    for(int i=0;i<n;i++) {
        cin >> t;
        q[i] = t - s.getResult(t+1);
        s.modify(t+1, 1);
    }
    s.build2(n);
 
    int c =0;
    int tmp = 0;
    for(int i=n-1;i>=0;i--) {
        tmp = (p[i]+q[i]+c)%(n-i);
        c = (p[i]+q[i]+c)/(n-i);
        q[i] = tmp;
    }
    for(int i=0;i<n;i++) {
        int tmp = s.get2(q[i]+1);
        cout << tmp -1 << " \n"[i==n-1];
        s.modify(tmp, -1);
    }
    return 0;
}
