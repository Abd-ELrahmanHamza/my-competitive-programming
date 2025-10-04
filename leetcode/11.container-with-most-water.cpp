/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            res = max(res, min(height[l], height[r]) * (r - l));
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return res;
    }
};
// @lc code=end
