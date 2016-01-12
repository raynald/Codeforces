#include<stdio.h>
#include<string.h>
#define MAXN 1000010

char A[MAXN];
char B[MAXN];
int i, j, k;
int lena, lenb;

int main() {
    scanf("%s", A);
    scanf("%s", B);
    lena = strlen(A);
    lenb = strlen(B);
    i = 0, j = 0;
    while (A[i] == '0') i ++;
    while (B[j] == '0') j ++;
    if (lena - i < lenb - j) {
        puts("<");
    } else if (lena - i > lenb - j) {
        puts(">");
    } else {
        for (k = 0; k < lena - i;k ++) {
            if (A[i + k] < B[j + k]) {
                puts("<");
                return 0;
            }
            if (A[i + k] > B[j + k]) {
                puts(">");
                return 0;
            }
        }
        puts("=");
    }
    
    return 0;
}
