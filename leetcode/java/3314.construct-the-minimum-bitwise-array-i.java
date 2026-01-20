
import java.util.List;

/*
 * @lc app=leetcode id=3314 lang=java
 *
 * [3314] Construct the Minimum Bitwise Array I
 */
// @lc code=start
class Solution {

    public int[] minBitwiseArray(List<Integer> nums) {
        int[] result = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            result[i] = -1;
            for (int j = 0; j < nums.get(i); j++) {
                if ((j | (j + 1)) == nums.get(i)) {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
}
// @lc code=end

