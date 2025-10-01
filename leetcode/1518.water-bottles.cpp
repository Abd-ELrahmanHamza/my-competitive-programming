/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int res = numBottles, rem = 0;
        while (numBottles >= numExchange) {
            rem = numBottles % numExchange;
            numBottles /= numExchange;
            res += numBottles;
            numBottles += rem;
        }
        return res;
    }
};
// @lc code=end
