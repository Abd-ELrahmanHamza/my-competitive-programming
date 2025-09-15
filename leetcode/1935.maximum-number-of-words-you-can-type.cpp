/*
 * @lc app=leetcode id=1935 lang=cpp
 *
 * [1935] Maximum Number of Words You Can Type
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        vector<bool> v(26, true);
        for (char c : brokenLetters)
            v[c - 'a'] = false;
        int n = text.size();
        int l = 0, r = 0, res = 0;
        while (r < n) {
            bool canBeTyped = true;
            while (r < n && text[r] != ' ') {
                canBeTyped = canBeTyped && v[text[r] - 'a'];
                r++;
            }
            if (canBeTyped) {
                res++;
            }
            r++;
            l = r;
        }
        return res;
    }
};
// @lc code=end
