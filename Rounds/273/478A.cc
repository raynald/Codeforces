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
    int c1, c2, c3, c4, c5;
    int t;

    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    t = c1 + c2 + c3 + c4 + c5;
    if(t%5 || t<5) cout << -1 << endl; else cout << t/5 << endl;
    
    return 0;
}
