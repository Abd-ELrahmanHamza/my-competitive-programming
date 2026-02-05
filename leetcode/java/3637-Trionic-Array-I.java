
class Solution {

    public boolean isTrionic(int[] nums) {
        int i = 1;
        boolean cond1 = false, cond2 = false, cond3 = false;
        while (i < nums.length && nums[i] > nums[i - 1]) {
            i++;
            cond1 = true;
        }
        while (i < nums.length && nums[i] < nums[i - 1]) {
            i++;
            cond2 = true;
        }

        while (i < nums.length && nums[i] > nums[i - 1]) {
            i++;
            cond3 = true;
        }
        return cond1 && cond2 && cond3 && i == nums.length;
    }
}
