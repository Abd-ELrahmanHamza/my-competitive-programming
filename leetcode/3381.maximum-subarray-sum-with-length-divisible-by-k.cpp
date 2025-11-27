/*
 * @lc app=leetcode id=3381 lang=cpp
 *
 * [3381] Maximum Subarray Sum With Length Divisible by K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k)
    {
        vector<long long> presum(nums.size());
        vector<long long> maxKSum(nums.size());
        presum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            presum[i] = presum[i - 1] + nums[i];
        }
        long long maxRes = LONG_LONG_MIN;
        for (int i = k-1; i < nums.size(); i++) {
            maxKSum[i] = presum[i] - (i - k >= 0 ? presum[i - k] : 0LL);
            maxKSum[i] = max(maxKSum[i], maxKSum[i] + (i - k >= 0 ? maxKSum[i - k] : 0LL));
            maxRes = max(maxRes, maxKSum[i]);
        }
        return maxRes;
    }
};
// @lc code=end
