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

int main() {
    int n, m, k;
    int dp[n];
    int x,y;
    
    cin >> n >> m;
    for(int k = n / 2 /m;k<=n/m;k++) {
        x = n-m*k;
        y = m*k-x;
        if(x<0 || y<0) continue;
        cout << x + y << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
//2*x+y=n
//x+y=m*k
// x = n - m*k >=0;
// y = 2*m*k-n >=0;
// 2*m/n<=k<=n/m
