/*
 * @lc app=leetcode id=2138 lang=cpp
 *
 * [2138] Divide a String Into Groups of Size k
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> res((int)ceil(s.size() / (double)k));
        for (int i = 0; i < (int)ceil(s.size() / (double)k); i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i * k + j < s.size())
                    res[i] += s[i * k + j];
                else
                    res[i] += fill;
            }
        }
        return res;
    }
};
// @lc code=end
