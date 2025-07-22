/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int l = 0, r = 0;
        int res = 0, curSum = 0;
        while (r < nums.size())
        {
            while (r < nums.size())
            {
                int curNum = nums[r];
                freq[curNum]++;
                if (freq[curNum] > 1)
                {
                    break;
                }
                curSum += curNum;
                r++;
            }
            res = max(res, curSum);
            while (l < nums.size())
            {
                int curNum = nums[l];
                l++;
                freq[curNum]--;
                curSum -= curNum;
                if (freq[curNum] == 1)
                {
                    freq[curNum] = 0;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
