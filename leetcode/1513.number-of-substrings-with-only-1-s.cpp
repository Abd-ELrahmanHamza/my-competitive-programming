/*
 * @lc app=leetcode id=1513 lang=cpp
 *
 * [1513] Number of Substrings With Only 1s
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSub(string s)
    {
        int l = 0, r = 0;
        long long res = 0;
        const int mod = 1e9 + 7;
        while (r < s.size()) {
            while (r < s.size() && s[r] == '1') {
                r++;
            }
            long long curCnt = r - l;
            res = (res % mod + ((curCnt * (curCnt + 1)) / 2) % mod) % mod;

            while (r < s.size() && s[r] == '0') {
                r++;
            }
            l = r;
        }
        return res;
    }
};
// @lc code=end
