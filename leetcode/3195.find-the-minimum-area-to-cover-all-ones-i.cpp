/*
 * @lc app=leetcode id=3195 lang=cpp
 *
 * [3195] Find the Minimum Area to Cover All Ones I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid)
    {
        int minX = grid.size(), maxX = 0, minY = grid[0].size(), maxY = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};
// @lc code=end
