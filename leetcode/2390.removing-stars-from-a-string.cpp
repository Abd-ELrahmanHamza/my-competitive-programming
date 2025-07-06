/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string removeStars(string s)
    {
        int curStrCnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                s[i] = ' ';
                curStrCnt++;
            }
            else if (curStrCnt > 0)
            {
                curStrCnt--;
                s[i] = ' ';
            }
        }
        string res;
        for (char c : s)
        {
            if (c != ' ')
                res += c;
        }
        return res;
    }
};
// @lc code=end
