/*
 * @lc app=leetcode id=3379 lang=java
 *
 * [3379] Transformed Array
 */

// @lc code=start
class Solution {

    public int[] constructTransformedArray(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            ans[i] = nums[((i + nums[i]) % nums.length + nums.length) % nums.length];
        }
        return ans;
    }
}
// @lc code=end

