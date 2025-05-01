#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int minIdx = 0, maxIdx = 0;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < a[minIdx]) {
                minIdx = i;
            }
            if (a[i] > a[maxIdx]) {
                maxIdx = i;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int l = -1;
        bool conflict = false;
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                if (l == -1) {
                    l = a[i] + b[i];
                } else if (l != a[i] + b[i]) {
                    conflict = true;
                    break;
                }
            }
        }
        if (conflict) {
            cout << 0 << endl;
            continue;
        }
        if (l != -1) {
            if (l - a[maxIdx] < 0 || l - a[minIdx] > k) {
                cout << 0 << endl;
            } else {
                cout << 1 << endl;
            }
            continue;
        }
        cout << k - (a[maxIdx] - a[minIdx]) + 1 << endl;
    }

    return 0;
}
