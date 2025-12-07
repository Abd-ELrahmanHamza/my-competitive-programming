/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
    int countOdds(int low, int high)
    {
        if (low % 2 != 0 && high & 2 != 0) {
            if (low == high)
                return 1;
            return (high - low - 1) / 2 + 2;
        } else if (low % 2 == 0 && high % 2 == 0) {
            if (low == high)
                return 0;
            return ceil((high - low - 1) / 2.0);
        } else {
            return (high - low - 1) / 2 + 1;
        }
    }
};
// @lc code=end
