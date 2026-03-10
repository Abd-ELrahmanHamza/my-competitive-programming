/*
 * @lc app=leetcode id=1888 lang=cpp
 *
 * [1888] Minimum Number of Flips to Make the Binary String Alternating
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s)
    {
        int ans = 0, n = s.size();
        int ops[] = { 0, 0 };
        for (int i = 0; i < n; i++) {
            ops[(s[i] & 1) ^ (i & 1)]++;
        }
        ans = min(ops[0], ops[1]);
        for (int i = 0; i < n; i++) {
            ops[(s[i] & 1) ^ (i & 1)]--;
            ops[(s[i] & 1) ^ ((n + i) & 1)]++;
            ans = min(ans, min(ops[0], ops[1]));
        }
        return ans;
    }
};
// @lc code=end
