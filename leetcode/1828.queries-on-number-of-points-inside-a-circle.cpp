/*
 * @lc app=leetcode id=1828 lang=cpp
 *
 * [1828] Queries on Number of Points Inside a Circle
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                ans[i] += (points[j][0] - queries[i][0]) * (points[j][0] - queries[i][0]) + (points[j][1] - queries[i][1]) * (points[j][1] - queries[i][1]) <= queries[i][2] * queries[i][2];
            }
        }
        return ans;
    }
};
// @lc code=end
