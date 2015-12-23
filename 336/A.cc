#include<iostream>
#include<algorithm>

using namespace std;

int n, s;

struct cmp {
    int f, t;
};

cmp a[110];
int ti, fl;

bool comp(cmp &x, cmp &y) {
    return (x.f > y.f);
}

int main() {
    cin >> n >> s;
    for(int i=0;i<n;i++) {
        cin >> a[i].f >> a[i].t;
    }
    sort(a, a+n, comp);
    ti = 0;
    fl = s;
    for(int i=0;i<n;i++) {
        if(ti + fl - a[i].f < a[i].t) {
            ti = a[i].t;
        } else {
            ti += fl - a[i].f;
        }
        fl = a[i].f;
    }
    cout << ti + fl << endl;
    return 0;
}
