#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> s;
int e;
int n, m;

int search1(int x, int l, int r) {
    if(l >= r - 1) {
        if (s[r] <= x) return s[r];
        return s[l];
    }
    int m = (l + r) / 2;

    if (s[m] > x) {
        return search1(x, l, m - 1);
    } else {
        return search1(x, m, r);
    }
}

int search2(int x, int l, int r) {
    if (l >= r - 1) {
        if(s[l] >= x) return s[l];
        return s[r];
    }
    int m = (l + r) / 2;

    if (s[m] < x) {
        return search2(x, m + 1, r);
    } else {
        return search2(x, l, m);
    }
}

int find(int x) {
    int a = search1(x, 0, s.size() - 1);
    int b = search2(x, 0, s.size() - 1);
    return min(abs(x - a), abs(b - x));
}

int main() {
    cin >> n >> m;
    a.resize(n);
    s.resize(m);
    for (auto &item: a) {
        cin >> item;
    }
    for (auto &item: s) {
        cin >> item;
    }
    sort(s.begin(), s.end());
    int ans = -1;
    for(auto &item: a) {
       ans = max(ans, find(item)); 
    }
    cout << ans << endl;

    return 0;
}
