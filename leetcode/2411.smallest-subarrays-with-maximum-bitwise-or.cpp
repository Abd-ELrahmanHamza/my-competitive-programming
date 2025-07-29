/*
 * @lc app=leetcode id=2411 lang=cpp
 *
 * [2411] Smallest Subarrays With Maximum Bitwise OR
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums)
    {
        vector<int> bits(50);
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int j = 0;
            while (nums[i]) {
                bits[j] = nums[i] & 1 ? i : bits[j];
                nums[i] = nums[i] >> 1;
                j++;
            }
            int maxDist = 0;
            for (int k = 0; k < 50; k++) {
                maxDist = max(maxDist, bits[k]);
            }

            res[i] = max(maxDist - i + 1, 1);
        }
        return res;
    }
};
// @lc code=end
