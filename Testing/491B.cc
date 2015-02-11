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

const int maxh = 100010;
const int maxm = 1000000010;

int diff(int x, int y) {
    return x>y?x-y:y-x;
}

int max(int x, int y) {
    return x>y?x:y;
}

int main() {
    int N, M;
    int C, H;
    bool flag;
    int x, y;
    int ans, ansj;
    int sum, tmp;
    int minh1, maxh1, minh2, maxh2;
    int hot1[maxh];
    int hot2[maxh];

    cin >> N >> M;
    cin >> C;
    maxh1=maxh2=0;
    minh1=minh2=maxm;
    for(int i=1;i<=C;i++) {
        cin >> hot1[i] >> hot2[i];
    }

    cin >> H;
    ans = maxm;
    for(int i=1;i<=H;i++) {
        cin >> x >> y;
        sum = 0; 
        flag = 1;
        for(int j=1;j<=C;j++) {
            tmp = diff(hot1[j],x)+diff(hot2[j],y);
            if(tmp>ans) {
                flag = 0;
                break;
            }
            if(tmp>sum) sum = tmp;
        }
        if(flag && sum<ans) {
            ans = sum;
            ansj = i;
        }
    }
    cout << ans << endl << ansj << endl;
    return 0;
}

