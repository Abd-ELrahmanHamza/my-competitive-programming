/*
 * @lc app=leetcode id=744 lang=java
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {

    public char nextGreatestLetter(char[] letters, char target) {
        int l = -1, r = letters.length;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (letters[m] > target) {
                r = m;
            } else {
                l = m;
            }
        }
        return r == letters.length ? letters[0] : letters[r];
    }
}
// @lc code=end

