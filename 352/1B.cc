#include<bits/stdc++.h>

using namespace std;

long long n, k, lft, rgt, mid, ind;
long long sum, avg;
long long a[500010];
long long s[500010];
long long step;

int search(int pivol) {
    int lft = 0; 
    int rgt = n - 1;
    int mid;
    while (lft + 1 < rgt) {
        mid = (lft + rgt) / 2;
        if (a[mid] < pivol) {
            lft = mid;
        } else {
            rgt = mid - 1;
        }
    }
    if (a[rgt] < pivol) return rgt;
    return lft;
}

int BinarySearchL(long long lft, long long rgt) {
    long long mid;
    long long val;
    while (lft + 1 < rgt) {
        mid = (lft + rgt) / 2;
        int ind = search(mid);
        val = mid * (ind + 1) - s[ind];
        if (val < k) lft = mid;
        else if (val > k) rgt = mid - 1; else return mid;
    }
    int ind = search(rgt);
    val = rgt * (ind + 1) - s[ind];
    if (val <= k) return rgt; else return lft;
}

int BinarySearchR(long long lft, long long rgt) {
    long long mid;
    long long val;
    while (lft < rgt) {
        mid = (lft + rgt) / 2;
        ind = search(mid);
        val = s[n - 1] - s[ind] - mid * (n - 1 - ind);
        if (val < k) rgt = mid;
        else if (val > k) lft = mid + 1; else return mid;
    }
    return rgt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0;i < n;i ++) 
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0;i < n;i ++) {
        if(i == 0) s[i] = a[i]; else s[i] = s[i - 1] + a[i];
    }
    lft = a[0];
    rgt = a[n - 1];
    sum = s[n - 1];
    avg = sum / n;
    ind = search(avg);
    step = max(avg * (ind + 1) - s[ind], s[n - 1] - s[ind] - avg * (n - 1 - ind));
    // cout << step << endl;
    if (step <= k) {
        if (sum % n) cout << 1 << endl; else cout << 0 << endl;
    } else {
        // cout << BinarySearchR(avg, rgt) << " " << BinarySearchL(lft, avg) << endl;
        cout << BinarySearchR(avg, rgt) - BinarySearchL(lft, avg) << endl;
    }

    return 0;
}

