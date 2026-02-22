/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n)
    {
        int lastIdx = -1, res = 0, idx = 0;
        while (n) {
            if (n & 1) {
                if (lastIdx != -1) {
                    res = max(res, idx - lastIdx);
                }
                lastIdx = idx;
            }
            n = n >> 1;
            idx++;
        }
        return res;
    }
};
// @lc code=end
