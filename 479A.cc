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

int max(int x, int y) {
    return x>y?x:y;
}
int main() {
    int a, b, c, t1;
    cin >> a >> b >> c;
    t1 = a+b*c;
    t1 = max(t1, a*b+c);
    t1 = max(t1, a*b*c);
    t1 = max(t1, a+b+c);
    t1 = max(t1, a*(b+c));
    t1 = max(t1, (a+b)*c);
    cout << t1 << endl; 
    return 0;
}
