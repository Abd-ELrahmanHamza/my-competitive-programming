/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool increasingTriplet(vector<int> &nums)
    {
        int f = INT_MAX, s = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= f)
                f = nums[i];
            else if (nums[i] >= s)
                s = nums[i];
            else
                return true;
        }

        return false;
    }
};
// @lc code=end
