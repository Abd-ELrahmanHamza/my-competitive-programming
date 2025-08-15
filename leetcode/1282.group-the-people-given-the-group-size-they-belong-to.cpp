/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes)
    {
        int n = groupSizes.size();
        
        vector<pair<int, int>> gp(n);
        for (int i = 0; i < n; i++) {
            gp[i] = { groupSizes[i], i };
        }
        sort(gp.begin(), gp.end());
        vector<vector<int>> res;
        int l = 0, r = 1;
        while (r <= n) {
            vector<int> curV;
            curV.push_back(gp[l].second);
            while (r < n && gp[r].first == gp[l].first && curV.size() < gp[l].first) {
                curV.push_back(gp[r].second);
                r++;
            }
            res.push_back(curV);
            l = r;
            r++;
        }
        return res;
    }
};
// @lc code=end
