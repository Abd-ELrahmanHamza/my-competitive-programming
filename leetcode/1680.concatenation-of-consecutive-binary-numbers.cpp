/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int concatenatedBinary(int n)
    {
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            res = (res << int(floor(log2(i)) + 1)) | (i);
            res = res % int(1e9 + 7);
        }
        return res;
    }
};
// @lc code=end
