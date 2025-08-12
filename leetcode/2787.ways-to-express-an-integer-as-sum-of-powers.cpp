/*
 * @lc app=leetcode id=2787 lang=cpp
 *
 * [2787] Ways to Express an Integer as Sum of Powers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[0][i] = 1;
        long long MOD = 1e9 + 7;
        for (int p = 1; p <= n; p++) {
            long long temp = pow(p, x);
            for (int cap = 1; cap <= n; cap++) {
                if (cap >= temp) {
                    dp[cap][p] =
                        (dp[cap - pow(p, x)][p - 1] + dp[cap][p - 1]) % MOD;
                } else {
                    dp[cap][p] = dp[cap][p - 1];
                }
            }
        }
        return dp[n][n];
    }
};
// @lc code=end
