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

const int maxh = 200010;

int a[maxh];
int b[maxh];

int search(int left, int right, int x) {
    if(left+1>=right) {
        if(b[right] <= x) return right;
        if(b[left]>x) return left-1;
        else return left;
    }
    int mid=(left+right)/2;
    if(b[mid]>x) return search(left, mid-1, x);
    else return search(mid,right, x);
}

int main() {
    int m, n, t;
    int ans1,ans2,ans;
    int sum1, sum2;

    cin >> n;
    for(int i=0;i<n;i++) 
        cin >> a[i];
    sort(a,a+n);
    cin >> m;
    for(int i=0;i<m;i++) 
        cin >> b[i];
    sort(b,b+m);
    ans = -200000000;
    for(int i=0;i<n;i++) {
        t = search(0,m-1,a[i]-1);
        ans1 = (n-i)*3+i*2;
        ans2 = (t+1)*2+(m-t-1)*3;
        if(ans1-ans2>ans) {
            ans = ans1-ans2;
            sum1 = ans1;
            sum2 = ans2;
        }
    }
    t = search(0,m-1,a[n-1]+1);
    ans1 = n*2;
    ans2 = (t+1)*2+(m-t-1)*3;
    if(ans1-ans2>ans) {
        ans = ans1-ans2;
        sum1 = ans1;
        sum2 = ans2;
    }
    cout << sum1<<":"<<sum2<<endl;
    return 0;
}
