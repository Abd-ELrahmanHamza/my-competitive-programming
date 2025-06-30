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
        int firstIdx = -1, secondIdx = -1;
        queue<int> candidates;
        candidates.push(0);
        while (!candidates.empty())
        {
            int idx = candidates.front();
            candidates.pop();
            firstIdx = -1, secondIdx = -1;
            for (int i = idx; i < nums.size(); i++)
            {

                if (firstIdx == -1 || secondIdx == -1 && nums[firstIdx] > nums[i])
                {
                    firstIdx = i;
                }
                else if (secondIdx == -1 && nums[i] > nums[firstIdx] ||
                         secondIdx != -1 && nums[i] < nums[secondIdx] && nums[i] > nums[firstIdx])
                {
                    secondIdx = i;
                }
                else if (secondIdx != -1 && nums[i] > nums[secondIdx])
                {
                    return true;
                }
                else if (firstIdx != -1 && nums[firstIdx] > nums[i])
                {
                    candidates.push(i);
                }
            }
        }
        return false;
    }
};
// @lc code=end
