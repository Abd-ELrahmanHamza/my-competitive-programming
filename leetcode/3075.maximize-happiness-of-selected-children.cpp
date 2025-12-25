/*
 * @lc app=leetcode id=3075 lang=cpp
 *
 * [3075] Maximize Happiness of Selected Children
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        long long res = 0, it = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i = 0; i < k; i++) {
            res += max(0LL,happiness[i] - (it++));
        }
        return res;
    }
};
// @lc code=end
