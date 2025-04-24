#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int first0 = -1, last0 = -1;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (first0 == -1 && v[i] == 0) {
                first0 = i;
            }
            if (v[i] == 0) {
                last0 = i;
            }
        }
        if (first0 == -1) {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
        } else if (last0 == first0) {
            if (first0 == n - 1) {
                cout << 2 << endl;
                cout << first0 << " " << n << endl;
                cout << 1 << " " << n - 1 << endl;
            } else {
                cout << 2 << endl;
                cout << first0 + 1 << " " << first0 + 2 << endl;
                cout << 1 << " " << n - 1 << endl;
            }
        } else {
            if (first0 == 0) {
                if (last0 != 1) {
                    cout << 3 << endl;
                    cout << 1 << " " << 2 << endl;
                    cout << 2 << " " << n - 1 << endl;
                    cout << 1 << " " << 2 << endl;
                } else {
                    cout << 2 << endl;
                    cout << 1 << " " << 2 << endl;
                    cout << 1 << " " << n - 1 << endl;
                }
            } else if (last0 == n - 1) {
                if (first0 != n - 2) {
                    cout << 3 << endl;
                    cout << 1 << " " << first0 + 1 << endl;
                    cout << 2 << " " << n - first0 << endl;
                    cout << 1 << " " << 2 << endl;
                } else {
                    cout << 2 << endl;
                    cout << n-1 << " " << n << endl;
                    cout << 1 << " " << n - 1 << endl;
                }
            } else {
                cout << 3 << endl;
                cout << 1 << " " << first0 + 1 << endl;
                cout << 2 << " " << n - first0 << endl;
                cout << 1 << " " << 2 << endl;
            }
        }
    }
    return 0;
}
