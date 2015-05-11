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
    int n;
    int t;
    int A[3010];
    int maxi, maxj;

    cin >> n;
    for(int i=0;i<n;i++) 
        cin >> A[i];
    cout << n<< endl;
    for(int i=0;i<n;i++) {
        maxi = A[i]; maxj = i;
        for(int j=i+1;j<n;j++) {
            if(A[j]<maxi) {
                maxi = A[j];
                maxj = j;
            }
        }
        t = A[i];
        A[i] = A[maxj];
        A[maxj]=t;
        cout << i << " " << maxj << endl;
    }
    return 0;
}
