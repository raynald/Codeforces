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
    int n;
    vector<int> s, t, ans;
    long long sum, l, r;
    bool flag;
    
    cin >> n;
    while(n--) {
        cin >> l >> r;
        s.clear();
        if(r==0) s.push_back(0);
        while(r!=0) {
            s.push_back(r%2);
            r/=2;
        }
        t.clear();
        if(l==0) t.push_back(0);
        while(l!=0) {
            t.push_back(l%2);
            l/=2;
        }
        while(t.size()<s.size()) t.push_back(0);
        ans = s;
        for(int i=t.size()-1;i>=0;i--) {
            if(s[i]==t[i]) {
                ans[i]=s[i];
            }
            else {
                flag = 0;
                for(int j=i;j>=0;j--) {
                    if(ans[j]==0) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) {
                    ans[i]=0;
                    for(int j=i-1;j>=0;j--) {
                        ans[j]=1;
                    }
                }
                break;
            }
        }
        sum = 0;
        for(int i=t.size()-1;i>=0;i--) {
            sum = sum*2 + ans[i];
        }
        cout << sum << endl;
    }
    return 0;
}
