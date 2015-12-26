#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const long double PI = 3.14159265358979;

const long double precision = 1e-7;

long double x1, Y1, z1, x2, y2, z2;
long double raw_1, raw_2;
long double sqr_dis;
long double area;
long double dis;
long double alpha, beta;

int main() {
    cin >> x1 >> Y1 >> z1;
    cin >> x2 >> y2 >> z2;
    sqr_dis = (x1 - x2) * (x1 - x2) + (Y1 - y2) * (Y1 - y2);
    dis = sqrt(sqr_dis);
    cout.precision(18);
    if (dis >= z1 + z2) {
        cout << "0.00000000000000000000" << endl;
    } else if (dis <= abs(z1 - z2)) {
        area = min(z1, z2);
        area = PI * area * area;
        cout << area << endl;
    } else {
        alpha = acos((z1 * z1 + sqr_dis - z2 * z2) / 2.0 / z1 / dis) * 2;
        area =  (alpha * z1 * z1 - z1 * z1 * sin(alpha)) / 2;
        beta = acos((z2 * z2 + sqr_dis - z1 * z1) / (2.0 * z2 * dis)) * 2;
        area += (beta * z2 * z2 - z2 * z2 * sin(beta)) / 2;
        cout << area << endl;
    }
    return 0;
}
