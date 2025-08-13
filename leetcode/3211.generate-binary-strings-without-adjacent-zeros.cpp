/*
 * @lc app=leetcode id=3211 lang=cpp
 *
 * [3211] Generate Binary Strings Without Adjacent Zeros
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
    void solve(int n, string cur)
    {
        if (!n) {
            res.push_back(cur);
            return;
        }
        solve(n - 1, cur + "1");
        if (cur.empty() || cur.back() != '0') {
            solve(n - 1, cur + "0");
        }
    }
    vector<string> validStrings(int n)
    {
        solve(n, "");
        return res;
    }
};
// @lc code=end
