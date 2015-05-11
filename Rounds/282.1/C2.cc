#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

int n, q;

    int a[int(1e5+7)];
int now;
    double eval;
    double maxh;


struct cmp {
    int x,y;
    double v;
};

    cmp seg[int(5e3+7)];
    vector<cmp> queue;
bool comp(cmp &s, cmp &t) {
    return s.x < t.x || (s.x == t.x && s.y > t.y);
}

int cnt;

void search(int x) {
    if(x==q) {
        maxh = 1;
        cnt = 0;
        for(int i=0;i<q;i++) {
            if(a[i]) {
                maxh *= seg[i].v;
                cnt++;
            }
            else maxh *= (1-seg[i].v);
        }
        eval += cnt * maxh;
    }
    else {
        a[x] = 1;
        search(x+1);
        a[x] = 0;
        search(x+1);
    }
}

int main() {
    eval = 0;
    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<q;i++) {
        cin >> seg[i].x >> seg[i].y >> seg[i].v;
    }
    eval = 0;
    search(0);
    printf("%.9lf",eval);
    return 0;
}
