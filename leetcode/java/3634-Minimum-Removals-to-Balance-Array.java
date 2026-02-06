
import java.util.Arrays;

class Solution {

    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, r = 0, ans = Integer.MAX_VALUE;
        while (r < nums.length) {
            while (r < nums.length && (long) nums[r] <= (long) k * (long) nums[l]) {
                r++;
            }
            ans = Math.min(ans, nums.length - (r - l));
            l++;
        }
        return ans;
    }
}
