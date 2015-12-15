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
    int A, B;

    cin >> A >> B;
    for(int i=1;i<=A;i++)
        cout << i << " ";
    cout << A+B+1 << " ";
    for(int i=A+B;i>A;i--)
        cout << i << " ";
    cout << endl;
    return 0;
}
