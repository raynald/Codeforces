#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1000010;

int p[MAXN];
bool v[MAXN];
int tmp;
int len;
int result[MAXN];
vector<vector<int> > stack;
vector<int> temp;
bool flag;
int n;

bool comp(vector<int> &x, vector<int> &y) {
    return x.size() < y.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    memset(v, 0, sizeof(v));
    for(int i=1;i<=n;i++) {
        cin >> p[i];
    }
    for(int i=1;i<=n;i++) {
        if(!v[i]) {
            v[i] = 1;
            len = 1;
            tmp = i;
            temp.clear();
            temp.push_back(i);
            while(!v[p[tmp]]) {
                temp.push_back(p[tmp]);
                len ++;
                v[p[tmp]] = 1;
                tmp = p[tmp];
            }
            if(len%2 == 0) {
                stack.push_back(temp);
            } else {
                for(int i=0;i<temp.size();i ++) {
                    result[temp[i]] = temp[(i+temp.size()/2 + 1)%temp.size()];
                }
            }
        }
    }
    flag = 1;
    if (stack.size()%2) flag = 0; else sort(stack.begin(), stack.end(), comp);
    for(int i=0;i<stack.size()/2;i++) {
        if(stack[i*2].size() != stack[i*2 + 1].size()) {
            flag = 0;
            break;
        }
    }
    if(!flag) {
        cout << -1 << endl;
    } else {
        for(int i=0;i<stack.size()/2;i++) {
            int vol = stack[i*2].size();
            for(int j=0;j<vol;j++) {
                result[stack[i*2][j]] = stack[i*2+1][j];
                result[stack[i*2+1][j]] = stack[i*2][(j+1)%vol];
            }
        }
        for(int i=1;i<=n;i++) {
            cout << result[i];
            cout << (i == n ? "\n": " ");
        }
    }
    return 0;
}

