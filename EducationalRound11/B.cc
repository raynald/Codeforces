#include<bits/stdc++.h>

using namespace std;

int a[100][4];
int c = 0;
int n, m;

void print(int x) {
    c --;
    cout << x;
    if (c == 0) cout << endl; else cout << " ";
}

int main() {
    bool lock = 1;

    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for(int i = 0;c < m && i < n;i ++) {
        c ++;
        a[i][0] = c;
        if (c == m) break;
        c ++;
        a[i][3] = c;
    }
    for(int i = 0;c < m && i < n;i ++) {
        c ++;
        a[i][1] = c;
        if (c == m) break;
        c ++;
        a[i][2] = c;
    }
    for(int i = 0;i < n;i ++) {
        if (a[i][1] > 0) print(a[i][1]);
        if (a[i][0] > 0) print(a[i][0]);
        if (a[i][2] > 0) print(a[i][2]);
        if (a[i][3] > 0) print(a[i][3]);
    }
    return 0;
}
