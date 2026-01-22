/*
 * @lc app=leetcode id=3507 lang=java
 *
 * [3507] Minimum Pair Removal to Sort Array I
 */

// @lc code=start
class Solution {

    public int minimumPairRemoval(int[] nums) {

        for (int i = 0; i < nums.length - 1; i++) {
            int curSize = nums.length - i;
            boolean isSorted = true;
            for (int j = 1; j < curSize; j++) {
                if (nums[j] < nums[j - 1]) {
                    isSorted = false;
                }
            }
            if (isSorted) {
                return i;
            }
            int idx = 1;
            for (int j = 2; j < curSize; j++) {
                if (nums[j] + nums[j - 1] < nums[idx] + nums[idx - 1]) {
                    idx = j;
                }
            }
            nums[idx - 1] += nums[idx];
            for (int j = idx; j < curSize - 1; j++) {
                nums[j] = nums[j + 1];
            }
        }
        return nums.length - 1;
    }
}
// @lc code=end

