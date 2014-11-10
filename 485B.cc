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

int n;
int x[1010];
int y[1010];

const int MM = 1000000000;

int min(int x, int y) {
    return x>y?y:x;
}

int max(int x, int y) {
    return x<y?y:x;
}

int xmin, xmax, ymin, ymax;
long long ans;

int main() {
    scanf("%d", &n);
    ymin = xmin = MM;
    ymax = xmax = -MM;
    for(int i = 0;i < n;i ++) {
        scanf("%d %d", x+i, y+i);
        xmin = min(x[i], xmin);
        ymin = min(y[i], ymin);
        xmax = max(x[i], xmax);
        ymax = max(y[i], ymax);
    }
    ans = max(xmax-xmin, ymax-ymin);
    cout << ans * ans << endl;
    
    return 0;
}

