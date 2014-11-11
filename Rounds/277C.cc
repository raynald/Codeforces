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

int min(int x, int y) {
    int a,b;
    a = x;
    b = y;
    if(a<0) a=-a;
    if(b<0) b=-b;
    return a>b?b:a;
}

int diff(char a, char b) {
    if(a>b) {
        return min(a-b, b-a+26);
    }
    else {
        return min(b-a, a-b+26);
    }
}

int main() {
    int n, p;
    string str;
    int t;
    int ans;
    int left, right;

    cin >> n >> p;
    cin >> str;
    ans = 0;
    if(p>(n+1)/2) p = n+1-p;
    left = n+1;right = 0;
    for(int i=1;i<=(n+1)/2;i++) {
        t = diff(str[i-1], str[n-i]);
        if(t>0 && i>right) {
            right = i;
        }
        if(t>0 && i<left) {
            left = i;
        }
        ans += t;
    }
    if(right!=0 || left!=n+1) ans += min(right-p, p-left) + (right-left);
    cout << ans << endl;
    return 0;
}

