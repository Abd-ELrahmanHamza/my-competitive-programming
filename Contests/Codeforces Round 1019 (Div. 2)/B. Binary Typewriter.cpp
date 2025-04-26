#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char cur = '0';
        int trans = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (cur != s[i]) {
                trans++;
                cur = s[i];
            }
        }
        int l = 0, r = 0;
        while (l < n && s[l] != '0')l++;
        r = l;
        int sub = 0;
        while (r < n) {
            while (r < n && s[r] == '0') {
                r++;
            }
            // cout << l << " " << r << endl;
            if (l > 0 && r <= n - 1) {
                sub = 2;
                break;
            }
            if (l > 0 && r <= n) {
                sub = 1;
            }
            while (r < n && s[r] != '0')r++;
            l = r;
        }
        cout << trans + n - sub << endl;
    }
    return 0;
}
