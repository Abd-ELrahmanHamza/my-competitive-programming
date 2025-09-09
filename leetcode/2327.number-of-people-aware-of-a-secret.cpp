/*
 * @lc app=leetcode id=2327 lang=cpp
 *
 * [2327] Number of People Aware of a Secret
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        int res = 0, MOD = 1e9 + 7;
        vector<int> v(n);
        v[0] = 1;
        for (int i = 0; i < n; i++) {
            int start = min(n, i + delay), end = min(n, i + forget);
            for (int j = start; j < end; j++) {
                v[j] = (v[j] + v[i]) % MOD;
            }
        }
        for (int i = n - forget; i < n; i++) {
            res = (res + v[i]) % MOD;
        }
        return res;
    }
};
// @lc code=end
