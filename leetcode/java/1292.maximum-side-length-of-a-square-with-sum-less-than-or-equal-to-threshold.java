/*
 * @lc app=leetcode id=1292 lang=java
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 */

// @lc code=start
class Solution {

    public int maxSideLength(int[][] mat, int threshold) {
        for (int[] mat1 : mat) {
            for (int j = 1; j < mat[0].length; j++) {
                mat1[j] += mat1[j - 1];
            }
        }
        for (int i = 0; i < mat[0].length; i++) {
            for (int j = 1; j < mat.length; j++) {
                mat[j][i] += mat[j - 1][i];
            }
        }

        int ans = 0;
        for (int side = 0; side <= Math.min(mat.length, mat[0].length); side++) {
            for (int i = 0; i < mat.length; i++) {
                for (int j = 0; j < mat[0].length; j++) {

                    if (i + side >= mat.length || j + side >= mat[0].length) {
                        continue;
                    }
                    int add1 = (i - 1 < 0 || j - 1 < 0) ? 0 : mat[i - 1][j - 1];
                    int sub1 = i - 1 < 0 ? 0 : mat[i - 1][j + side];
                    int sub2 = j - 1 < 0 ? 0 : mat[i + side][j - 1];
                    if (mat[i + side][j + side] + add1 - sub1 - sub2 <= threshold) {
                        ans = Math.max(ans, side + 1);
                    }
                }
            }
        }

        return ans;
    }
}
// @lc code=end

