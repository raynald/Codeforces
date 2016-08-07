#include<bits/stdc++.h>

using namespace std;

vector<set<int> > offset;
vector<int> c; 

class BIT {
private:
    int n;
public:
    BIT(int x) {
        n = x;
        c.resize(n + 1, 0);
        offset.resize(n + 1);
    }

    int lowBit(int t) {
        return t&(-t);
    }

    void insert(int t, int y) {
        offset[t].insert(y);
        while(t<=n) {
            c[t]++;
            t+=lowBit(t);
        }
    }

    void modify(int t, int y) {
        while(t<=n) {
            c[t]+= y;
            t+=lowBit(t);
        }
    }

    void wholedelete(int x) {
        int y = offset[x].size();
        offset[x].clear();
        modify(x, -y);
    }

    void del(int x, int y) {
        if (offset[x].find(y) != offset[x].end()) {
            offset[x].erase(y);
            modify(x, -1);
        }
    }

    int getResult(int t) {
        int num = 0;
        while(t>0) {
            num+=c[t];
            t-=lowBit(t);
        }
        return num;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, q;
    int a, b;
    int read = 0;
    vector<int> tt;

    cin >> n >> q;
    BIT s(n);
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        switch (a) {
            case 1: {
                        s.insert(b, tt.size()); 
                        tt.push_back(b);
                        break;
                    }
            case 2: s.wholedelete(b); break;
            default: if (b > read) {
                         for(int j = read;j < b;j ++) {
                             s.del(tt[j], j); 
                         }
                         read = b;
                     }
                    break;
        }
        cout << s.getResult(n) << endl;
    }
 
    return 0;
}

