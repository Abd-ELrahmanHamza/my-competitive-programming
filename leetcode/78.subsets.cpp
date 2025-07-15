/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> res;
    void solve(vector<int> curSet, int idx, vector<int> &nums)
    {
        if (idx >= nums.size())
        {
            res.push_back(curSet);
            return;
        }
        solve(curSet, idx + 1, nums);
        curSet.push_back(nums[idx]);
        solve(curSet, idx + 1, nums);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        solve(vector<int>(), 0, nums);
        return res;
    }
};
// @lc code=end
