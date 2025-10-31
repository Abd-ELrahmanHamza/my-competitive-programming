/*
 * @lc app=leetcode id=3289 lang=cpp
 *
 * [3289] The Two Sneaky Numbers of Digitville
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
    {
        vector<int> res(2);
        int idx = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                res[idx++] = nums[i];
        }
        return res;
    }
};
// @lc code=end
