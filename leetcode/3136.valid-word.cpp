/*
 * @lc app=leetcode id=3136 lang=cpp
 *
 * [3136] Valid Word
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool isValid(string word)
    {
        bool vowel = false, consonant = false;
        for (char c : word)
        {
            if (isalnum(c))
            {
                if (isalpha(tolower(c)))
                {
                    if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' ||
                        tolower(c) == 'u')
                        vowel = true;
                    else
                        consonant = true;
                }
            }
            else
            {
                return false;
            }
        }
        return vowel && consonant && word.size() >= 3;
    }
};
// @lc code=end
