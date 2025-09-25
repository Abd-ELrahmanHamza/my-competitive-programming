/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int x = INT_MAX, y = INT_MAX;
                if (j - 1 >= 0)
                    x = triangle[i - 1][j - 1];
                if (j < triangle[i - 1].size())
                    y = triangle[i - 1][j];
                triangle[i][j] += min(x, y);
            }
        }
        int res = INT_MAX;
        for (int x : triangle.back()) {
            res = min(x, res);
        }
        return res;
    }
};
// @lc code=end
