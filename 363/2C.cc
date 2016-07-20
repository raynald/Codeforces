#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int event;
    int last_day;
    int rest = 0;

    cin >> n;
    for(int i = 0;i < n;i ++) {
        cin >> event;
        switch (event) {
            case 0: last_day = 0; rest ++ ;break;
            case 1: if (last_day == 1) {
                        last_day = 0;
                        rest ++;    
                    } else last_day = 1;
                    break;
            case 2: if (last_day == 2) {
                        last_day = 0;
                        rest ++;
                    } else last_day = 2;
                    break;
            case 3: if (last_day == 1) {
                        last_day = 2;
                    } else if (last_day == 2) {
                        last_day = 1;
                    } else last_day = 3;
                    break;
        }
    }
    cout << rest << endl;

    return 0;
}
