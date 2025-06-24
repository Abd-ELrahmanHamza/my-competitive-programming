/*
 * @lc app=leetcode id=2200 lang=cpp
 *
 * [2200] Find All K-Distant Indices in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<bool> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                for (int j = max(0, i - k); j <= min(i + k, (int)nums.size());
                     j++) {
                    res[j] = true;
                }
            }
        }
        vector<int> res2;
        for (int i = 0; i < nums.size(); i++) {
            if (res[i]) {
                res2.push_back(i);
            }
        }

        return res2;
    }
};
// @lc code=end
