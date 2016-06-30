#include<bits/stdc++.h>

using namespace std;

bool mat[110][110];
int n, d;
char ch;

int main() {
    int ans = 0;
    bool flag;
    int sum;

    cin >> n >> d;
    sum = 0;
    for(int i = 0;i < d;i ++) {
        flag = 1;
        for(int j = 0;j < n;j ++) {
            cin >> ch;
            while (ch != '0' && ch != '1') cin >> ch;
            if(ch == '0') flag = 0;
        }
        if(flag) {
            ans = max(ans, sum);
            sum = 0;
        } else sum ++;
    }
    ans = max(ans, sum);
    cout << ans << endl;

    return 0;
}
