/*
 * @lc app=leetcode id=3190 lang=cpp
 *
 * [3190] Find Minimum Operations to Make All Elements Divisible by Three
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int ans = 0;
        for (int& x : nums) {
            ans += x % 3 != 0;
        }
        return ans;
    }
};
// @lc code=end
