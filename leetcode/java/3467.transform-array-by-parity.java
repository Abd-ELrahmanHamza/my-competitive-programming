/*
 * @lc app=leetcode id=3467 lang=java
 *
 * [3467] Transform Array by Parity
 */

// @lc code=start
class Solution {

    public int[] transformArray(int[] nums) {
        int e = 0;
        for (int i : nums) {
            e += (i % 2 == 0) ? 1 : 0;
        }
        for (int i = 0; i < e; i++) {
            nums[i] = 0;
        }
        for (int i = e; i < nums.length; i++) {
            nums[i] = 1;
        }
        return nums;
    }
}
// @lc code=end

