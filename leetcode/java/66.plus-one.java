/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {

    public int[] plusOne(int[] digits) {
        Boolean sameSize = false;
        for (int digit : digits) {
            if (digit < 9) {
                sameSize = true;
            }
        }
        int[] ans = new int[digits.length + (sameSize ? 0 : 1)];
        Boolean done = false;
        for (int i = digits.length - 1; i >= 0; i--) {
            ans[i] = digits[i];
            if (done) {
                continue;
            }
            if (ans[i] == 9) {
                ans[i] = 0;
            } else {
                ans[i]++;
                done = true;
            }
        }
        if (!sameSize) {
            ans[0] = 1;
        }
        return ans;

    }
}
// @lc code=end

