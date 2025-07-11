/*
 * @lc app=leetcode id=2942 lang=cpp
 *
 * [2942] Find Words Containing Character
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> res;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].find(x) != std::string::npos)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
