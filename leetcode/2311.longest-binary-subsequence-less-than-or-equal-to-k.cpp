/*
 * @lc app=leetcode id=2311 lang=cpp
 *
 * [2311] Longest Binary Subsequence Less Than or Equal to K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int longestSubsequence(string s, int k)
    {
        int k1 = k, k2 = 0, i = 0;
        int cnt = 0;
        while (k1)
        {
            if (i >= s.size())
            {
                k2 = 0;
                break;
            }
            int idx = s.size() - i - 1;
            k2 = k2 | (s[idx] == '1' ? (1 << i) : 0);
            k1 = (k1 >> 1);
            i++;
        }
        for (int j = i; j < s.size(); j++)
        {
            if (s[s.size() - j - 1] == '1')
            {
                cnt++;
            }
        }
        cnt += (k2 > k);
        return s.size() - cnt;
    }
};
// @lc code=end
