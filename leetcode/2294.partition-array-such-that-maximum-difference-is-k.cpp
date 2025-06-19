/*
 * @lc app=leetcode id=2294 lang=cpp
 *
 * [2294] Partition Array Such That Maximum Difference Is K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        int l = 0, r = 0;
        while (r < nums.size())
        {
            while (r < nums.size() && nums[r] - nums[l] <= k)
            {
                r++;
            }
            res++;
            r++;
            l = r;
        }
        return res;
    }
};
// @lc code=end
