#include <stdio.h>

int i, j, n;
int ans_j, cry_len, cnt;
int cry_list[4010];
int v[4010];
int d[4010];
int p[4010];
int ans[4010];

void cry(int x) {
    int k;

    for (k = x + 1;k < n;k ++) {
        if (p[k] >= 0) {
            p[k] -= d[x];
            if (p[k] < 0) cry(k);
        }
    }
}
int main() {
    scanf("%d", &n);
    for(i = 0;i < n;i ++) {
        scanf("%d %d %d", v + i, d + i, p + i);
    }
    for (i = 0;i < n;i ++) {
        if (p[i] >= 0) {
            ans[ans_j ++] = i + 1;
            cnt = 0;
            cry_len = 0;
            for (j = i + 1;j < n;j ++) {
                if (v[i] - cnt == 0) break;
                if (p[j] >= 0) {
                    p[j] -= v[i] - cnt;
                    if (p[j] < 0) cry_list[cry_len ++] = j;
                    cnt ++;
                }
            }
            for (j = 0;j < cry_len;j ++)
                cry(cry_list[j]);
        }
    }
    printf("%d\n", ans_j);
    for (i = 0;i < ans_j - 1;i ++) 
        printf("%d ", ans[i]);
    printf("%d\n", ans[ans_j - 1]);

    return 0;
}
