/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2)
    {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            auto search_end = nums2.begin() + i;

            auto it = upper_bound(nums2.begin() + i, nums2.end(), nums1[i], greater<int>());
            if (it != nums2.begin() + i) {
                auto furthest_valid_it = it - 1;
                int j = distance(nums2.begin(), furthest_valid_it);
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};
// @lc code=end
