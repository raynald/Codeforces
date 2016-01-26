#include<stdio.h>

long long a[4];
long long b[4];
int n,j;
int t,i;
int ans;
int q,p;

int abs(int x) {
    return x > 0 ? x : -x;
}

int main() {
    int n = 3;
    for(i=0;i<n;i++) {
        scanf("%d %d", &p, &q);
        a[i] = (long long)p;
        b[i] = (long long)q;
    }
    ans = 3;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(b[i] > b[j]) {
                t=a[i];a[i]=a[j];a[j]=t;
                t=b[i];b[i]=b[j];b[j]=t;
            }
        }
    }
    if (b[0] == b[1]) {
        if ((a[0] - a[2]) * (a[1] - a[2]) >= 0) ans = 2;
    }
    if (b[2] == b[1]) {
        if ((a[2] - a[0]) * (a[1] - a[0]) >= 0) ans = 2;
    }
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(a[i] > a[j]) {
                t=a[i];a[i]=a[j];a[j]=t;
                t=b[i];b[i]=b[j];b[j]=t;
            }
        }
    }
    if (a[0] == a[1]) {
        if ((b[0] - b[2]) * (b[1] - b[2]) >= 0) ans = 2;
    }
    if (a[2] == a[1]) {
        if ((b[2] - b[0]) * (b[1] - b[0]) >= 0) ans = 2;
    }
    if (a[0] == a[1] && a[1] == a[2]) ans = 1;
    if (b[0] == b[1] && b[1] == b[2]) ans = 1;

    printf("%d\n", ans);

    return 0;
}
