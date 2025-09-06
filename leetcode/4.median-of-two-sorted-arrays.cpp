/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<int> mergedNums(n + m);
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                mergedNums[k++] = nums1[i++];
            } else {
                mergedNums[k++] = nums2[j++];
            }
        }
        while (i < n) {
            mergedNums[k++] = nums1[i++];
        }
        while (j < m) {
            mergedNums[k++] = nums2[j++];
        }
        return mergedNums;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size() + nums2.size();
        auto mergedNums = merge(nums1, nums2);
        return (mergedNums[n / 2] + (n % 2 == 0 ? mergedNums[n / 2 - 1] : mergedNums[n / 2])) / 2.0;
    }
};
// @lc code=end
