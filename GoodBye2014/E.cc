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
 
class Segment_Tree {
private:
    struct Node {
        int left,right,cover;
    };
    Node Tree[int(4e5+10)];
    int Number, c, d;
public:
    Segment_Tree() {
    }

    void build(int Now, int a,int b) {
        Tree[Now].cover=0;
        Tree[Now].left=a;
        Tree[Now].right=b;
        if(b-a>=1) {
            int mid=(a+b)>>1;
            build(2*Now+1 , a,mid);
            build(2*Now+2,mid+1, b);
        }
    }

    void print(int Now) {
        cout << Tree[Now].left << " " << Tree[Now].right <<  " " << Tree[Now].cover << endl;
        if(Tree[Now].right>Tree[Now].left) {
            print(2*Now+1);
            print(2*Now+2);
        }
    }
    void insert(int Num, int left, int right) {
        cout << Num << " " << left << " " << right<<endl;
            int mid=(Tree[Num].left+Tree[Num].right)/2;
            if(right<=mid)
                insert(2*Num+1, left,right );
            if(left>=mid+1)
                insert(2*Num+2, left,right);
            else {
                insert(2*Num+1, left,mid);
                insert(2*Num+2, mid+1,right);
            }
            Tree[Num].cover = Tree[2*Num+1].cover+ Tree[2*Num+2].cover;
    }

    int query(int num, int left, int right) {
        if(Tree[num].left == left && Tree[num].right==right) {
            return Tree[num].cover;
        }
        const int mid = (Tree[num].left +Tree[num].right)/2;
        if(left > mid) {
            return query(2* num+2, left, right);
        }
        else if(right <= mid) {
            return query(2*num+1, left, right);
        }
        else {
            return query(2*num+1, left, mid) + query(2*num+2, mid + 1, right);
        }
    }
};


int main() {
    Segment_Tree t;
    int n;
    int a, b;
    int q;
   cin >> n;
    t.build(0, 0,n);
    for(int i=1;i<=n;i++) {
        cin >> a>> b;
        A[i] = a;
        B[i] = b;
        t.insert(0, A[i], A[i]+B[i]);
    }
    t.print(0);
    /*
    cin >> q;
    for(int i=1;i<=q;i++) {
        cin >> a >> b;
        if(A[a]+B[a]>=A[b]) cout << 0 << endl;
        else cout << A[b]-A[a]-B[a] - t.query(0, A[a]+B[a], A[b]) << endl;
    }
    */
    return 0;
}
