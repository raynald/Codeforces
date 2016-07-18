#include<bits/stdc++.h>

using namespace std;

set<char> mirror = {'A', 'H', 'I', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'};
map<char, char> leftright = {{'b', 'd'}, {'d', 'b'}, {'p', 'q'}, {'q', 'p'}};

char trans(char x) {
    if(mirror.find(x) != mirror.end()) {
        return x;
    } else {
        if (leftright.find(x) != leftright.end()) {
            return leftright[x];
        } else return '#'; 
    }
}

int main() {
    string str;

    ios::sync_with_stdio(false);
    cin >> str;
    if(str.length() % 2){
        int n = (str.length() - 1) / 2;
        bool flag = 1;
        for(int i = 0;n + i < str.length() && i <= n;i ++) {
            if (str[n - i] != trans(str[n + i])) {
                flag = 0;
                break;
            }
        }
        if (flag) puts("TAK"); else puts("NIE");
    } else {
        int n = (str.length()) / 2;
        bool flag = 1;
        for(int i = 0;n + i < str.length() && i + 1 <= n;i ++) {
            if (str[n - i - 1] != trans(str[n + i])) {
                flag = 0;
                break;
            }
        }
        if (flag) puts("TAK"); else puts("NIE");
    }

    return 0;
}
