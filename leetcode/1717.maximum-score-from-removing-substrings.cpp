/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void remBA(set<int> &as, set<int> &bs, int &res, int score)
    {
        auto bIdxIt = bs.begin();
        while (bIdxIt != bs.end())
        {
            auto aIdxIt = as.lower_bound(*bIdxIt);
            if (aIdxIt != as.end())
            {
                res += score;
                auto tempBIdxIt = bIdxIt;

                as.erase(aIdxIt);
                bs.erase(tempBIdxIt);
            }
            bIdxIt++;
        }
    }
    void remAB(set<int> &as, set<int> &bs, int &res, int score)
    {
        auto aIdxIt = as.begin();
        while (aIdxIt != as.end())
        {
            auto bIdxIt = bs.lower_bound(*aIdxIt);
            if (bIdxIt != bs.end())
            {
                res += score;
                auto tempAIdxIt = aIdxIt;
                bs.erase(bIdxIt);
                as.erase(tempAIdxIt);
            }
            aIdxIt++;
        }
    }
    int maximumGain(string s, int x, int y)
    {
        int res = 0;
        set<int> bs, as;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
                as.insert(i);
            else if (s[i] == 'b')
                bs.insert(i);
            else
            {
                if (y >= x)
                {
                    remBA(as, bs, res, y);
                    remAB(as, bs, res, x);
                }
                else
                {
                    remAB(as, bs, res, x);
                    remBA(as, bs, res, y);
                }
                as = set<int>();
                bs = set<int>();
            }
        }
        if (y >= x)
        {
            remBA(as, bs, res, y);
            remAB(as, bs, res, x);
        }
        else
        {
            remAB(as, bs, res, x);
            remBA(as, bs, res, y);
        }
        return res;
    }
};
// @lc code=end
