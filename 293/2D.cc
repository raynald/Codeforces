#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

double dp[2010][2010];
int n, t;
double p;

int main() {
    cin >> n >> p >> t;
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1-p;
    dp[1][1] = p;
    for(int i=2;i<=t;i++) {
        dp[i][0] = (1-p) * dp[i-1][0];
        for(int j=1;j<n;j++) {
            dp[i][j] = p * dp[i-1][j-1] + (1-p) * dp[i-1][j];
        }
        dp[i][n] = p * dp[i-1][n-1] + dp[i-1][n];
    }
    double ans = 0;
    for(int i=1;i<=t;i++) {
        ans += i * dp[t][i];
    }
    printf("%lf\n",ans);
}
