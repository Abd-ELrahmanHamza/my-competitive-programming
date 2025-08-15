/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        return pow(4, ceil(log(n) / log(4))) == n;
    }
};
// @lc code=end
