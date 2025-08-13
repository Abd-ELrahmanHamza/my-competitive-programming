/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        vector<int> res(pref.size());
        res[0] = pref[0];
        for (int i = 1; i < pref.size(); i++) {
            res[i] = pref[i] ^ pref[i - 1];
        }
        return res;
    }
};
// @lc code=end
