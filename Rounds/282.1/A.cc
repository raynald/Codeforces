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
    c2 = 0;
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
        for(int i=fin+1;i<S.length();i++) {
            if(S[i]=='(') c2++;
            if(S[i]==')') c2--;
            if(c2<0) {
                flag = 0;
                break;
            }
        }
        if(c2>0) flag = 0;
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
