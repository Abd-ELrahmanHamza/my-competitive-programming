/*
 * @lc app=leetcode id=3567 lang=cpp
 *
 * [3567] Minimum Absolute Difference in Sliding Submatrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k)
    {
        vector<vector<int>> ans(grid.size() - k + 1, vector<int>(grid[0].size() - k + 1));
        for (int i = 0; i < grid.size() - k + 1; i++) {
            for (int j = 0; j < grid[0].size() - k + 1; j++) {
                vector<int> cur(k * k);
                for (int ii = 0; ii < k; ii++) {
                    for (int jj = 0; jj < k; jj++) {
                        cur[ii * k + jj] = grid[i + ii][j + jj];
                    }
                }
                sort(cur.begin(), cur.end());
                int m = INT_MAX;
                for (int ii = 1; ii < k * k; ii++) {
                    m = min(cur[ii] - cur[ii - 1] != 0 ? cur[ii] - cur[ii - 1] : INT_MAX, m);
                }
                ans[i][j] = m == INT_MAX ? 0 : m;
            }
        }
        return ans;
    }
};
// @lc code=end
