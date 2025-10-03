/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
            return 0;
        }

        vector<vector<int>> newHeightMap(heightMap);
        for (int i = 1; i < newHeightMap.size() - 1; i++) {
            for (int j = 1; j < newHeightMap[0].size() - 1; j++) {
                newHeightMap[i][j] = INT_MAX;
            }
        }
        queue<pair<int, int>> q;
        q.push({ 1, 1 });
        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            int newVal = min(newHeightMap[t.first - 1][t.second], min(newHeightMap[t.first][t.second - 1], min(newHeightMap[t.first + 1][t.second], newHeightMap[t.first][t.second + 1])));
            newVal = max(newVal, heightMap[t.first][t.second]);

            if (newHeightMap[t.first][t.second] > newVal) {
                newHeightMap[t.first][t.second] = newVal;
            } else {
                continue;
            }
            if (t.first + 1 < newHeightMap.size() - 1) {
                q.push({ t.first + 1, t.second });
            }
            if (t.second + 1 < newHeightMap[0].size() - 1) {
                q.push({ t.first, t.second + 1 });
            }
            if (t.first - 1 > 0) {
                q.push({ t.first - 1, t.second });
            }
            if (t.second - 1 > 0) {
                q.push({ t.first, t.second - 1 });
            }
        }
        int res = 0;
        for (int i = 1; i < newHeightMap.size() - 1; i++) {
            for (int j = 1; j < newHeightMap[0].size() - 1; j++) {
                res += newHeightMap[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
