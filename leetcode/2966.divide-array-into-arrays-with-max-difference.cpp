/*
 * @lc app=leetcode id=2966 lang=cpp
 *
 * [2966] Divide Array Into Arrays With Max Difference
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(nums.size() / 3);
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i + 2] - nums[i] > k)
            {
                return vector<vector<int>>();
            }
            res[i / 3] = {nums[i], nums[i + 1], nums[i + 2]};
            i += 3;
        }
        return res;
    }
};
// @lc code=end
