#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int maxE = -1;
        int res = 0;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            res += (x - 1) + x;
            maxE = max(maxE, x);
        }
        res -= (maxE - 1) + maxE;
        cout << res << endl;
    }
    return 0;
}
