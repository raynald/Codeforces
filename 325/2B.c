#include <stdio.h>

int N;
int a[55];
int b[55];
int c[55];
int s1[55];
int s2[55];
int tmp, ans;
int i,j;

int main() {
    scanf("%d", &N);
    s1[0] = 0;
    s2[N-1] = 0;
    for(i=1;i<N;i++) {
        scanf("%d",a+i);
        s1[i] = s1[i-1]+a[i];
    }
    for(i=1;i<N;i++) {
        scanf("%d",b+i);
    }
    for(i=N-2;i>=0;i--) {
        s2[i] = s2[i+1] + b[i+1];
    }
    for(i=0;i<N;i++) {
        scanf("%d",c+i);
    }
    ans = 2e9;
    for(i=0;i<N;i++) {
        for(j=i+1;j<N;j++) {
            tmp = s1[i] + c[i] + s2[i] + s1[j] + s2[j] + c[j];
            if(tmp<ans) ans=tmp;
        }
    }
    printf("%d\n", ans);

    return 0;
}
