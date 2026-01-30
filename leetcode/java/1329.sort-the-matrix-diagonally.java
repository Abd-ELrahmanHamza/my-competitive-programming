/*
 * @lc app=leetcode id=1329 lang=java
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {

    private void sortDiagonal(int[][] mat, int startI, int startJ) {
        List<Integer> arr = new ArrayList<>();
        int i = startI, j = startJ;
        while (i < mat.length && j < mat[0].length) {
            arr.add(mat[i++][j++]);
        }
        Collections.sort(arr);
        i = startI;
        j = startJ;
        int k = 0;
        while (i < mat.length && j < mat[0].length) {
            mat[i++][j++] = arr.get(k++);
        }
    }

    public int[][] diagonalSort(int[][] mat) {
        for (int i = 0; i < mat.length; i++) {
            sortDiagonal(mat, i, 0);
        }
        for (int i = 1; i < mat[0].length; i++) {
            sortDiagonal(mat, 0, i);
        }
        return mat;
    }
}
// @lc code=end

