/*
 * @lc app=leetcode id=1611 lang=cpp
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
 */

// @lc code=start
class Solution {
public:
    int minimumOneBitOperations(int n)
    {
        int decimal = 0;
        while (n) {
            decimal = decimal ^ n;
            n = (n >> 1);
        }
        return decimal;
    }
};
// @lc code=end
