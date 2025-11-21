/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int l = 0, r = s.size() - 1;
            while (l < s.size() && s[l] != c)
                l++;
            while (r >= 0 && s[r] != c)
                r--;
            vector<bool> cs(26);
            for (int i = l + 1; i < r; i++) {
                cs[s[i] - 'a'] = true;
            }
            for (int i = 0; i < 26; i++) {
                ans += cs[i];
            }
        }
        return ans;
    }
};
// @lc code=end
