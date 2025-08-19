/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long res = 0;
        long long curCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                curCnt++;
            } else {
                res += (curCnt * (curCnt + 1)) / 2;
                curCnt = 0;
            }
        }

        res += (curCnt * (curCnt + 1)) / 2;
        return res;
    }
};
// @lc code=end
