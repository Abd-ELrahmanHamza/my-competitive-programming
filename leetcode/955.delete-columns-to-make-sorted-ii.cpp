/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int ans = 0;
        vector<bool> isGreater(strs.size());
        for (int i = 0; i < strs[0].size(); i++) {
            vector<bool> newIsGreater(strs.size());
            bool isValid = true;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] < strs[j - 1][i] && !isGreater[j - 1]) {
                    ans++;
                    isValid = false;
                    break;
                }
                if (strs[j][i] > strs[j - 1][i]) {
                    newIsGreater[j - 1] = true;
                }
            }
            if (isValid)
                for (int i = 0; i < strs.size(); i++) {
                    isGreater[i] = isGreater[i] || newIsGreater[i];
                }
        }
        return ans;
    }
};
// @lc code=end
