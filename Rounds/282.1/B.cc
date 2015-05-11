#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

bool v[int(1e5+10)];
int space;
int len;
const int MAXH = int(1e9+7);

void compute(string W, int next[]) {
    int pos = 2;
    int pre = 0;
    next[0] = -1;
    next[1] = 0;
    while(pos < W.length()) {
        if(W[pos-1] == W[pre]) {
            pre ++;
            next[pos] = pre;
            pos++;
        }
        else {
            if(pre>0) pre = next[pre];
            else {
                next[pos] = 0;
                pos ++;
            }
        }
    }
}

void kmp_search(string S, string W) {
    int pos = 0;
    int pos_i = 0;
    int next[W.length()];

    compute(W, next);
    while (pos + pos_i < S.length()) {
        if(S[pos + pos_i] == W[pos_i]) {
            if(pos_i == len - 1) {
                v[pos+len-1]=1;
                if(next[pos_i] > -1) {
                    pos = pos + pos_i - next[pos_i];
                    pos_i = next[pos_i];
                }
                else {
                    pos_i = 0;
                    pos ++;
                }
            }
            else pos_i ++;
        }
        else {
            if(next[pos_i] > -1) {
                pos = pos + pos_i - next[pos_i];
                pos_i = next[pos_i];
            }
            else {
                pos_i = 0;
                pos ++;
            }
        }
    }
}

int main() {
    string S, T;
    long long dp, sum;
    long long sos[int(1e5+7)];

    memset(v,0,sizeof(v));
    memset(sos,0,sizeof(sos));
    cin >> S >> T;
    len = T.length();
    kmp_search(S, T);
    space = -1;
    dp = sum = 0;
    for(int i=0;i<S.length();i++) {
        if(v[i]) {
            space = i-len+1;
        }
        if(space>=0) {
            dp = space+1;
            if(space>0) dp= (dp+sos[space-1])%MAXH;
            sum = (sum+dp)%MAXH;
            if(i>0) sos[i] = (sos[i-1]+ sum)%MAXH; else sos[i] = sum;
        }
    }
    cout << sum << endl;
    return 0;
}
