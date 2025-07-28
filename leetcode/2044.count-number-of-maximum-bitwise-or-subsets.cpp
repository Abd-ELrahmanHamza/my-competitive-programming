/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int res = 0;
        int maxOr = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxOr |= nums[i];
        }
        for (int i = 0; i < (1 << nums.size()); i++) {
            int curOr = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    curOr |= nums[i];
                }
            }
            if (curOr == maxOr)
                res++;
        }
        return res;
    }
};
// @lc code=end
