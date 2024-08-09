#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int res = 0;
        if ((a1 > b1 && a2 > b2) || (a1 == b1 && a2 > b2) || (a1 > b1 && a2 == b2)) {
            res += 2;
        }
        if ((a1 > b2 && a2 > b1) || (a1 == b2 && a2 > b1) || (a1 > b2 && a2 == b1)) {
            res += 2;
        }
        cout << res << endl;
    }
    return 0;
}