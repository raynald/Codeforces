#include<bits/stdc++.h>

using namespace std;

#define EPS (1e-9)
#define INF ((int)2e9)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i=0;i<(int)(n);++i)
#define ford(i, n) for (int i= (int)(n)-1; i>=0;--i)
#define fore(i, a, b) for(int i= (int)(a);i<=(int)(b);++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vill;
typedef vector<vill> vvill;

int main() {
    bool flag;
    string str;
    cin >> str;
    flag = 0;
    for (int i=0;i<str.length();i++) {
        if(!flag && str[i] == '9') {
            flag = 1;
            continue;
        }
        if(str[i] > '4') str[i] = char('9' - str[i]) + '0';
        flag = 1;
    }
    cout << str << endl;
    return 0;
}

