#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int t;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    t = 0;
    while (n > 0) {
        t ++;
        if (n % 2) {
            v.push_back(t);
        }
        n = n >> 1;
    }
    for(int i = v.size() - 1;i>=1;i--) {
        cout << v[i] << " ";
    }
    cout << v[0] << endl;
    return 0;
}
