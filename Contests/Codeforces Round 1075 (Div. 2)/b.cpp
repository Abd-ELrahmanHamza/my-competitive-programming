#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        long long sum = 0, maxC = LONG_LONG_MIN;
        for (int i = 0; i < n; i++) {
            long long a, b, c;
            cin >> a >> b >> c;
            sum += (b - 1) * a;
            maxC = max(maxC, (long long)b * a - c);
        }
        if (sum >= x) {
            cout << 0 << endl;
        } else if (maxC <= 0) {
            cout << -1 << endl;
        } else {
            long long rem = x - sum;
            long long ans = (rem + maxC - 1) / maxC;
            cout << ans << endl;
        }
    }
    return 0;
}