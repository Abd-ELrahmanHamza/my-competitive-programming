/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start)
    {
        int i = start, j = start;
        while (i < nums.size() || j >= 0) {
            if (i < nums.size() && nums[i] == target) {
                return i - start;
            }
            if (j >= 0 && nums[j] == target) {
                return start - j;
            }
            i++, j--;
        }
        return -1;
    }
};
// @lc code=end
