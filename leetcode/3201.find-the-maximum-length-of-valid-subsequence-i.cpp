/*
 * @lc app=leetcode id=3201 lang=cpp
 *
 * [3201] Find the Maximum Length of Valid Subsequence I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maximumLength(vector<int> &nums)
    {
        int cntO = nums[0] % 2 != 0, cntE = nums[0] % 2 == 0, cntTog = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                cntE++;
            }
            else
            {
                cntO++;
            }
            if (nums[i] % 2 != nums[i - 1] % 2)
            {
                cntTog++;
            }
        }
        return max(cntO, max(cntE, cntTog));
    }
};
// @lc code=end
