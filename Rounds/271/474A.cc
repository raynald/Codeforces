#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

char search(char ch, char in) {
    string a = "qwertyuiop";
    string b = "asdfghjkl;";
    string c = "zxcvbnm,./";
    if(in=='L') {
        for(int i=0;i<a.length()-1;i++) {
            if(a[i]==ch) return a[i+1];
            if(b[i]==ch) return b[i+1];
            if(c[i]==ch) return c[i+1];
        }
    }
    else {
        for(int i=1;i<a.length();i++) {
            if(a[i]==ch) return a[i-1];
            if(b[i]==ch) return b[i-1];
            if(c[i]==ch) return c[i-1];
        }
    }
    return '#';
}

int main() {
    char ch;
    string str;
    string a = "qwertyuiop";
    string b = "asdfghjkl;";
    string c = "zxcvbnm,./";
    cin >> ch;
    cin >> str;
    for(int i=0;i<str.length();i++) {
        cout << search(str[i], ch);
    }
    cout << endl;
    return 0;
}
