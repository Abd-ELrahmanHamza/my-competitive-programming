/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int findLHS(vector<int> &nums)
    {
        map<int, int> freq;
        for (int x : nums)
        {
            freq[x]++;
        }
        int res = 0;
        auto it = freq.begin();
        for (; it != freq.end(); ++it)
        {
            auto pIt = prev(it);
            if (it->first == pIt->first - 1)
            {
                res = max(res, it->second + pIt->second);
            }
        }

        return res;
    }
};
// @lc code=end
