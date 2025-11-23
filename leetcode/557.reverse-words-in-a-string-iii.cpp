/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s)
    {
        int l = 0, r = 0;
        while (r < s.size()) {
            while (r < s.size() && s[r] != ' ') {
                r++;
            }
            int tr = r;
            r--;
            while (l < r) {
                swap(s[l], s[r]);
                l++, r--;
            }
            tr++;
            r = tr;
            l = tr;
        }
        return s;
    }
};
// @lc code=end
