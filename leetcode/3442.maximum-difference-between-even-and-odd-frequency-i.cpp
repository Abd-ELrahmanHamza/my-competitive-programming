/*
 * @lc app=leetcode id=3442 lang=cpp
 *
 * [3442] Maximum Difference Between Even and Odd Frequency I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxDifference(string s)
    {
        vector<int> freq(26);
        int maxO = 0, minE = INT_MAX;
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] & 1)
                maxO = max(maxO, freq[i]);
            else if (freq[i] != 0)
                minE = min(minE, freq[i]);
        }

        return maxO - minE;
    }
};
// @lc code=end
