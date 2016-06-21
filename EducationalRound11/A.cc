#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;
int n, t;

int coprime(int x, int y) {
    if (x < y) return coprime(y, x);
    if (x % y == 0) return y; else return coprime(y, x % y);
}

int main() {
    cin >> n;
    for(int i = 0;i < n;i ++) {
        cin >> t;
        a.push_back(t);
    }
    for(int i = 0;i < n - 1;i ++) {
        b.push_back(a[i]);
        if (coprime(a[i], a[i + 1]) != 1) {
            b.push_back(1);
        }
    }
    b.push_back(a[n - 1]);
    cout << b.size() - n << endl;
    for(int i = 0;i < b.size() - 1;i ++) cout << b[i] << " ";
    cout << b[b.size() - 1] << endl;

    return 0;
}

