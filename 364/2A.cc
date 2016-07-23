#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> a;

bool cmp(pii &x, pii &y) {
    return x.first < y.first;
}

int main() {
    int n;
    int b;

    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> b;
        a.push_back({b, i});
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0;i < n / 2;i ++) {
        cout << a[i].second << " " << a[n - 1 - i].second << endl;
    }
    return 0;
}
