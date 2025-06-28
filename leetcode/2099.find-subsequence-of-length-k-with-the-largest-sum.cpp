/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<pair<int, int>> numsPairs(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            numsPairs[i].first = nums[i];
            numsPairs[i].second = i;
        }
        sort(numsPairs.begin(), numsPairs.end(), greater<pair<int, int>>());
        vector<pair<int, int>> res(k);
        for (int i = 0; i < k; i++)
        {
            res[i].first = numsPairs[i].second;
            res[i].second = numsPairs[i].first;
        }
        sort(res.begin(), res.end());
        vector<int> resV(k);
        for (int i = 0; i < k; i++)
        {
            resV[i] = res[i].second;
        }

        return resV;
    }
};
// @lc code=end
