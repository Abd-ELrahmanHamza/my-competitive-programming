/*
 * @lc app=leetcode id=3170 lang=cpp
 *
 * [3170] Lexicographically Minimum String After Removing Stars
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string clearStars(string s)
    {
        vector<stack<int>> vs(26);
        vector<int> rem;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (!vs[j].empty())
                    {
                        rem.push_back(vs[j].top());
                        vs[j].pop();
                        break;
                    }
                }
                rem.push_back(i);
            }
            else
            {
                vs[s[i] - 'a'].push(i);
            }
        }
        for (int i = 0; i < rem.size(); i++)
        {
            s[rem[i]] = -1;
        }
        string res;
        for (char c : s)
        {
            if (c != -1)
                res.push_back(c);
        }
        return res;
    }
};
// @lc code=end
