/*
 * @lc app=leetcode id=1437 lang=cpp
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k)
    {
        int l = 0, r = 0;
        while (r < nums.size() && nums[r] != 1) {
            r++;
        }
        l = r;
        r++;
        while (r < nums.size()) {
            while (r < nums.size() && nums[r] != 1) {
                r++;
            }
            if (r < nums.size()) {
                if (r - l - 1 < k)
                    return false;
            }
            l = r;
            r++;
        }
        return true;
    }
};
// @lc code=end
