/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int z1 = -2, z2 = -1;
        int res = 0;
        bool contains0 = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                z1 = z2;
                z2 = i;
                contains0 = true;
            } else {
                res = max(res, i - z1 - 1);
            }
        }
        return res - !contains0;
    }
};
// @lc code=end
