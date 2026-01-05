/*
 * @lc app=leetcode id=1975 lang=java
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
class Solution {

    public long maxMatrixSum(int[][] matrix) {
        long absSum = 0;
        int numNeg = 0, absMin = Integer.MAX_VALUE;
        for (int[] row : matrix) {
            for (int elem : row) {
                if (elem < 0) {
                    numNeg++;
                }
                absSum += Math.abs(elem);
                absMin = Math.min(absMin, Math.abs(elem));
            }
        }
        if (numNeg % 2 == 0) {
            return absSum;
        }
        return absSum - 2 * absMin;

    }
}
// @lc code=end

