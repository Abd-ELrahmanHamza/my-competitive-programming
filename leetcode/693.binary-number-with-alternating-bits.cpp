/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        int prev = -1;
        while (n) {
            if ((n & 1) == prev)
                return false;
            prev = n & 1;
            n = n >> 1;
        }
        return true;
    }
};
// @lc code=end
