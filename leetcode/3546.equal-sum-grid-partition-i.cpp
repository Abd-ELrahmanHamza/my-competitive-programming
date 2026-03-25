/*
 * @lc app=leetcode id=3546 lang=cpp
 *
 * [3546] Equal Sum Grid Partition I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        vector<long long> rows(grid.size()), cols(grid[0].size());
        long long rs = 0, cs = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                rows[i] += grid[i][j];
            }
            rs += rows[i];
        }
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                cols[i] += grid[j][i];
            }
            cs += cols[i];
        }
        long long curs = 0;
        for (int i = 0; i < grid.size(); i++) {
            curs += rows[i];
            if (2 * curs == rs) {
                return true;
            }
        }
        curs = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            curs += cols[i];
            if (2 * curs == cs) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
