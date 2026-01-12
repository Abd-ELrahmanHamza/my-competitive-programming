/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            int a = abs(points[i - 1][0] - points[i][0]);
            int b = abs(points[i - 1][1] - points[i][1]);
            res += max(a, b);
        }
        return res;
    }
};
// @lc code=end
