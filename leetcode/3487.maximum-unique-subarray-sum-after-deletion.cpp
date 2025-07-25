/*
 * @lc app=leetcode id=3487 lang=cpp
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxSum(vector<int> &nums)
    {
        set<int> s;
        int maxE = INT_MIN;
        bool added = false;
        for (int x : nums)
        {
            s.insert(x);
        }
        int res = 0;
        for (int x : s)
        {
            if (x >= 0)
            {
                res += x;
                added = true;
            }
            maxE = max(maxE, x);
        }
        if (added)
            return res;
        return maxE;
    }
};
// @lc code=end
