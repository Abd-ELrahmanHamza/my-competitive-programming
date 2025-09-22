/*
 * @lc app=leetcode id=3005 lang=cpp
 *
 * [3005] Count Elements With Maximum Frequency
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        vector<int> freq(200);
        for (int& x : nums)
            freq[x]++;
        int maxFrq = INT_MIN;
        for (int& x : freq)
            maxFrq = max(maxFrq, x);
        int cnt = 0;
        for (int& x : freq)
            cnt += x == maxFrq;
        return cnt * maxFrq;
    }
};
// @lc code=end
