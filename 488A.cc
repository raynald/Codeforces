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

bool check(int x) {
    int y = x;
    if (y<0) y = -y;
    while(y>0) {
        if(y%10==8) return 1;
        y /= 10;
    }
    return 0;
}
int main() {
    int n;
    int b;

    cin >> n;
    b=0;
    while(1) {
        b++;
        if(check(n+b)) {
            cout << b << endl;
            break;
        }
    }
    return 0;
}
