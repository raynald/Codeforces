#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

struct cmp {
    int col;
    bool color;
    int num;
};

vector<cmp> p;
vector<int> out;
set<int> sset;
bool activate;
int n, k;
int a, b;

inline bool comp(cmp &x, cmp &y) {
    return x.col < y.col ||  (x.col == y.col && x.color < y.color);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    out.reserve(2 * n);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        p.push_back({a, 0, i});
        p.push_back({b, 1, i});
    }
    sort(p.begin(), p.end(), comp);
    activate = 0;
    for(int i = 0;i < p.size();i ++) {
        cmp x = p[i];
        if(x.color) {
            sset.erase(x.num);
            if(sset.size() < k && activate) {
                activate = 0;
                out.push_back(x.col);
            }
        } else {
            sset.insert(x.num);
            if(sset.size() >= k && !activate) {
                activate = 1;
                out.push_back(x.col);
            }
        }
    }
    printf("%ld\n", out.size() / 2);
    for(int i=0;i<out.size()/2;i++) {
        printf("%d %d\n", out[i * 2] , out[i * 2 + 1]);
    }
    return 0;
}
