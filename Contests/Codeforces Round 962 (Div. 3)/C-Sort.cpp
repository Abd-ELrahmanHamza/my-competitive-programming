#include <bits/stdc++.h>

using namespace std;

int sumInRange(vector<int> &v, int l, int r) {
    return v[r] - v[l - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        vector<vector<int>> aPrefix(26, vector<int>(a.size() + 1));
        vector<vector<int>> bPrefix(26, vector<int>(b.size() + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (a[i - 1] - 'a' == j) {
                    aPrefix[j][i] = aPrefix[j][i - 1] + 1;
                } else {
                    aPrefix[j][i] = aPrefix[j][i - 1];
                }
                if (b[i - 1] - 'a' == j) {
                    bPrefix[j][i] = bPrefix[j][i - 1] + 1;
                } else {
                    bPrefix[j][i] = bPrefix[j][i - 1];
                }
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            int sumDiff = 0;
            for (int j = 0; j < 26; ++j) {
                int aChar = sumInRange(aPrefix[j], l, r);
                int bChar = sumInRange(bPrefix[j], l, r);
                sumDiff += abs(aChar - bChar);
            }
            cout << sumDiff / 2 << endl;
        }
    }
    return 0;
}