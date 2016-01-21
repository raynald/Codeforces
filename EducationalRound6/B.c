#include <stdio.h>

int main() {
    int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int ans, t;
    int a, b;

    scanf("%d %d", &a, &b);
    ans = 0;
    for (int i = a;i <= b;i ++) {
        t = i;
        while (t) {
            ans += num[t % 10];
            t /= 10;
        }
    }
    printf("%d\n", ans);

    return 0;
}

