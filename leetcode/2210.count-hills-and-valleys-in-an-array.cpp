/*
 * @lc app=leetcode id=2210 lang=cpp
 *
 * [2210] Count Hills and Valleys in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countHillValley(vector<int>& nums)
    {
        int i = 1;
        int res = 0;
        int lastNum = nums[0];
        while (i < nums.size()) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                    i++;
            }
            int nextNum = -1;
            if (i + 1 < nums.size())
                nextNum = nums[i + 1];
            if (nextNum == -1 || lastNum == -1) {
                lastNum = nums[i];
                i++;
                continue;
            }
            if (nums[i] > lastNum && nums[i] > nextNum || nums[i] < lastNum && nums[i] < nextNum)
                res++;
            if (i < nums.size())
                lastNum = nums[i];
            i++;
        }
        return res;
    }
};
// @lc code=end
