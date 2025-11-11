/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1));
        for (string& s : strs) {
            int z = count(s.begin(), s.end(), '0');
            int o = s.size() - z;
            for (int i = m; i >= z; i--) {
                for (int j = n; j >= o; j--) {
                    memo[i][j] = max(memo[i][j], memo[i - z][j - o] + 1);
                }
            }
        }

        return memo[m][n];
    }
};
// @lc code=end
