/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) -> bool {
            int a1 = 0, b1 = 0;
            int ta = a, tb = b;
            while (ta) {
                a1 += ta & 1;
                ta = ta >> 1;
            }
            while (tb) {
                b1 += tb & 1;
                tb = tb >> 1;
            }
            if (a1 < b1)
                return true;
            if (a1 > b1)
                return false;
            return a < b;
        });
        return arr;
    }
};
// @lc code=end
