#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<char> v(10);
        for (int i = 0; i < 10; i++) {
            char c;
            cin >> c;
            v[c - '0']++;
        }
        for (int i = 1; i <= 10; i++) {
            for (int j = 10 - i; j < 10; j++) {
                if (v[j]) {
                    cout << j;
                    v[j]--;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
