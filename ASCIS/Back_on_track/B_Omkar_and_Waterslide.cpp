#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (ll &x: v)cin >> x;
        ll op = 0;
        for (int i = 0; i < n - 1; ++i) {
            v[i + 1] += op;
            if (v[i] > v[i+1]) {
                op += v[i] - v[i + 1];
                v[i + 1] = v[i];
            }
        }
        cout << op << endl;
    }
    return 0;
}
