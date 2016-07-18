#include<bits/stdc++.h>

using namespace std;

string str;
string lft, rgt;
string lft_, rgt_;

int main() {
    // 0.00001
    // 0.0
    // 100.0
    // 123.45
    // 1637
    // .10
    // .0
    // 10.
    ios::sync_with_stdio(false);
    cin >> str;
    int pos = str.find('.');
    if(pos > -1) lft = str.substr(0, pos); else lft = str;
    int x = 0;
    while(lft[x] == '0') x ++;
    if(x == str.length()) lft = "0"; else lft = lft.substr(x);
    if(pos > -1) rgt = str.substr(pos + 1);
    if(lft == "0" || lft == "") {
        int ex;

        x = 0;
        while (x < rgt.length() && rgt[x] == '0') x ++;
        if (x == rgt.length()) {
            cout << "0" << endl;
        } else {
            cout << rgt[x];
            ex = x;
            rgt = rgt.substr(x + 1);
            x = rgt.length() - 1;
            while(x >= 0 && rgt[x] == '0') x --;
            if(x < 0) rgt = ""; else rgt = rgt.substr(0, x + 1);
            if (rgt != "") {
                cout << "." << rgt;
            } 
            cout << "E" << - ex - 1;
        }
    } else {
        int ex = lft.length() - 1;
        rgt = lft.substr(1) + rgt;
        x = rgt.length() - 1;
        while(x >= 0 && rgt[x] == '0') x --;
        if(x < 0) rgt = ""; else rgt = rgt.substr(0, x + 1);
        cout << lft[0];
        if(rgt != "") {
            cout << "." << rgt;
        } 
        if(ex > 0) {
            cout << "E" << ex;
        }
        cout << endl;
    }

    return 0;
}
