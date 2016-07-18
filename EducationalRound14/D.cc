#include<bits/stdc++.h>

using namespace std;


class Disjoint {
private:
    vector<int> s;
public:
    Disjoint(int x) {
        s.resize(x, -1);
    }

    void merge(int x, int y) {
        int p = find(x);
        int q = find(y);
        if(p == q) return;
        s[p] += s[q];
        s[q] = p;
    }
    int find(int x) {
        if(s[x] < 0) return x;
        int p = find(s[x]);
        s[x] = p;
        return p;
    }
};

int main() {
    int n, m;
    vector<int> num;
    int a, b;

    ios::sync_with_stdio(false);
    cin >> n >> m;
    Disjoint d(n);
    num.resize(n);
    for(auto &item: num) {
        cin >> item;
    }
    for(int i = 0;i < m;i ++) {
        cin >> a >> b;
        d.merge(--a, --b);
    }
    map<int, vector<int> > ma;
    for(int i = 0;i < n;i ++) {
        ma[d.find(i)].push_back(i);
    }
    for(auto item: ma) {
        vector<int> tmp;
        for(auto ele: item.second) {
            tmp.push_back(- num[ele]);
        }
        sort(tmp.begin(), tmp.end());
        int count = 0;
        for(auto ele: item.second) {
            num[ele] = - tmp[count++];
        }
    }
    for(int i = 0;i + 1 < n;i ++) cout << num[i] << " ";
    cout << num[n - 1] << endl;

    return 0;
}
