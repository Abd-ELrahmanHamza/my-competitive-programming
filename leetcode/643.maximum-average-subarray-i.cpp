/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        long long maxSum = 0;
        for (int i = 0; i < k; i++)
        {
            maxSum += nums[i];
        }
        long long curSum = maxSum;
        for (int i = k; i < nums.size(); i++)
        {
            curSum = curSum - nums[i - k] + nums[i];
            maxSum = max(curSum, maxSum);
        }
        return maxSum / double(k);
    }
};
// @lc code=end
