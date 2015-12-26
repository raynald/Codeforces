#include<iostream>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
int c[MAXN];
vector<int> mat[MAXN];
long long sum[MAXN];
int con[MAXN];
map<int, int> *m[MAXN];

void merge(int root, int parent) {
    int child;

    for (int i=0;i<mat[root].size();i ++) {
        child = mat[root][i];
        if (child == parent) continue;
        merge(child, root);
        if(m[child]->size() > m[root]->size()) {
            swap(m[child], m[root]);
            sum[root] = sum[child];
            con[root] = con[child];
        }
        for(auto item: *m[child]) {
            auto p = m[root] -> find(item.first);
            if (p != m[root] -> end()) {
                p -> second += item.second;
            } else {
                m[root] -> insert(item);
            }
            int val = (*m[root])[item.first];
            if (val > con[root]) {
                con[root] = val;
                sum[root] = item.first;
            } else if (val == con[root]) {
                sum[root] += item.first;
            }
        }
        delete m[child];
    }
}

int main() {
    int a, b;
    int node;

    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> c[i];
        con[i] = 1;
        m[i] = new map<int, int>;
        (*m[i])[c[i]] = 1;
        sum[i] = c[i];
    }
    for(int i = 1;i < n;i ++) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    merge(1, -1);
    for(int i = 1;i <= n;i ++) {
        cout << sum[i];
        if (i == n) cout << "\n"; else cout << " ";
    }
    return 0;
}

