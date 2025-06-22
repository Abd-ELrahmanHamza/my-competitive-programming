/*
 * @lc app=leetcode id=2395 lang=cpp
 *
 * [2395] Find Subarrays With Equal Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool findSubarrays(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            freq[nums[i] + nums[i + 1]]++;
            if (freq[nums[i] + nums[i + 1]] > 1)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
