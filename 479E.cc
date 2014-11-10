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

int abs(int x) {
    return x<0?-x:x;
}

const int MAXH = 1000000007;

int main() {
    int n, a, b, k;
    int dp[5010];
    int dp2[5010];
    int accu[5010];
    int sum;
    int t;

    cin >> n >> a >> b >> k;
    memset(dp, 0, sizeof(dp));
    dp[a]=1;
    for(int t=1;t<=k;t++) {
        memset(dp2,0,sizeof(dp2));
        accu[0]=0;
        for(int i=1;i<=n;i++) {
            accu[i]=(accu[i-1]+dp[i])%MAXH;
        }
        for(int i=1;i<=n;i++) {
            if(i<b) {
                if(i<b-1) {
                    dp2[i] = ((accu[(b+i)/2-1]-dp[i])%MAXH+MAXH)%MAXH;
                }
                else {
                    if(b>3) dp2[i] = (accu[b-2])%MAXH;
                }
            }
            if(i>b) {
                if(i>b+1) {
                    dp2[i] = ((accu[n]-accu[(i+b)/2]-dp[i])%MAXH+MAXH)%MAXH;
                }
                else {
                    if(b+1<n) dp2[i] = (accu[n]-accu[b+1])%MAXH;
                }
            }
        }
        memcpy(dp,dp2,sizeof(dp2));
        for(int i=1;i<=n;i++)cout << dp[i]<<" ";
        cout << endl;
    }
    sum = 0;
    for(int i=1;i<=n;i++) sum=(sum+dp[i])%MAXH;
    cout << sum << endl;
    return 0;
}
