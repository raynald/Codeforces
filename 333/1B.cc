#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100010;

long long absolute(long long x) {
    return x > 0 ? x: -x;
}

long long calc(vector<long long> &in) {
    int k;
    long long solution;
    long long tmp;
    long long item;
    in.push_back(1e8 + 10);
    k = 0;
    solution = 0;
    vector<long long> stack;
    vector<int> id_stack;
    for(int k = 0;k < in.size(); k++) {
        item = in[k];
        while (1) {
            if (stack.size() == 0 || stack.back() > item) { 
                stack.push_back(item);
                id_stack.push_back(k + 1);
                break;
            } else {
                int left;
                if (stack.size() == 1) {
                    left = 0;
                } else {
                    left = id_stack[id_stack.size() - 2];
                }
                tmp = stack.back();
                tmp *= k + 1 - id_stack.back();
                tmp *= id_stack.back() - left;
                solution += tmp;
                stack.pop_back();
                id_stack.pop_back();
            }
        }
    }
    return solution;
}

int main() {
    long long array[MAXN];
    int left, right;
    int n, q;
    vector<long long> diff;

    cin >> n >> q;
    for (int i = 0;i < n;i ++) 
        cin >> array[i];
    while (q--) {
        cin >> left >> right;
        diff.clear();
        for(int i = left - 1;i < right - 1;i ++) 
            diff.push_back(absolute(array[i] - array[i + 1]));
        cout << calc(diff) << endl;
    }
}
