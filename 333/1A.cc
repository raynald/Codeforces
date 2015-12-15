#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

int n, m;
bool mat[410][410];

void init() {
    int a, b;
    
    cin >> n >> m;
    memset(mat, 0, sizeof(mat));
    for(int i = 0;i < m;i ++) {
	cin >> a >> b;
	-- a; -- b;
	mat[a][b] = 1;
	mat[b][a] = 1;
    }
    for(int i = 0;i < n;i ++) {
	mat[i][i] = -1;
    }
}

int process(int k) {
    int dist[410];
    vector<int> list;
    int now;
    
    memset(dist, -1, sizeof(dist));
    dist[0] = 0;
    list.push_back(0);
    while (!list.empty()) {
	now = list.back();
	list.pop_back();
	for (int i = 0;i < n;i ++) {
	    if (mat[now][i] == k && (dist[i] == -1 || dist[now] + 1 < dist[i])) {
		dist[i] = dist[now] + 1;
		list.push_back(i);
	    }
	}
    }
    return dist[n - 1];
}

int find_max(int x, int y) {
    if (x < 0 || y < 0) return -1;
    return x > y ? x : y;
}

int main() {
    init();
    cout << find_max(process(1), process(0)) << endl;
    return 0;
}
