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

int a[100010];

int search(int left, int right, int value) {
    if(left>right) return -1;
    int mid=(left+right)/2;
    if(a[mid]==value) return mid;
    if(a[mid]>value) return search(left, mid-1, value); else return search(mid+1, right, value);
}

int main() {
    int n, l, x, y;
    bool flag, flag2;

    cin >> n >> l >> x >> y;
    for(int i=0;i<n;i++) cin >> a[i];
    flag = flag2 = 1;
    if(search(0, n-1, x) == -1) {
        flag = 0;
        for(int i=0;i<n-1;i++) {
            if(search(i+1,n-1,x+a[i]) != -1) {
                flag = 1;
                break;
            }
        }
    }
    if(search(0,n-1,y)==-1) {
        flag2 = 0;
        for(int i=0;i<n-1;i++) {
            if(search(i+1,n-1,y+a[i]) != -1) {
                flag2 = 1;
                break;
            }
        }
    }
    if(flag+flag2==0) {
        for(int i=0;i<n-1;i++) {
            if(search(i+1,n-1,x+y+a[i]) != -1) {
                cout << 1 << endl;
                cout << x+a[i] << endl;
                return 0;
            }
            if(search(0,n-1,a[i]-x-y) != -1) {
                cout << 1 << endl;
                cout << a[i]-x << endl;
                return 0;
            }
            if(a[i]-y>=0 && search(0,n-1,a[i]+x-y) != -1) {
                cout << 1 << endl;
                cout << a[i]-y << endl;
                return 0;
            }
            if(a[i]+x<=l && search(0,n-1,a[i]+x-y) != -1) {
                cout << 1 << endl;
                cout << a[i]+x << endl;
                return 0;
            }
            if(a[i]-x>=0 && search(0,n-1,a[i]+y-x) != -1) {
                cout << 1 << endl;
                cout << a[i]-x << endl;
                return 0;
            }
            if(a[i]+y<=l && search(0,n-1,a[i]+y-x) != -1) {
                cout << 1 << endl;
                cout << a[i]+y << endl;
                return 0;
            }
        }
        cout << 2 << endl;
        cout << x << " " << y << endl;
    }
    else if(flag+flag2==2) {
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
        if(flag) cout << y << endl; else cout << x << endl;
    }
    
    return 0;
}
