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

int main() {
    int k, cur, row;
    string a[4];
    cin >> k;
    cout << "+------------------------+" << endl;
    a[0] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    a[1] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    a[2] = "|#.......................|";
    a[3] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    if(k<=4) {
        for(int i=1;i<=k;i++) {
            a[i-1][1]='O';
        }
    }
    else {
        for(int i=1;i<=4;i++) {
            a[i-1][1]='O';
        }
        k-=4;
        cur = 0;
        row = 3;
        while(k>0) {
            a[cur][row]='O';
            cur++;
            if(cur==4) {
                cur=0;row+=2;
            }
            else if(cur==2) cur=3;
            k--;
        }
    }
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << a[3] << endl;
    cout << "+------------------------+" << endl;

    return 0;
}
