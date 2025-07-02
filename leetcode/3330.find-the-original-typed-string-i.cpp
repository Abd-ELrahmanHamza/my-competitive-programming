/*
 * @lc app=leetcode id=3330 lang=cpp
 *
 * [3330] Find the Original Typed String I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int possibleStringCount(string word)
    {
        int res = 1, curCnt = 1;
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
            {
                curCnt++;
            }
            else
            {
                res += curCnt - 1;
                curCnt = 1;
            }
        }
        res += curCnt - 1;
        return res;
    }
};
// @lc code=end
