/*
 * @lc app=leetcode id=1594 lang=cpp
 *
 * [1594] Maximum Non Negative Product in a Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<pair<long long, long long>>> memo;
    pair<long long, long long> solve(vector<vector<int>>& grid, int i, int j)
    {
        if (memo[i][j].first != LONG_LONG_MIN)
            return memo[i][j];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return { grid[i][j], grid[i][j] };
        }
        long long resMin = LONG_LONG_MAX;
        long long resMax = LONG_LONG_MIN;
        if (i + 1 < grid.size()) {
            auto p = solve(grid, i + 1, j);
            long long t = grid[i][j] * p.first;
            long long t2 = grid[i][j] * p.second;
            resMin = min(t, t2);
            resMax = max(t, t2);
        }
        if (j + 1 < grid[0].size()) {
            auto p = solve(grid, i, j + 1);
            long long t = grid[i][j] * p.first;
            long long t2 = grid[i][j] * p.second;
            resMax = max(resMax, t);
            resMax = max(resMax, t2);
            resMin = min(resMin, t);
            resMin = min(resMin, t2);
        }
        return memo[i][j] = { resMax, resMin };
    }
    int maxProductPath(vector<vector<int>>& grid)
    {
        memo = vector<vector<pair<long long, long long>>>(grid.size(), vector<pair<long long, long long>>(grid[0].size(), { LONG_LONG_MIN, LONG_LONG_MAX }));
        int MOD = 1e9 + 7;
        auto res = solve(grid, 0, 0);
        return max(res.first >= 0 ? res.first % MOD : -1, res.second >= 0 ? res.second % MOD : -1);
    }
};
// @lc code=end
