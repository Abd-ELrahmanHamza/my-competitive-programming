#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            cnt0 += (c == '0');
        }
        int cnt1 = n-cnt0;
        cout << (cnt0 * (cnt1 + 1)) + (cnt1 * max(cnt1 - 1, 0)) << endl;
    }

    return 0;
}
