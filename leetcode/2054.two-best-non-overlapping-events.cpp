/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>>
            pq;
        sort(events.begin(), events.end(), [](auto& first, auto& second) {
            return first[0] < second[0];
        });
        int curMax = 0, ans = 0;
        for (int i = 0; i < events.size(); i++) {
            pq.push({ events[i][1], events[i][2] });
            int curEndMax = 0;
            while (!pq.empty() && pq.top().first < events[i][0]) {
                curEndMax = max(curEndMax, pq.top().second);
                pq.pop();
            }
            curMax = max(curMax, curEndMax);
            ans = max(ans, curMax + events[i][2]);
        }
        return ans;
    }
};
// @lc code=end
