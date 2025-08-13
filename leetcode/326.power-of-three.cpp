/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        int p = ceil(log(n) / log(3));

        return pow(3, p) == n;
    }
};
// @lc code=end
