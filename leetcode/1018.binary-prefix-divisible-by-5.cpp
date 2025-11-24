/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums)
    {
        int x = 0;
        vector<bool> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            x = (x << 1) | nums[i];
            res[i] = x % 5 == 0;
            x = x%5;
        }
        return res;
    }
};
// @lc code=end
