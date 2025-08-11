/*
 * @lc app=leetcode id=2438 lang=cpp
 *
 * [2438] Range Product Queries of Powers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pow2(int n)
    {
        int res = 1;
        int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            res = (res * 2) % MOD;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries)
    {
        vector<int> powers(50);
        int i = 0, idx = 0;
        while (n) {
            if (n & 1) {
                powers[idx++] = i;
            }
            i++;
            n = (n >> 1);
        }
        for (int i = 1; i < 50; i++)
            powers[i] = powers[i - 1] + powers[i];
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int preSum = powers[queries[i][1]] - (queries[i][0] - 1 >= 0 ? powers[queries[i][0] - 1] : 0);
            ans[i] = pow2(preSum);
        }
        return ans;
    }
};
// @lc code=end
