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
    int n, k;

    cin >> n >> k;
    cout << 1;
    for(int i=1;i<=k/2;i++) {
        cout << " " << k+2-i << " " << i+1;
    }
    if(k%2) cout << " " << (k+1)/2 + 1;
    for(int i=k+2;i<=n;i++) {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}
/*
1: 1 2 3 4 5 6 7 
2: 1 3 2 4 5 6 7
3: 1 4 2 3 5 6 7
4: 1 5 2 4 3 6 7
5: 1 6 2 5 3 4 7
*/


