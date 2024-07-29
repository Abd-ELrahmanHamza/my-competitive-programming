#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;
        ll sum = 0;
        int minNum = INT_MAX;
        for (int i = 0; i < (n * n); i++) {
            int x;
            cin >> x;
            sum += x;
            minNum = min(minNum, x);
        }
        ll ans = (n * (n - 1) / 2) * n * (d + c);
        ll a = (sum - ans) / (n * n);
        if ((sum - ans) % (n * n) == 0 && a == minNum && a >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
