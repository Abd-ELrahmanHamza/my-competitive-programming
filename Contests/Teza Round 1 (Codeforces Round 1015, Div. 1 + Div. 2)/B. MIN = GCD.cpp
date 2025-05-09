#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v(n);
        int minEIdx = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] < v[minEIdx]) {
                minEIdx = i;
            }
        }
        long long curGCD = -1;
        for (int i = 0; i < n; i++) {
            if (i == minEIdx)continue;
            if (v[i] % v[minEIdx] == 0) {
                if (curGCD == -1) {
                    curGCD = v[i];
                } else {
                    curGCD = __gcd(curGCD, v[i]);
                }
            }
        }
        cout << (curGCD == v[minEIdx] ? "YES" : "NO") << endl;
    }
    return 0;
}
