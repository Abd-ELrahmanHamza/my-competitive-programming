/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> w1(26), w2(26);
        set<char> ws1, ws2;
        for (char c : word1)
        {
            w1[c - 'a']++;
            ws1.insert(c);
        }
        for (char c : word2)
        {
            w2[c - 'a']++;
            ws2.insert(c);
        }
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        for (int i = 0; i < 26; i++)
        {
            if (w1[i] != w2[i])
                return false;
        }
        return true && ws1 == ws2;
    }
};
// @lc code=end
