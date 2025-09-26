/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int idxMaxLimit = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin() - 1;
                int idxMinLimit = lower_bound(nums.begin(), nums.end(), max(nums[i] - nums[j], nums[j] - nums[i]) + 1) - nums.begin();
                idxMinLimit = max(idxMinLimit, j);
                int toAdd = idxMaxLimit - idxMinLimit + 1;
                if (i <= idxMaxLimit && i >= idxMinLimit)
                    toAdd--;
                if (j <= idxMaxLimit && j >= idxMinLimit)
                    toAdd--;
                if (toAdd > 0)
                    res += toAdd;
            }
        }
        return res;
    }
};
// @lc code=end
