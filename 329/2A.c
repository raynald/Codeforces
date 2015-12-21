#include<stdio.h>
#include<string.h>

int n;
int mat[110][28];
char str[1010];
int ans, tmp;

int main() {
    scanf("%d", &n);
    memset(mat, 0, sizeof(mat));
    for(int i=0;i<n;i++) {
        scanf("%s", str);
        mat[i][27] = strlen(str);
        for(int j=0;j<strlen(str);j ++) {
            mat[i][str[j]-'a'] = 1;
        }
        for(int j=0;j<26;j++) {
            mat[i][26] += mat[i][j];
        }
    }
    ans = 0;
    for(int i=0;i<25;i++) {
        for(int j=i+1;j<26;j++) {
            tmp = 0;
            for(int k=0;k<n;k++) {
                if(mat[k][i] + mat[k][j] == mat[k][26]) {
                    tmp += mat[k][27];
                }
            }
            if (tmp>ans) ans=tmp;
        }
    }
    printf("%d\n", ans);
    return 0;
}

