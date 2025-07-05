/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int longestPalindrome(string s)
    {
        vector<int> freq(26), freqC(26);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < 'a')
            {
                freqC[s[i] - 'A']++;
            }
            else
            {
                freq[s[i] - 'a']++;
            }
        }
        int res = 0, hasOdd = false;
        for (int i = 0; i < 26; i++)
        {
            if (!(freq[i] & 1))
            {
                res += freq[i];
            }
            else
            {
                res += freq[i] - 1;
                hasOdd = true;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (!(freqC[i] & 1))
            {
                res += freqC[i];
            }
            else
            {
                res += freqC[i] - 1;
                hasOdd = true;
            }
        }
        return res + hasOdd;
    }
};
// @lc code=end
