/*
 * @lc app=leetcode id=3315 lang=java
 *
 * [3315] Construct the Minimum Bitwise Array II
 */

// @lc code=start
import java.util.List;

class Solution {

    public int[] minBitwiseArray(List<Integer> nums) {
        int[] result = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            if (nums.get(i) == 2) {
                result[i] = -1;
            } else {
                int j = 0;
                while ((nums.get(i) & (1 << j)) != 0) {
                    j++;
                }
                result[i] = nums.get(i) ^ (1 << (j - 1));
            }
        }
        return result;
    }
}
// @lc code=end

