/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string num)
    {
        int l = 0, r = 1;
        char res = -1;
        while (r < num.size()) {
            while (r < num.size() && num[r] == num[l]) {
                r++;
            }
            if (r - l >= 3) {
                res = max(res, num[l]);
            }
            l = r;
            r++;
        }
        if (res != -1) {
            return string({ res, res, res });
        }
        return "";
    }
};
// @lc code=end
