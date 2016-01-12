#include<stdio.h>
#include<string.h>

int ans;
int n, m;
int x, y;
int a[110];

int main() {
    scanf("%d %d", &n, &m);
    memset(a, 0, sizeof(a));
    for(int i = 0;i < n;i ++) {
        scanf("%d", &x);
        for(int j = 0;j < x;j ++) {
            scanf("%d", &y);
            a[y - 1] = 1;
        }
    }
    ans = 0;
    for(int i = 0;i < m;i ++)
        ans += a[i];
    if (ans == m) {
        puts("YES");
    } else {
        puts("NO");
    }
}
