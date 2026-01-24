/*
 * @lc app=leetcode id=1877 lang=java
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
import java.util.Arrays;

class Solution {

    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int l = 0, r = nums.length - 1;
        int ans = 0;
        while (l < r) {
            ans = Math.max(ans, nums[r] + nums[l]);
            r--;
            l++;
        }
        return ans;
    }

}
// @lc code=end

