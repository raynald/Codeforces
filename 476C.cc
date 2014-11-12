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

const int MAXH = 1000000007;

int main() {
    long long a, b;
    long long t, t2;

    cin >> a >> b;
    t = (b * (b-1) / 2) % MAXH;
    t2 = ((a*(a+1)/2) %MAXH * b)%MAXH + a;
    t = (t*t2)%MAXH;
    cout << t << endl;
    return 0;
}
