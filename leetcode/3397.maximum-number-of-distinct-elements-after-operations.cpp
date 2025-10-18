/*
 * @lc app=leetcode id=3397 lang=cpp
 *
 * [3397] Maximum Number of Distinct Elements After Operations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int minE = nums[0] - k, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (minE >= nums[i] - k && minE <= nums[i] + k) {
                res++;
                minE++;
            } else if (minE < nums[i] - k) {
                res++;
                minE = nums[i] - k + 1;
            }
        }
        return res;
    }
};

// @lc code=end
