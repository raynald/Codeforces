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

long long cnt1, cnt2, x, y;

long long search(long long left, long long right) {
    if(right-left<=1) {
        if(left-left/x<cnt1 || left-left/y<cnt2 || left-left/x/y<cnt1+cnt2) return right; else return left;
    }
    int mid = (left+right)/2;
    if(mid-mid/x<cnt1 || mid-mid/y<cnt2 || mid-mid/x/y<cnt1+cnt2) return search(mid+1, right);
    else return search(left, mid);
}
int main() {
    long long v;

    cin >> cnt1 >> cnt2 >> x >> y;
    v = search(cnt1+cnt2, 2*(cnt1+cnt2));
    cout << v << endl;
    return 0;
}
