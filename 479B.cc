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
    x>y?y:x;
}

int max(int x, int y) {
    x>y?x:y;
}

int main() {
    int n, k, kk;
    int a[110];
    int step[1010][2];
    int ma, mi, a_min, a_max;

    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<=k;i++) {
        a_min=a_max=a[0];
        mi = ma = 0;
        for(int j=1;j<n;j++) {
            if(a[j]<a_min) {
                a_min = a[j];
                mi = j;
            }
            if(a[j]>a_max) {
                a_max = a[j];
                ma = j;
            }
        }
        if(i==k || a_max-a_min<=1) {
            cout << a_max-a_min << " " << i << endl;
            for(int j=0;j<i;j++) {
                cout << step[j][0] << " " << step[j][1]<<endl;
            }
            break;
        }
        else {
            a[mi]++;
            a[ma]--;
            step[i][0]=ma + 1;
            step[i][1]=mi + 1;
            kk = i;
        }
    }

    return 0;
}
