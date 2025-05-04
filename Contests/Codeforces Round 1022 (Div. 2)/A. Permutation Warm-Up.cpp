#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += abs(i - (n - i + 1));
        }
        cout << res / 2 + 1 << endl;
    }
    return 0;
}
