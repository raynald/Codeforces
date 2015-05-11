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
    int cur, n;
    int a[5010];
    int b[5010];

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i] >> b[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i]>a[j] || (a[i]==a[j] && b[i]>b[j])) {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
        }
    }
    cur = 0;
    for(int i=0;i<n;i++) {
        if(b[i]>=cur) cur = b[i]; else cur=a[i];
    }
    cout << cur << endl;
    return 0;
}
