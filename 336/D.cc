#include<iostream>
#include<cstring>

using namespace std;

int n;
int dp[510][510];
int mat[510];

int main() {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++) {
        cin >> mat[i];
        dp[i][i] = 1;
        if(i>0) {
            if(mat[i-1] == mat[i]) dp[i-1][i] = 1; else dp[i-1][i] = 2;
        }
    }
    for(int i=3;i<=n;i++) {
        for(int j=0;j<=n-i;j++) {
            dp[j][j+i-1] = i;
            for(int k=1;k<i;k++) {
                if(dp[j][j + k - 1] + dp[j + k][j + i - 1] < dp[j][j+i-1]) {
                    dp[j][j+i-1] = dp[j][j + k - 1] + dp[j + k][j + i - 1];
                }
            }
            if(mat[j] == mat[j + i - 1]) {
                if(dp[j+1][j+i-2] < dp[j][j+i-1]) dp[j][j+i-1] = dp[j+1][j+i-2];
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
