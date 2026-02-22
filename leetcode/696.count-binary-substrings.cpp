/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s)
    {
        int l = 0, r = 1;
        int res = 0;
        while (r < s.size()) {
            while (r < s.size() && s[r] == s[l]) {
                r++;
            }
            int cntf = r - l;
            l = r;
            r++;
            while (r < s.size() && s[r] == s[l]) {
                r++;
            }
            int cnts = l >= s.size() ? 0 : r - l;

            res += min(cntf, cnts);
        }
        return res;
    }
};
// @lc code=end
