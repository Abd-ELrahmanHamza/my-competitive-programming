/*
 * @lc app=leetcode id=3197 lang=cpp
 *
 * [3197] Find the Minimum Area to Cover All Ones II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minArea(vector<vector<int>>& grid, int startI, int endI, int startJ, int endJ)
    {
        long long minI = grid.size(), maxI = 0;
        long long minJ = grid[0].size(), maxJ = 0;
        bool found = false;
        for (long long i = startI; i <= endI; i++) {
            for (long long j = startJ; j <= endJ; j++) {
                if (grid[i][j]) {
                    found = true;
                    minI = min(i, minI);
                    maxI = max(i, maxI);
                    minJ = min(j, minJ);
                    maxJ = max(j, maxJ);
                }
            }
        }
        if (!found)
            return INT_MAX;
        return (maxI - minI + 1) * (maxJ - minJ + 1);
    }
    int minimumSum(vector<vector<int>>& grid)
    {
        long long n = grid.size(), m = grid[0].size(), res = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = min(res, minArea(grid, 0, i, 0, m - 1) + minArea(grid, i + 1, n - 1, 0, j) + minArea(grid, i + 1, n - 1, j + 1, m - 1));
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = min(res, minArea(grid, i + 1, n - 1, 0, m - 1) + minArea(grid, 0, i, 0, j) + minArea(grid, 0, i, j + 1, m - 1));
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                res = min(res, minArea(grid, 0, n - 1, 0, j) + minArea(grid, 0, i, j + 1, m - 1) + minArea(grid, i + 1, n - 1, j + 1, m - 1));
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                res = min(res, minArea(grid, 0, n - 1, j + 1, m - 1) + minArea(grid, 0, i, 0, j) + minArea(grid, i + 1, n - 1, 0, j));
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                res = min(res, minArea(grid, 0, n - 1, 0, i) + minArea(grid, 0, n - 1, i + 1, j) + minArea(grid, 0, n - 1, j + 1, m - 1));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = min(res, minArea(grid, 0, i, 0, m - 1) + minArea(grid, i + 1, j, 0, m - 1) + minArea(grid, j + 1, n - 1, 0, m - 1));
            }
        }
        return res;
    }
};
// @lc code=end
