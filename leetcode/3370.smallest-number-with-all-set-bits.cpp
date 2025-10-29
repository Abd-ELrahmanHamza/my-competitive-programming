/*
 * @lc app=leetcode id=3370 lang=cpp
 *
 * [3370] Smallest Number With All Set Bits
 */

// @lc code=start
class Solution {
public:
    int smallestNumber(int n)
    {
        char numBits = 0;
        while (n) {
            numBits++;
            n = n >> 1;
        }
        return (1 << (numBits)) - 1;
    }
};
// @lc code=end
