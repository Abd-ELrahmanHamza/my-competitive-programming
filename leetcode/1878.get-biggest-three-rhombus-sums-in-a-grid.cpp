/*
 * @lc app=leetcode id=1878 lang=cpp
 *
 * [1878] Get Biggest Three Rhombus Sums in a Grid
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkLimits(int l, int r, int t, int b, int n, int m)
    {
        return l >= 0 && r >= 0 && t >= 0 && b >= 0 && l < n && r < n && t < m && b < m;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        set<int, greater<int>> sums;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sums.insert(grid[i][j]);
            }
        }

        for (int s = 2; s <= min(m, n); s++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int l = i - (s - 1);
                    int r = i + (s - 1);
                    int t = j - (s - 1);
                    int b = j + (s - 1);
                    if (!checkLimits(l, r, t, b, n, m)) {
                        continue;
                    }
                    int sum = 0;
                    for (int k = 0; k <= s - 2; k++) {
                        sum += grid[i - k][j - (s - 1) + k] + grid[i - k][j + (s - 1) - k];
                    }
                    for (int k = 1; k <= s - 2; k++) {
                        sum += grid[i + k][j - (s - 1) + k] + grid[i + k][j + (s - 1) - k];
                    }
                    sum += grid[i - (s - 1)][j] + grid[i + (s - 1)][j];

                    sums.insert(sum);
                }
            }
        }
        vector<int> res;
        int i = 0;
        for (auto x : sums) {
            res.push_back(x);
            i++;
            if (i == 3)
                break;
        }
        return res;
    }
};
// @lc code=end
