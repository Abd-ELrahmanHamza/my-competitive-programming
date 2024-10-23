#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        long long start = 0, end = 1e5;
        while (start < end - 1) {
            long long n = start + (end - start) / 2;
            if (l + (n * (n + 1) / 2) <= r) {
                start = n;
            } else {
                end = n;
            }
        }
        cout << start + 1 << endl;
    }
    return 0;
}
