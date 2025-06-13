/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool check(vector<int> &nums, int p, int sol)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (abs(nums[i] - nums[i + 1]) <= sol)
            {
                i++;
                p--;
                if (p <= 0)
                    return true;
            }
        }
        return false;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        if (p == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int l = -1, r = 1e9 + 1;
        while (l < r - 1)
        {
            int m = l + (r - l) / 2;
            if (check(nums, p, m))
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return r;
    }
};
// @lc code=end
