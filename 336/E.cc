#include<iostream>

using namespace std;

const int MAXN = 1000010;
string stra, strb, new_stra;
int n;
string tmpa, tmpb;
int nxt[MAXN];

void calc(string &x) {
    int i, pre;

    nxt[0] = -1;
    nxt[1] = 0;
    i = 2; pre = 0;
    while (i < x.length()) {
        if(x[i - 1] == x[pre]) {
            pre ++;
            nxt[i] = pre;
            i ++;
        } else {
            if(nxt[pre] > 0) pre = nxt[pre];
            else {
                pre = 0;
                nxt[i] = 0;
                i ++;
            }
        }
    }
}

string check(string &x, string &y) {
    int iy, w;

    w = iy = 0;
    while(iy + w < n) {
        if (y[iy + w] == x[w]) {
            if(iy + w == n - 1) {
                return "NO";
            }
            w ++;
        } else {
            if(nxt[w] > -1) {
                iy += w - nxt[w];
                w = nxt[w];
            } else {
                iy ++;
            }
        }
    }
    return "YES";
}

inline char opo(char &x) {
    if (x == 'W') return 'E';
    if (x == 'E') return 'W';
    if (x == 'S') return 'N';
    if (x == 'N') return 'S';
    return ' ';
}

int main() {
    cin >> n;
    stra.reserve(n);
    strb.reserve(n);
    new_stra.reserve(n);
    -- n;
    cin >> stra >> strb;
    for(int i=n-1;i>=0;i--) {
        new_stra += opo(stra[i]);
    }
    calc(new_stra);
    cout << check(new_stra, strb) << endl;

    return 0;
}
