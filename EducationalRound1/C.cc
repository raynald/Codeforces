/*
 * Lesson: use atan2, more precise than atan
 */
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef long double ld;

const ld pi = 3.141592653589793238462;
const int MAXN = 1e5 + 10;

struct cmp {
    int index;
    ld val;
};

int n;
cmp m[MAXN];

ld calc(ld x, ld y) {
    return atan2(y, x);
}


bool comp(const cmp x, const cmp y) {
    return x.val < y.val;
}

int main() {
    ld ans;
    int ans_j;
    ld x, y;

    cin >> n;
    cout.precision(30);
    for(int it=1;it<=n;it++) {
        cin >> x >> y;
        m[it - 1] = {it, calc(x,y)};
    }
    std::sort(m, m+n, comp);
    ans = m[0].val - m[n - 1].val + 2 * pi;
    ans_j = n - 1;
    for(int it=0;it<n - 1;it++) {
        if (m[it + 1].val - m[it].val < ans) {
            ans = m[it + 1].val - m[it].val;
            ans_j = it;
        }
    }
    cout << m[ans_j].index << " " << m[(ans_j + 1) % n].index << endl;
    
    return 0;
}
