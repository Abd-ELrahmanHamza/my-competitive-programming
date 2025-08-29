#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0) {
            return 1;
        }
        vector<double> dp(n + 1);
        dp[0] = 1;
        double s = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = s / maxPts;
            if (i < k) {
                s += dp[i];
            }
            if (i - maxPts >= 0 && i - maxPts < k) {
                s -= dp[i - maxPts];
            }
        }
        double res = accumulate(dp.begin() + k, dp.end(), 0.0);
        return res;
    }
};
