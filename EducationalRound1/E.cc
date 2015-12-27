#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int N, M, K;
int t;
int tmp;
int f[35][35][55];
int i, j, k, a, b;
int i1, i2, i3, i4;

void precompute() {
    memset(f, 0, sizeof(f));
    for(i = 1;i <= 30;i ++) {
        for(j = 1;j <= min(i, 30);j ++) {
            for(k = 1;k <= min(50, i * j);k ++) {
                if(i * j == k) {
                    f[i][j][k] = 0;
                    continue;
                }
                f[i][j][k] = 2e9;
                for(a = 1;a < j;a ++) {
                    for(b = 0;b <= k;b ++) {
                        if(b > i * a || k - b > i * (j - a)) continue;
                        f[i][j][k] = min(f[i][j][k], f[i][a][b] + f[i][j - a][k - b] + i * i);
                    }
                }
                for(a = 1;a < i;a ++) {
                    for(b = 0;b <= k;b ++) {
                        i1 = a; i2 = j;
                        i3 = i - a;i4 = j;
                        if (i1 < i2) swap(i1, i2);
                        if (i3 < i4) swap(i3, i4);
                        if (b > i1 * i2 || k - b > i3 * i4) continue;
                        f[i][j][k] = min(f[i][j][k], f[i1][i2][b] + f[i3][i4][k - b] + j * j);
                    }
                }
            }
        }
    }
}

int main() {
    precompute();
    scanf("%d", &t);
    while(t --) {
        scanf("%d %d %d", &N, &M, &K);
        if (N < M) swap(N, M);
        printf("%d\n", f[N][M][K]);
    }
    return 0;
}

