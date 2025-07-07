/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxEvents(vector<vector<int>> &events)
    {
        int maxDay = 0;
        for (int i = 0; i < events.size(); i++)
        {
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<>> pq;

        sort(events.begin(), events.end());
        int cnt = 0;
        int j = 0;
        for (int curDay = 0; curDay <= maxDay; curDay++)
        {
            while (j < events.size() && events[j][0] <= curDay)
            {
                pq.push(events[j++][1]);
            }
            while (!pq.empty() && pq.top() < curDay)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end
