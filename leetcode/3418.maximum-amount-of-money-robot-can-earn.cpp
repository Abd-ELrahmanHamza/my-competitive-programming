/*
 * @lc app=leetcode id=3418 lang=cpp
 *
 * [3418] Maximum Amount of Money Robot Can Earn
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins)
    {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(3, INT_MIN)));
        dp[n - 1][m - 1][0] = coins[n - 1][m - 1];
        dp[n - 1][m - 1][1] = coins[n - 1][m - 1] < 0 ? 0 : INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1)
                    continue;
                if (i + 1 < n) {
                    dp[i][j][0] = coins[i][j] + dp[i + 1][j][0];
                    if (coins[i][j] >= 0) {
                        dp[i][j][1] = coins[i][j] + dp[i + 1][j][1];
                        dp[i][j][2] = coins[i][j] + dp[i + 1][j][2];
                    } else {
                        dp[i][j][1] = max(dp[i + 1][j][0], coins[i][j] + dp[i + 1][j][1]);
                        dp[i][j][2] = max(dp[i + 1][j][1], coins[i][j] + dp[i + 1][j][2]);
                    }
                }
                if (j + 1 < m) {
                    dp[i][j][0] = max(dp[i][j][0], coins[i][j] + dp[i][j + 1][0]);

                    if (coins[i][j] >= 0) {
                        dp[i][j][1] = max(dp[i][j][1], coins[i][j] + dp[i][j + 1][1]);
                        dp[i][j][2] = max(dp[i][j][2], coins[i][j] + dp[i][j + 1][2]);
                    } else {
                        dp[i][j][1] = max(dp[i][j][1], max(dp[i][j + 1][0], coins[i][j] + dp[i][j + 1][1]));
                        dp[i][j][2] = max(dp[i][j][2], max(dp[i][j + 1][1], coins[i][j] + dp[i][j + 1][2]));
                    }
                }
            }
        }
        return max(dp[0][0][0], max(dp[0][0][1], dp[0][0][2]));
    }
};
// @lc code=end