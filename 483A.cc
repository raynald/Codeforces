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

long long gcd(long long x, long long y) {
    if(x<y) return gcd(y,x);
    if(x%y==0) return  y; else return gcd(x%y, y);
}

int main() {
    long long l, r;

    cin >> l >> r;
    if (r - l <= 1) {
        cout << -1 << endl;
    }
    else {
        if(l % 2) {
            if(r >= l + 3) {
                cout << l+1 << " "<< l+2 <<" "<< l+3 << endl;
            }
            else {
                if (gcd(l+2, l)>1) {
                    cout << l << " "<<l+1 <<" "<< l+2 << endl;
                }
                else {
                    cout << -1 << endl;
                }
            }
        }
        else {
            cout << l << " "<<l+1 <<" "<< l+2 << endl;
        }
    }
    return 0;
}
