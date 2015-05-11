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

struct cmp {
    int x,y;
    double v;
};

bool comp(cmp &s, cmp &t) {
    return s.x < t.x || (s.x == t.x && s.y > t.y);
}
int main() {
    int n, q;
    cmp seg[int(5e3+7)];
    int a[int(1e5+7)];
    int now;
    double eval;
    double maxh;
    vector<cmp> queue;

    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<q;i++) {
        cin >> seg[i].x >> seg[i].y >> seg[i].v;
    }
    sort(seg, seg+q, comp);
    queue.clear();
    eval = 0;
    now = 0;
    maxh = 0;
    for(int i=0;i<n;i++) {
        while(now<q && seg[now].x==i+1) {
            queue.push_back(seg[now]); 
            eval += seg[now].v;
            now++;
        }
        if(a[i]+eval>maxh) maxh = a[i]+eval;
        while(!queue.empty() && queue.back().y==i+1) {
            eval -= queue.back().v;
            queue.pop_back();
        }
    }
    printf("%.9lf",maxh);
    return 0;
}
