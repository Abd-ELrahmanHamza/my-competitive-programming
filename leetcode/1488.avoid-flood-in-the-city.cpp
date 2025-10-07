/*
 * @lc app=leetcode id=1488 lang=cpp
 *
 * [1488] Avoid Flood in The City
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        unordered_map<int, bool> lacks;
        vector<int> ans(rains.size());
        set<int> toEmptyIndices;
        unordered_map<int, int> lastSeen;
        int numEmpty = rains.size();
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                numEmpty++;
                toEmptyIndices.insert(i);
            } else {
                ans[i] = -1;
                if (numEmpty == 0)
                    return {};
                if (lacks[rains[i]]) {
                    if (toEmptyIndices.empty())
                        return {};
                    auto idxIT = toEmptyIndices.upper_bound(lastSeen[rains[i]]);
                    if (idxIT == toEmptyIndices.end())
                        return {};
                    ans[*idxIT] = rains[i];
                    toEmptyIndices.erase(idxIT);
                    numEmpty++;
                }
                lacks[rains[i]] = true;
                lastSeen[rains[i]] = i;
                numEmpty--;
            }
        }
        for (int x : toEmptyIndices) {
            ans[x] = 1;
        }
        return ans;
    }
};
// @lc code=end