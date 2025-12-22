/*
 * @lc app=leetcode id=960 lang=cpp
 *
 * [960] Delete Columns to Make Sorted III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int n = strs.size(), m = strs[0].size(), res = 1;
        vector<int> dp(m, 1);
        for (int i = 1; i < m; i++) {
            int maxVal = 0;
            for (int j = 0; j < i; j++) {
                bool isBigger = true;
                for (int k = 0; k < n; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        isBigger = false;
                        break;
                    }
                }
                if (isBigger) {
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i] = 1 + maxVal;
            res = max(res, dp[i]);
        }
        return m - res;
    }
};
// @lc code=end
