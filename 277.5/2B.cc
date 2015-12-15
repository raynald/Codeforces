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

int n,m;
int ans;
int a[110],b[110];
bool mat[110][110];
bool v[110];
int p[110];


bool find(int x) {
    for(int i=0;i<m;i++) {
        if(mat[x][i]==1 && !v[i]) {
            v[i]=1;
            if(p[i]==-1 || find(p[i])) {
                p[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cin >>m;
    for(int i=0;i<m;i++) {
        cin >> b[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i]-b[j]<=1 && a[i]-b[j]>=-1) mat[i][j]=1;
            else mat[i][j]=0;
        }
    }
    ans = 0;
    memset(p,-1,sizeof(p));
    for(int i=0;i<n;i++) {
        memset(v,0,sizeof(v));
        if(find(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}

