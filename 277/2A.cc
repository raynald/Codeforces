#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

int main() {
    long long n;

    cin >> n;
    if(n%2) cout << n / 2 - n << endl; else cout << n/2 << endl;
    return 0;
}
