/*
 * @lc app=leetcode id=3446 lang=cpp
 *
 * [3446] Sort Matrix by Diagonals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        for (int i = 1; i <= n * 2 - 1; i++) {
            vector<int> v;
            for (int j = max(n - i, 0), k = max(-(n - i), 0); j <= n - 1 + min(n - i, 0); j++, k++) {
                v.push_back(grid[j][k]);
            }
            if (n - i < 0)
                sort(v.begin(), v.end());
            else
                sort(v.begin(), v.end(), greater<int>());
            int x = 0;
            for (int j = max(n - i, 0), k = max(-(n - i), 0); j <= n - 1 + min(n - i, 0); j++, k++) {
                grid[j][k] = v[x++];
            }
        }
        return grid;
    }
};
// @lc code=end
