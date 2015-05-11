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

int m, s, ds;
int A[110];
int B[110];

int main() {
    cin >> m >> s;
    ds = s;
    memset(A,0,sizeof(0));
    if(s>m*9 || m>1 && s<1) {
        cout << -1 << " " << -1 << endl;
    }
    else {
        for(int i=m-1;i>=0;i--) {
            if(s<10) {
                if(i==0) {
                    A[i]=s;
                }
                else {
                    A[i]=s-1;
                    A[0]=1;
                }
                break;
            }
            else {
                A[i]=9;
                s-=9;
            }
        }
        for(int i=0;i<m;i++) 
            cout << A[i];
        cout << " ";
        for(int i=0;i<m;i++) {
            if(ds<9) {
                B[i]=ds;
                break;
            }
            else {
                B[i]=9;
                ds-=9;
            }
        }
        for(int i=0;i<m;i++) {
            cout << B[i];
        }
        cout << endl;
    }
    return 0;
}
