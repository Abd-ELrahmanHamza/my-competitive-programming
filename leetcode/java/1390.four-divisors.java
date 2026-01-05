/*
 * @lc app=leetcode id=1390 lang=java
 *
 * [1390] Four Divisors
 */

// @lc code=start
class Solution {

    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            int divSum = nums[i] + 1, cnt = 2;
            for (int j = 2; j < Math.sqrt(nums[i]); j++) {
                if (nums[i] % j == 0) {
                    System.out.println("j " + j + " nums[i] / j " + nums[i] / j);
                    divSum += j;
                    divSum += nums[i] / j;
                    cnt += 2;
                }
            }
            if (nums[i] % Math.sqrt(nums[i]) == 0) {
                cnt++;
                divSum += Math.sqrt(nums[i]);
            }
            System.out.println("nums[i] " + nums[i]);
            System.out.println("divSum " + divSum);
            if (cnt == 4) {
                ans += divSum;
            }
        }
        return ans;
    }
}
// @lc code=end

