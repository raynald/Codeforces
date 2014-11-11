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

long long combi(long long x) {
    return x*(x-1)/2;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    cout << combi(n/m)*(m-n%m)+combi(1+n/m)*(n%m) << " " <<
        combi(1)*(m-1) + combi(n-(m-1)) << endl;
    return 0;
}

