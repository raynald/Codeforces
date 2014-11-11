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

string s2;
int dp[30];
int ans;
int county;
int sum;

void search(int x, int y) {
    if(x==s2.length()) {
        if(y==ans) county ++;
        sum ++;
        return;
    }
    if(s2[x]=='+') search(x+1, y+1);
    else if(s2[x]=='-') search(x+1, y-1);
    else {
        search(x+1, y+1);
        search(x+1, y-1);
    }
}

int main() {
    string s1;

    cin >> s1 >> s2;
    memset(dp, 0, sizeof(dp));
    ans = 0;
    county = 0;
    sum = 0;
    for(int i=0;i<s1.length();i++) {
        if(s1[i]=='+') ans++; else ans--;
    }
    search(0, 0);
    if(sum==0) puts("0.000000000000\n"); else printf("%.12lf\n", county*1.0/sum);
    return 0;
}

