/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid)
    {
        int s7 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int s8 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];

        set<int> s = { s7, s8 }, nums;
        for (int ii = 0; ii < 3; ii++) {
            int s1 = 0, s2 = 0;
            for (int jj = 0; jj < 3; jj++) {
                if (grid[ii + i][jj + j] > 9 || grid[ii + i][jj + j] <= 0)
                    return false;
                nums.insert(grid[ii + i][jj + j]);
                s1 += grid[ii + i][jj + j];
                s2 += grid[jj + i][ii + j];
            }
            s.insert(s1);
            s.insert(s2);
        }

        return s.size() == 1 && nums.size() == 9;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int ans = 0;
        for (int i = 2; i < grid.size(); i++) {
            for (int j = 2; j < grid[i].size(); j++) {
                ans += check(i - 2, j - 2, grid);
            }
        }
        return ans;
    }
};
// @lc code=end
