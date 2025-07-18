/*
 * @lc app=leetcode id=2163 lang=cpp
 *
 * [2163] Minimum Difference in Sums After Removal of Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        long long leftS = 0, rightS = 0;
        int n = nums.size() / 3;
        for (int i = 0; i < n; i++) {
            left.push(nums[i]);
            leftS += nums[i];
        }
        for (int i = 2 * n; i < nums.size(); i++) {
            right.push(nums[i]);
            rightS += nums[i];
        }
        vector<long long> leftSums(n + 1), rightSums(n + 1);
        leftSums[0] = leftS, rightSums[n] = rightS;
        for (int i = n; i < 2 * n; i++) {
            left.push(nums[i]);
            leftS += nums[i];
            leftS -= left.top();
            left.pop();
            leftSums[i + 1 - n] = leftS;
        }
        for (int i = 2 * n - 1; i >= n; i--) {
            right.push(nums[i]);
            rightS += nums[i];
            rightS -= right.top();
            right.pop();
            rightSums[i - n] = rightS;
        }
        long long res = leftSums[0] - rightSums[0];
        for (int i = 0; i <= n; i++) {
            res = min(res, leftSums[i] - rightSums[i]);
        }
        return res;
    }
};
// @lc code=end
