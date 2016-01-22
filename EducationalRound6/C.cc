#include <bits/stdc++.h>

using namespace std;

int n;
int a;
map<int, int> m;
int last;
vector<int> sum;

int main() {
    ios::sync_with_stdio(false);

    scanf("%d", &n);
    for (int i = 0;i < n;i ++) {
        scanf("%d", &a);
        auto p = m.find(a);
        if (p == m.end()) {
            m[a] = 1;
        } else {
            if (m[a] == 1) {
                sum.push_back(i + 1);
                m.clear();
            } else {
                m[a] ++;
            }
        }
    }
    if (sum.size() > 0) {
        sum[sum.size() - 1] = n;
    }
    if (sum.size() > 0) {
        printf("%d\n", sum.size());
        last = 0;
        for (int i = 0;i < sum.size();i ++) {
            printf("%d %d\n", last + 1, sum[i]);
            last = sum[i];
        }
    } else {
        puts("-1");
    }

    return 0;
}
