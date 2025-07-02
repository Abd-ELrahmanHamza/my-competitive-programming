/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxVowels(string s, int k)
    {
        vector<int> freq(26);
        for (int i = 0; i < k; i++)
        {
            freq[s[i] - 'a']++;
        }
        int res = freq['a' - 'a'] + freq['e' - 'a'] + freq['i' - 'a'] + freq['o' - 'a'] + freq['u' - 'a'];
        for (int i = k; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
            freq[s[i - k] - 'a']--;
            res = max(res, freq['a' - 'a'] + freq['e' - 'a'] + freq['i' - 'a'] + freq['o' - 'a'] + freq['u' - 'a']);
        }
        return res;
    }
};
// @lc code=end
