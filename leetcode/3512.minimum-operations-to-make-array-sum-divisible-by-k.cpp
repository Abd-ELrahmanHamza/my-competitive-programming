/*
 * @lc app=leetcode id=3512 lang=cpp
 *
 * [3512] Minimum Operations to Make Array Sum Divisible by K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        int s = 0;
        for (int x : nums)
            s += x;
        return s % k;
    }
};
// @lc code=end
