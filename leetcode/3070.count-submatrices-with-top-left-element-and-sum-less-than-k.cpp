/*
 * @lc app=leetcode id=3070 lang=cpp
 *
 * [3070] Count Submatrices with Top-Left Element and Sum Less Than k
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int t = 0;
                if (i - 1 >= 0) {
                    t += grid[i - 1][j];
                }
                if (j - 1 >= 0) {
                    t += grid[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    t -= grid[i - 1][j - 1];
                }
                grid[i][j] += t;
                if (grid[i][j] <= k)
                    res++;
            }
        }
        return res;
    }
};
// @lc code=end
