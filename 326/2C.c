#include<stdio.h>
#include<string.h>

int n,b,s,i;
int a[1000030];

int main() {
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++) {
        scanf("%d",&b);
        ++a[b];
    }
    s=0;
    for(i=0;i<1000029;i++) {
        a[i+1]+=a[i]/2;
        a[i]%=2;
        s+=a[i];
    }
    printf("%d\n",s);
    return 0;
}

