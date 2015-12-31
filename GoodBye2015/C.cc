#include<bits/stdc++.h>
//#include<unordered_set>

using namespace std;

#define EPS (1e-9)
#define INF ((int)2e9)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define frn(i, n) for (int i = 0;i < (int)(n);++ i)
#define ford(i, n) for (int i = (int)(n) - 1; i>=0;-- i)
#define fore(i, a, b) for(int i = (int)(a);i <= (int)(b);++ i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vill;
typedef vector<vill> vvill;

char mat[510][510];
int h, w;
int sum;
int f[510][510];
int sum2[510][510];
int sum1[510][510];
int q;
int r1, c1, r2, c2;

int main() {
    ios::sync_with_stdio(false);
    cin >> h >> w;
    memset(f, 0,sizeof(f));
    memset(sum1, 0,sizeof(sum1));
    memset(sum2, 0,sizeof(sum2));
    frn(i, h+1) {
        mat[i][0] = '#';
        mat[i][w+1] = '#';
    }
    frn(j, w+1) {
        mat[0][j] = '#';
        mat[h+1][j] = '#';
    }
    frn(i, h) {
        sum = 0;
        frn(j, w) {
            cin >> mat[i + 1][j + 1];
            sum2[i+1][j + 1] = sum2[i+1][j];
            sum1[i+1][j + 1] = sum1[i][j+1];
            if(mat[i +1][j+1]=='.') {
                if(mat[i +1][j ] == '.') {
                    sum1[i+1][j+1]++;
                    sum++;
                }
                if(mat[i ][j +1] == '.') {
                    sum2[i+1][j+1]++;
                    sum++;
                }
            } 
            f[i + 1][j + 1] = f[i][j + 1] +sum;//+ sum1[i+1][j+1] + sum2[i+1][j+1];
        }
    }
    /*
    frn(i, h) {
        frn(j, w) {
            cout << i + 1 << " " << j + 1 << " " << f[i+1][j+1] 
                << " " << sum1[i+1][j+1] << " " << sum2[i+1][j+1] << endl;
        }
    }
    */
    cin >> q;
    frn(i, q) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << f[r2][c2] - f[r1-1][c2] - f[r2][c1-1] + f[r1 - 1][c1 -1] - (sum2[r1][c2] -sum2[r1][c1-1]) - (sum1[r2][c1] - sum1[r1-1][c1])<< endl;
    }
    return 0;
}
