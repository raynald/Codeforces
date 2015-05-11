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

const int maxh = 100010;
const int maxv = int(1e9+7);

struct cmp {
    int to;
    int val;
};

int n;
int tmp;
int a,b,c;
long long ans;
int q,u,v;
cmp mat[maxh][3];
int d[maxh];
long long one[maxh];
long num[maxh];
long long dep[maxh];
bool vis[maxh];
long long two[maxh];
bool judge[maxh];

void dfs(int x, long long y, bool z) {
    long long u, v, t;
    u = v = t = 0;
    vis[x] = 1;
    for(int i=0;i<d[x];i++) {
        if(!vis[mat[x][i].to]) {
            dfs(mat[x][i].to, y+mat[x][i].val, z);
            u = (u+one[mat[x][i].to])%maxv;
            v = (v+two[mat[x][i].to])%maxv;
            t = (t+num[mat[x][i].to])%maxv;
        }
    }
    one[x] = (u+ y)%maxv;
    two[x] = (v + y*y)%maxv;
    judge[x] = z;
    num[x] = t + 1;
    dep[x] = y;
}

int main() {
    cin >> n;
    memset(d,0,sizeof(d));
    memset(judge,0,sizeof(judge));
    memset(num,0,sizeof(num));
    memset(dep,0,sizeof(dep));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<n;i++) {
        cin >> a >> b >> c;
        mat[a][d[a]].to=b;
        mat[a][d[a]].val=c;
        d[a]++;
        mat[b][d[b]].to=a;
        mat[b][d[b]].val=c;
        d[b]++;
    }
    vis[1]=1;
    if(d[1]==1) {
        dfs(mat[1][0].to, mat[1][0].val,0);
        one[1] = one[mat[1][0].to] + mat[1][0].val;
        two[1] = two[mat[1][0].to] + mat[1][0].val;
        num[1] = num[mat[1][0].to] + 1;
    }
    if(d[1]==2) {
        dfs(mat[1][0].to,mat[1][0].val,0);
        dfs(mat[1][1].to,mat[1][1].val,1);
        one[1] = one[mat[1][1].to]+ one[mat[1][0].to];
        two[1] = two[mat[1][1].to]+ two[mat[1][0].to];
        num[1] = num[mat[1][1].to]+ num[mat[1][0].to] + 1;
    }
    cout << two[1] << " " << one[1] << endl;
    cin >> q;
    for(int i=0;i<q;i++) {
        cin >> u >> v;
        if(u==1) {
            ans = (2*two[v] - two[1])%maxv;
        }
        else  {
            if(judge[mat[1][0].to]!=judge[u]) tmp = mat[1][0].to; else tmp = mat[1][1].to;
            if(v==1) {
                ans = (two[1]+ ((num[1]*dep[u])%maxv*dep[u])%maxv - 2*dep[u]*(one[1]-one[tmp]) + 2 * dep[u]*one[tmp])%maxv;
            }
            else {
                if(judge[u]!=judge[v]) {
                    ans = (two[v]+ ((dep[u]*dep[u])%maxv*num[v])%maxv+2*dep[u]*one[v]-
                        ((two[tmp]-two[v])+(dep[u]*dep[u])%maxv*(num[tmp]-num[v])+2*dep[u]*(one[tmp]-one[v])
                         +(two[1]-two[tmp])+ (dep[u]*dep[u])%maxv*(num[1]-num[tmp])-2*dep[u]*(one[1]-one[tmp])))%maxv;
                }
                else {
                    ans = (two[v]+ (dep[u]*dep[u])%maxv*num[v]-2*dep[u]*one[v]-
                        ((two[1]-two[tmp]-two[v])+(dep[u]*dep[u])%maxv*(num[1]-num[v]-num[tmp])-2*dep[u]*(one[1]-one[v]-one[tmp])
                         +two[tmp]+ (dep[u]*dep[u])%maxv*num[tmp]+2*dep[u]*one[tmp]))%maxv;
                }
            }
        }
        cout << (ans+maxv)%maxv << endl;
    }
    return 0;

}
