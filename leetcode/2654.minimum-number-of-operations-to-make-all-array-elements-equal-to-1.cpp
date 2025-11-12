/*
 * @lc app=leetcode id=2654 lang=cpp
 *
 * [2654] Minimum Number of Operations to Make All Array Elements Equal to 1
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int smallestLen = INT_MAX;
        int numOnes = 0;

        for (int i = 0; i < nums.size(); i++) {
            int gcd = nums[i];
            if (nums[i] == 1)
                numOnes++;
            for (int j = i + 1; j < nums.size(); j++) {
                gcd = __gcd(gcd, nums[j]);
                if (gcd == 1) {
                    smallestLen = min(smallestLen, j - i + 1);
                }
            }
        }
        if (smallestLen == INT_MAX)
            return -1;
        return smallestLen + (nums.size() - numOnes) - 2;
    }
};
// @lc code=end
