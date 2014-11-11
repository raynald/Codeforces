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
    return x>y?y:x;
}

int pack(int a, int b, int c) {
    int t;

    if(a>b) return pack(b,a,c);
    if(a>c) return pack(c,b,a);
    if(b>c) return pack(a,c,b);
    if(a>0) {
        if(c-b>1) {
            t = min((c-b)/2,b);
            return t + pack(a, b-t, c-2*t);
        }
        else {
            return a + pack(0,b-a,c-a);
        }
    }
    else {
        if(b>0) {
            if(2*b-c>2) {
                t = (2*c-b)/3;
            }
            else {
                t = min(c/2,b);
            }
            if(t==0) return 0; else return t+pack(0,b-t,c-2*t);
        }
        else return 0;
    }
}

int main() {
    int r, g, b;
    int t;
    cin >> r >> g >> b;
    cout << pack(r,g,b) << endl;

    return 0;
}

