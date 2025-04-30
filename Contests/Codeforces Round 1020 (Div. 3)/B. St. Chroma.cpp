#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        for (int i = 0; i < min(x, n - 1); i++) {
            cout << i << " ";
        }
        for (int i = min(x + 1, n - 1); i < n; i++) {
            cout << i << " ";
        }

        if (min(x, n - 1) + n - min(x + 1, n - 1) < n) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
