/*
 * @lc app=leetcode id=67 lang=java
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {

    public String addBinary(String a, String b) {
        String res = "";
        int i = b.length() - 1, j = a.length() - 1;
        int rem = 0;
        while (i >= 0 && j >= 0) {
            if (a.charAt(j) == '1' && b.charAt(i) == '1' && rem == 1) {
                res = "1" + res;
                rem = 1;
            } else if (a.charAt(j) == '1' && b.charAt(i) == '1') {
                res = "0" + res;
                rem = 1;
            } else if ((a.charAt(j) == '1' || b.charAt(i) == '1') && rem == 1) {
                res = "0" + res;
                rem = 1;
            } else if (a.charAt(j) == '1' || b.charAt(i) == '1' || rem == 1) {
                res = "1" + res;
                rem = 0;
            } else {
                res = "0" + res;
                rem = 0;
            }
            i--;
            j--;
        }
        while (i >= 0) {
            if (b.charAt(i) == '1' && rem == 1) {
                res = "0" + res;
                rem = 1;
            } else if (b.charAt(i) == '1' || rem == 1) {
                res = "1" + res;
                rem = 0;
            } else {
                res = "0" + res;
                rem = 0;
            }
            i--;
        }
        while (j >= 0) {
            if (a.charAt(j) == '1' && rem == 1) {
                res = "0" + res;
                rem = 1;
            } else if (a.charAt(j) == '1' || rem == 1) {
                res = "1" + res;
                rem = 0;
            } else {
                res = "0" + res;
                rem = 0;
            }
            j--;
        }
        if (rem == 1) {
            res = "1" + res;
        }
        return res;
    }
}
// @lc code=end
