/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

// @lc code=start'
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr)
    {
        unordered_set<int> res;
        unordered_set<int> cur;
        for (int x : arr) {
            unordered_set<int> newCur;
            for (int y : cur)
                newCur.insert(x | y);
            newCur.insert(x);
            res.insert(newCur.begin(), newCur.end());
            cur = newCur;
        }
        return res.size();
    }
};
// @lc code=end
