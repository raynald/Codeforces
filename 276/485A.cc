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

int a, m;
bool v[100010];

bool check() {
    while(1) {
        if (a==0) return 1;
        a = (a+a)%m;
        if(v[a]) return 0;
        v[a]=1;
    }
}

int main() {
    scanf("%d %d", &a, &m);
    a = a % m;
    memset(v,0,sizeof(v));
    if(check()) puts("Yes"); else puts("No");
    return 0;
}

