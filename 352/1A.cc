#include<bits/stdc++.h>

using namespace std;

int n;
typedef long double ld;
typedef long long ll;
ll ax, ay, bx, by, tx, ty;
ll x[100010];
ll y[100010];
ld z[100010];
ld sum, sum2;
int max_1, max_2;
int max_3, max_4;
ld ans_1, ans_2, ans_3, ans_4;
ld tmp_1, tmp_2;

ld calc(ll x, ll y, ll a, ll b) {
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}

void push_into(ld X, ld & Y, ld & Z, int & a, int & b, int v) {
    if (a == -1 || Y < X) {
        Z = Y; Y = X;
        b = a, a = v;
    } else {
        if (b == -1 || Z < X) {
            Z = X;
            b = v;
        }
    }
}

int main() {
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    sum = 0;
    for(int i = 0;i < n;i ++) {
        cin >> x[i] >> y[i];
        z[i] = calc(x[i], y[i], tx, ty);
        sum += z[i];
    }
    sum *= 2;
    max_1 = -1;
    max_2 = -1;
    max_3 = -1;
    max_4 = -1;
    for(int i = 0;i < n;i ++) {
        tmp_1 = z[i] - calc(ax, ay, x[i], y[i]);
        tmp_2 = z[i] - calc(bx, by, x[i], y[i]);
        push_into(tmp_1,
                  ans_1,
                  ans_2,
                  max_1,
                  max_2,
                  i
                  );
        push_into(tmp_2,
                  ans_3,
                  ans_4,
                  max_3,
                  max_4,
                  i
                  );
    }
    cout << setprecision(20);
    sum2 = sum - max(ans_1, ans_3);
    if (max_1 == max_3) {
        sum -= max(ans_1 + ans_4, ans_2 + ans_3);
    } else {
        sum -= (ans_1 + ans_3);
    }
    sum = min(sum, sum2);
    cout << sum << endl;
    return 0;
}
