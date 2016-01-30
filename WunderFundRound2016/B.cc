#include<bits/stdc++.h>

using namespace std;

int n;
int v[51];
int a[51];
int s;
int t;


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++) {
        memset(v,0,sizeof(v));
        for(int j=0;j<n;j++) {
            cin >> t;
            if (v[t] == 1) a[i] = t;
            v[t] = 1;
        }
    }
    s = n - 1;
    for(int i=0;i<n;i++) {
        if(!a[i]) {a[i] = s; s++;}
    }
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
    return 0;
}
