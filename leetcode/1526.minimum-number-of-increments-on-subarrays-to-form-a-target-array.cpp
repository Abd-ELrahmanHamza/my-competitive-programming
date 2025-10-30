/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minNumberOperations(vector<int>& target)
    {
        int res = target[0];
        for (int i = 1; i < target.size(); i++) {
            res += max(target[i] - target[i - 1], 0);
        }
        return res;
    }
};
// @lc code=end
