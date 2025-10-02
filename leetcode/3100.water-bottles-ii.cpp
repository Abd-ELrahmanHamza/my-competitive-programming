/*
 * @lc app=leetcode id=3100 lang=cpp
 *
 * [3100] Water Bottles II
 */

// @lc code=start
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int res = numBottles, rem = 0;
        while (numBottles >= numExchange) {
            int inc = 0;
            while (numBottles >= numExchange) {
                inc++;
                numBottles -= numExchange;
                numExchange++;
            }
            res += inc;
            numBottles += inc;
        }
        return res;
    }
};
// @lc code=end
