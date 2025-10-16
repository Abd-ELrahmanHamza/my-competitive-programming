/*
 * @lc app=leetcode id=2598 lang=cpp
 *
 * [2598] Smallest Missing Non-negative Integer After Operations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value)
    {
        vector<int> v(value);
        for (int i = 0; i < nums.size(); i++) {
            v[((nums[i] % value) + value) % value]++;
        }
        int minE = INT_MAX, minI = -1;
        for (int i = 0; i < value; i++) {
            if (v[i] < minE) {
                minE = v[i];
                minI = i;
            }
        }
        return minI + minE * value;
    }
};
// @lc code=end
