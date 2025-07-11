/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string defangIPaddr(string address)
    {
        string res;
        for (char c : address)
        {
            if (c == '.')
                res += "[.]";
            else
                res.push_back(c);
        }
        return res;
    }
};
// @lc code=end
