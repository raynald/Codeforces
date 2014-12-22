#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

int main() {
    string S;
    int c;
    bool flag;
    int c2;
    int fin;

    cin >> S;
    c = 0;
    fin = -1;
    flag = 1;
    for(int i=0;i<S.length();i++) {
        if(S[i]=='(') {
            c ++;
        }
        if(S[i] =='#') {
            fin = i;
            c --;
        }
        if(S[i] == ')') {
            c --;
        }
        if(c<0) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        c2 = 0;
        for(int i=0;i<S.length();i++) {
            if(S[i]=='(') c2++;
            if(S[i]==')') c2--;
            if(S[i]=='#') {
                if(i==fin) {
                    c2-=(c+1);
                }
                else c2--;
            }
            if(c2<0) {
                flag = 0;break;
            }
        }
        if(flag) {
            for(int i=0;i<fin;i++) {
                if(S[i]=='#') cout << 1 << endl;
            }
            cout << c + 1 << endl;
        }
    }
    if(!flag) puts("-1");
    return 0;
}
