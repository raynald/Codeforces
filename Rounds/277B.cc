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
    int m, n;
    int A[110][110];
    int B[110][110];
    bool flag;

    cin >> m >> n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            cin >> B[i][j];
            A[i][j]=1;
        }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            if(B[i][j] ==0) {
                for(int k=0;k<m;k++)
                    A[k][j]=0;
                for(int k=0;k<n;k++)
                    A[i][k]=0;
            }
        }
     for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            if(B[i][j]) {
                flag = 0;
                for(int k=0;k<m;k++)
                    if(A[k][j]) {
                        flag = 1;
                        break;
                    }
                for(int k=0;k<n;k++)
                    if(A[i][k]) {
                        flag = 1;
                        break;
                    }
                if(!flag) {
                    puts("NO");
                    return 0;
                }
            }
        }
    puts("YES");
    for(int i=0;i<m;i++) {
        cout << A[i][0];
        for(int j=1;j<n;j++) {
            cout << " " << A[i][j];
        }
        cout << endl;
    }
    return 0;
}
