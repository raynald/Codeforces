#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> f;
vector<int> p;
vector<int> v;
int root = -1;

int find(int x) {
    if(f[x] < 0) return x;
    int ff = find(f[x]);
    f[x] = ff;
    return ff;
}

int main() {
    cin >> n;
    f.resize(n + 1, -1);
    v.resize(n + 1);
    for(int i = 1;i <= n;i ++) {
        cin >> v[i];
    }
    for(int i = 1;i <= n;i ++) {
        if(find(i) != find(v[i])) f[find(i)] = find(v[i]);
        else {
            if (v[i] == i && root == -1) root = i;
            else p.push_back(i);
        }
    }
    if (root > -1) {
        for(auto &item: p) v[item] = root;
    } else {
        root = p[0];
        for(auto &item: p) v[item] = root;
    }
    cout << p.size() << endl;
    for(int i = 1;i <= n;i ++) cout << v[i] << " \n"[i == n];

    return 0;
}

