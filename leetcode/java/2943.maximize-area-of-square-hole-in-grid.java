
import java.util.Arrays;

/*
 * @lc app=leetcode id=2943 lang=java
 *
 * [2943] Maximize Area of Square Hole in Grid
 */
// @lc code=start
class Solution {

    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        int h = 1, v = 1, maxH = 1, maxV = 1;
        Arrays.sort(hBars);
        Arrays.sort(vBars);
        for (int i = 1; i < hBars.length; i++) {
            if (hBars[i - 1] + 1 == hBars[i]) {
                h++;
            } else {
                maxH = Math.max(maxH, h);
                h = 1;
            }
        }
        maxH = Math.max(maxH, h);

        for (int i = 1; i < vBars.length; i++) {
            if (vBars[i - 1] + 1 == vBars[i]) {
                v++;
            } else {
                maxV = Math.max(maxV, v);
                v = 1;
            }
        }
        maxV = Math.max(maxV, v);

        return (Math.min(maxV, maxH) + 1) * (Math.min(maxV, maxH) + 1);
    }
}
// @lc code=end

