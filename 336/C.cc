#include<iostream>
#include<algorithm>

using namespace std;

struct cmp {
    int a, b;
};

bool comp(cmp &x, cmp &y) {
    return x.a < y.a;
}

int n;
cmp f[100010];
int dp[100010];
int a, b;
int ans;

int find(int x) {
    int left = -1;
    int right = n - 1;
    int mid;

    while(left < right - 1) {
        mid = (left + right) / 2;
        if(f[mid].a >= x) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    if(left + 1 == right) {
        if(f[right].a < x) return right; 
    }
    return left;
}

int main() {
    int idx;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        f[i].a = a;
        f[i].b = b;
    }
    sort(f, f+n, comp);
    for(int i=0;i<n;i++) {
        idx = find(f[i].a - f[i].b);
        dp[i + 1] = dp[idx + 1] + i - idx - 1;
    }
    ans = -1;
    for(int i=1;i<=n;i++) {
        if (ans == -1 || dp[i] + n - i < ans) {
            ans = dp[i] + n - i;
        }
    }
    cout << ans << endl;
    return 0;
}
