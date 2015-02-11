#include<iostream>

using namespace std;

int main() {
    int n = 65536;
    cout << n << endl;
    for(int i=0;i<n-1;i++) {
        if(i%2==0) cout << 1 << " " << i+1 << endl;
        else cout << 1 << " " << i-1 << endl;
    }
}
