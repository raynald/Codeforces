#include<iostream>

using namespace std;

typedef long long ll;

ll n, a, b, c;
ll ans;

int main() {
    cin >> n;
    cin >> a >> b >> c;

    if (n < b || a <= b - c) {
        cout << n / a << endl;
    } else {
        if (a >= b) {
            cout << (n - b) / (b - c) + 1 << endl;
        } else {
            // a < b, a > b - c
            cout << (n - b) / (b - c) + 1 + 
                    ((n - b) % (b - c) + c ) / a << endl;
        }
    }

    return 0;
}

