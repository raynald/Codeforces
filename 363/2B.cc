#include<bits/stdc++.h>

using namespace std;

vector<string> mat;
vector<int> col, row;
int n, m;
int sum = 0;

int main() {
    cin >> n >> m;
    mat.resize(n);
    row.resize(n, 0);
    col.resize(m, 0);
    for(auto &item: mat) cin >> item;
    for(int i = 0;i < n;i ++) {
        for(int j = 0;j < m;j ++) {
            if (mat[i][j] == '*') {
                sum ++;
                row[i] ++;
                col[j] ++;
            }
        }
    }
    bool answer = 0;
    auto f = [](char x) -> bool {return x == '*';};
    for(int i = 0;i < n;i ++) {
        for(int j = 0;j < m;j ++) {
            if(row[i] + col[j] - f(mat[i][j]) == sum) {
                puts("YES");
                cout << i + 1 << " " << j + 1 << endl;
                answer = 1;
                break;
            }
        }
        if (answer) break;
    }
    if (!answer) puts("NO");

    return 0;
}
