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

void print(string h, int a, int b) {
    cout << h  << " " << a << " " << b << endl;
}

int main() {
    string home, away;
    int n;
    int t, m;
    char ch1, ch2;
    int a[100];
    bool va[100];
    int b[100];
    bool vb[100];

    cin >> home >> away;
    cin >> n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(va,0,sizeof(va));
    memset(vb,0,sizeof(vb));
    for(int i = 0;i<n;i++) {
        cin >> t;
        cin >> ch1;
        while(ch1!='h' && ch1!='a') cin >> ch1;
        cin >> m;
        cin >> ch2;
        while(ch2!='r' && ch2!='y') cin >> ch2;
        if(ch1=='h') {
            if(va[m]) continue;
            if(ch2=='r') {
                print(home, m, t);
                va[m] = 1;
            }
            else {
                a[m] ++;
                if(a[m]>=2) {
                    print(home, m, t);
                    va[m] = 1;
                }
            }
        }
        else {
            if(vb[m]) continue;
            if(ch2=='r') {
                print(away, m, t);
                vb[m] = 1;
            }
            else { 
                b[m] ++;
                if(b[m]>=2) {
                    print(away, m, t);
                    vb[m] = 1;
                }
            }
        }
    }
    return 0;
}

