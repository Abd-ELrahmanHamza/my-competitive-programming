/*
 * @lc app=leetcode id=3047 lang=cpp
 *
 * [3047] Find the Largest Area of Square Inside Two Rectangles
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight)
    {
        long long ans = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long xl = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                long long yl = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                if (xl < 0 || yl < 0)
                    continue;
                ans = max(ans, min(xl, yl) * min(xl, yl));
            }
        }
        return ans;
    }
};
// @lc code=end
