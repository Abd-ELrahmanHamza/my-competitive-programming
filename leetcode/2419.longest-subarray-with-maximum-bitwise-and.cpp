/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int maxE = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxE = max(maxE, nums[i]);
        }
        int curCnt = 0, res = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxE) {
                curCnt++;
            } else {
                res = max(curCnt, res);
                curCnt = 0;
            }
        }
        res = max(curCnt, res);

        return res;
    }
};
// @lc code=end
