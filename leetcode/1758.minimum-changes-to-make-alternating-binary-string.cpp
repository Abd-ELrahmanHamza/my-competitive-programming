/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s)
    {
        int c0 = 0, c1 = 0;
        char should0 = '0';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != should0)
                c0++;
            else
                c1++;
            should0 = '1' - should0 + '0';
        }
        return min(c0, c1);
    }
};
// @lc code=end
