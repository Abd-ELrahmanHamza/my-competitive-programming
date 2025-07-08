/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int k = 0; k < grid.size(); k++)
            {
                bool res = true;
                for (int j = 0; j < grid.size(); j++)
                {
                    if (grid[i][j] != grid[j][k])
                    {
                        res = false;
                        break;
                    }
                }
                cnt += res;
            }
        }
        return cnt;
    }
};
// @lc code=end
