#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        string s;
        cin >> n >> m >> k >> s;
        s = "L" + s + "L";
        int lastC = -1;
        bool canSurvive = true;
        int c = 0;
        bool containsC = false;
        int w = 0, totalW = 0;

        for (int i = 0; i < n + 2; ++i) {
            if (s[i] == 'W') {
                c++;
            } else if (s[i] == 'C') {
                c++;
                containsC = true;
                lastC = i;
            } else {
                if (c >= m && containsC) {
                    if (c - (i - lastC - 1) >= m) {
                        canSurvive = false;
                        break;
                    } else {
                        totalW += c - m + 1;
                    }
                } else if (c >= m) {
                    totalW += c - m + 1;
                }
                c = 0;
                containsC = false;
                lastC = -1;
            }
        }
        if (totalW > k) {
            canSurvive = false;
        }
        cout << (canSurvive ? "YES\n" : "NO\n");
    }
    return 0;
}
