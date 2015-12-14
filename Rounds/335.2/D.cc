#include<iostream>
#include<algorithm>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    bool mst;
    int id;
    
    Edge() {
        from = to = weight = 0;
        mst = 0;
    }
};

const int MAX = 1e5 + 7;
Edge edge[MAX];
int n, m;

bool cmp(const Edge &x, const Edge &y) {
    return x.mst == y.mst ? x.weight < y.weight: x.mst > y.mst;
}

bool cmp_(const Edge &x, const Edge &y) {
    return x.id < y.id;
}

void init() {
    cin >> n >> m;
    for (int i = 0;i < m;i ++) {
        edge[i].id = i;
        cin >> edge[i].weight >> edge[i].mst;
    }
    sort(edge, edge + m, cmp);
}

void calc() {
    for (int i = 0;i < n - 1;i ++) {
	edge[i].from = i;
	edge[i].to = i + 1;
    }
    int source = 0;
    int to = 2;
    for (int i = n - 1;i < m;i ++) {
	if (edge[to - 1].weight > edge[i].weight) {
	    cout << "-1" << endl;
	    return;
	} else {
	    edge[i].from = source;
	    edge[i].to = to;
	    if (source == to - 2) {
		source = 0;
		to ++;
	    } else {
		source ++;
	    }
	}
    }
    sort(edge, edge + m, cmp_);
    for (int i = 0;i < m;i ++) {
        cout << edge[i].from + 1 << " " << edge[i].to + 1 << endl;
    }
}

int main() {
    init();
    calc();
    return 0;
}
