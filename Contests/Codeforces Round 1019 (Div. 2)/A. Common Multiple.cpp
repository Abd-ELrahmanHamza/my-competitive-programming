#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> v(200);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (v[x] == 0) {
                res++;
                v[x] = true;
            }
        }
        cout << res << endl;
    }
    return 0;
}
