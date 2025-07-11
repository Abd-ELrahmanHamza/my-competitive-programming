/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> res(nums.size() * 2);
        for (int i = 0; i < nums.size(); i++)
        {
            res[i] = nums[i];
            res[i + nums.size()] = nums[i];
        }
        return res;
    }
};
// @lc code=end
