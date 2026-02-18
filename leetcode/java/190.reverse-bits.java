/*
 * @lc app=leetcode id=190 lang=java
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {

    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res = res | (((n & (1 << i)) >> i) << (31 - i));
        }
        return res;
    }
}
// @lc code=end

