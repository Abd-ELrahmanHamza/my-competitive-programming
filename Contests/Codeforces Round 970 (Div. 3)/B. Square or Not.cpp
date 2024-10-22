#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int side = sqrt(n);
        if (side * side != n) {
            cout << "NO" << endl;
            continue;
        }
        if (side == 2) {
            cout << "YES" << endl;
            continue;
        }
        bool found = false;
        for (int i = 1; i < side - 1; i++) {
            for (int j = 1; j < side - 1; j++) {
                int index = i * side + j;
                if (s[index] != '0') {
                    found = true;
                    break;
                }
            }
            if (found)break;
        }
        if (found) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
