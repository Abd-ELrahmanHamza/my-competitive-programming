/*
 * @lc app=leetcode id=3542 lang=cpp
 *
 * [3542] Minimum Operations to Convert All Elements to Zero
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        map<int, vector<int>> indices;
        set<int> zeros;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zeros.insert(i);
            else
                indices[nums[i]].push_back(i);
        }
        int res = 0;
        for (auto p : indices) {
            int maxG = -1;
            int maxCnt = 0;
            set<int> groupsKeys;
            for (int idx : p.second) {
                auto group = zeros.lower_bound(idx);
                int gkey = (group == zeros.end() ? -1 : *group);
                groupsKeys.insert(gkey);
                zeros.insert(idx);
            }
            res += groupsKeys.size();
        }
        return res;
    }
};
// @lc code=end
