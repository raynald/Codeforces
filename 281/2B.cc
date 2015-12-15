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

int main() {
    int n;
    int a;
    long long sum;
    vector<int> b;
    vector<int> c;
    bool flag;

    cin >> n;
    sum = 0;
    b.clear();
    for(int i=0;i<n;i++) {
        cin >> a;
        sum += a;
        if(a>0) b.push_back(a);
        else c.push_back(-a);
    }
    if(a>0) flag = 1; else flag = 0;
    if(sum>0) flag = 1; else 
        if(sum<0) flag = 0;
        else {
            if(b.size()<c.size()) flag = 1;
            for(int i=0;i<b.size();i++) {
                if(i==c.size()) {
                    flag = 0;
                    break;
                }
                if(b[i]>c[i]) {
                    flag = 1;
                    break;
                }
                if(b[i]<c[i]) {
                    flag = 0;
                    break;
                }
            }
        }
    if(flag) puts("first"); else puts("second");
    return 0;
}
