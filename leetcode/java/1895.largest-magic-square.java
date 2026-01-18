/*
 * @lc app=leetcode id=1895 lang=java
 *
 * [1895] Largest Magic Square
 */

// @lc code=start
import java.util.HashSet;
import java.util.Set;

class Solution {

    private boolean check(int[][] grid, int ii, int jj, int side) {
        Set<Integer> sums = new HashSet<>();
        for (int i = ii; i < ii + side; i++) {
            int s = 0;
            for (int j = jj; j < jj + side; j++) {
                s += grid[i][j];
            }
            sums.add(s);
        }
        for (int j = jj; j < jj + side; j++) {
            int s = 0;
            for (int i = ii; i < ii + side; i++) {
                s += grid[i][j];
            }

            sums.add(s);
        }
        int s = 0;
        for (int k = 0; k < side; k++) {
            s += grid[ii + k][jj + k];
        }

        sums.add(s);
        s = 0;
        for (int k = 0; k < side; k++) {
            s += grid[ii + k][jj + (side - k - 1)];
        }
        sums.add(s);

        return sums.size() == 1;
    }

    public int largestMagicSquare(int[][] grid) {
        int ans = 1;
        for (int side = 2; side <= Math.min(grid.length, grid[0].length); side++) {
            for (int i = 0; i < grid.length - side + 1; i++) {
                for (int j = 0; j < grid[0].length - side + 1; j++) {
                    if (check(grid, i, j, side)) {
                        ans = Math.max(ans, side);
                    }
                }
            }
        }
        return ans;
    }
}
// @lc code=end

