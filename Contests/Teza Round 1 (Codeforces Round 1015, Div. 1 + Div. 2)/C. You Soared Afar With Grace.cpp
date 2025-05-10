#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), invIdx(n + 1);
        for (int i = 0; i < n; i++)cin >> a[i];
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            invIdx[b[i]] = i;
        }
        bool valid = true;
        bool midTaken = false;
        vector<pair<int, int> > res;
        for (int i = 0; i < n / 2; i++) {
            int repNum = a[n - i - 1];
            int repBIdx = invIdx[repNum];
            if (repBIdx >= n - i - 1) {
                if (n % 2 != 0 && repBIdx == n - i - 1 && repBIdx > n / 2 && !midTaken
                ) {
                    midTaken = true;
                    swap(a[n / 2], a[n - i - 1]);
                    swap(b[n / 2], b[n - i - 1]);
                    swap(invIdx[b[n / 2]], invIdx[b[n - i - 1]]);
                    res.push_back({n / 2, n - i - 1});
                    i--;
                    continue;
                }
                valid = false;
                break;
            }
            if (b[i] == repNum)continue;
            swap(invIdx[b[i]], invIdx[b[repBIdx]]);
            swap(b[i], b[repBIdx]);
            swap(a[i], a[repBIdx]);

            res.push_back({i, repBIdx});
        }
        for (int i = 0; i < n; i++) {
            if (a[i] != b[n - i - 1]) {
                valid = false;
                break;
            }
        }
        if (n % 2 != 0) {
            if (a[n / 2] != b[n / 2])valid = false;
        }
        if (valid) {
            cout << res.size() << endl;
            for (auto p: res) {
                cout << p.first + 1 << " " << p.second + 1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
