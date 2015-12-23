#include<iostream>

using namespace std;

string stra, strb;
int sum[200010];
long long ans;
int tmp;

int main() {
    cin >> stra;
    cin >> strb;
    sum[0] = 0;
    for(int i=0;i<strb.length();i ++) {
        sum[i + 1] = sum[i] + strb[i] - '0';
    }
    ans = 0;
    for(int i=0;i<stra.length();i++) {
        tmp = sum[strb.length() - stra.length() + i + 1] - sum[i];
        if(stra[i]-'0') {
            tmp = strb.length() - stra.length() + 1 - tmp;
        } 
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}
