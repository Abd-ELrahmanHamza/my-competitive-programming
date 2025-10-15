/*
 * @lc app=leetcode id=3350 lang=cpp
 *
 * [3350] Adjacent Increasing Subarrays Detection II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums)
    {
        vector<int> f(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                f[i] = f[i - 1] + 1;
            }
            if (i - f[i] >= 0 && f[i - f[i]] >= f[i])
                res = max(res, f[i]);
            if (i - f[i] / 2 >= 0 && f[i - f[i] / 2] * 2 >= f[i] + (f[i] % 2 != 0 ? 1 : 0))
                res = max(res, f[i - f[i] / 2] - (f[i] % 2 != 0 ? 1 : 0));
        }
        return res;
    }
};
// @lc code=end
