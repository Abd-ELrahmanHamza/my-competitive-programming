#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int r = -1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[0]) {
                r = i;
                break;
            }
        }
        if (r == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            swap(s[0], s[r]);
            cout << s << endl;
        }
    }
    return 0;
}
