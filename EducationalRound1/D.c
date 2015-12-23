#include<stdio.h>
#include<string.h>
#define MAXH 1010

char ch;
int n, m, k;
int mat[MAXH][MAXH];
int a, b;
int tick;

void flood(int x, int y) {
    if(mat[x][y] != -1) {
        if (mat[x][y] == 0) tick ++;
        return;
    }
    mat[x][y] = -2; 
    flood(x + 1, y);
    flood(x - 1, y);
    flood(x, y + 1);
    flood(x, y - 1);
}

void fill(int x, int y, int count) {
    if(mat[x][y] >= 0) return;
    mat[x][y] = count;
    fill(x + 1, y, count);
    fill(x - 1, y, count);
    fill(x, y + 1, count);
    fill(x, y - 1, count);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    memset(mat, 0, sizeof(mat));
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            scanf("%c", &ch);
            while(ch != '.' && ch != '*') scanf("%c", &ch);
            if (ch == '.') mat[i][j] = -1;
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(mat[i][j] == -1) {
                tick = 0;
                flood(i, j);
                fill(i, j, tick); 
            }
        }
    }
    while(k --) {
        scanf("%d %d", &a, &b);
        printf("%d\n", mat[a][b]);
    }
    return 0;
}
