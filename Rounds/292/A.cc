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
    int n;
    string str;
    string ans = "";

    cin >> n;
    cin >> str;
    for(int i=0;i<n;i++) {
        if(str[i] == '4') {
            ans += "223";
        }
        if(str[i] == '2' || str[i] == '3' || str[i] == '5' || str[i] == '7') {
            ans += str[i]; 
        }
        if(str[i] == '6') {
            ans += "53";
        }
        if(str[i] == '8') {
            ans += "2227";
        }
        if(str[i] == '9') {
            ans += "7332";
        }
    }
    for(int i=0;i<ans.length();i++) {
        for(int j=i+1;j<ans.length();j++) {
            if(ans[i] < ans[j]) swap(ans[i], ans[j]);
        }
    }
    cout << ans << endl;
    return 0;
}

