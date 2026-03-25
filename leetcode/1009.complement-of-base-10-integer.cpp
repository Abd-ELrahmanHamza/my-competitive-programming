/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
            return 1;
        int numBits = log2(n) + 1;
        return (~n) & ((1 << numBits) - 1);
    }
};
// @lc code=end
