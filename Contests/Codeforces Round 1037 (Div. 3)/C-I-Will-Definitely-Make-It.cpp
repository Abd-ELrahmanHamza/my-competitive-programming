#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        unsigned int k, n;
        cin >> n >> k;
        vector<int> v(n);
        for (int& x : v)
            cin >> x;
        int cur = v[k - 1];
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (cur == v[i]) {
                k = i;
            }
        }
        bool res = true;
        int water = 0;
        for (unsigned int i = k; i < n - 1; i++) {
            if (v[i + 1] - v[i] > v[i] - water) {
                res = false;
            }
            water += v[i + 1] - v[i];
        }
        cout << (res ? "YES\n" : "NO\n");
    }
    return 0;
}