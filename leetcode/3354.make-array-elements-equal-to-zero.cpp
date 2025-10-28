/*
 * @lc app=leetcode id=3354 lang=cpp
 *
 * [3354] Make Array Elements Equal to Zero
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(int idx, int dir, vector<int>& nums)
    {
        nums[idx]++;
        while (idx >= 0 && idx < nums.size()) {
            if (nums[idx] > 0) {
                nums[idx]--;
                dir = dir == -1 ? 1 : -1;
            }
            idx += dir;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                vector<int> nums1(nums.begin(), nums.end());
                vector<int> nums2(nums.begin(), nums.end());
                res += isValid(i, 1, nums1);
                res += isValid(i, -1, nums2);
            }
        }
        return res;
    }
};
// @lc code=end
