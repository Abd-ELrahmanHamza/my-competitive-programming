/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        priority_queue<int, vector<int>, greater<>> empty_rooms;
        vector<int> cnts(n);
        sort(meetings.begin(), meetings.end());
        int ans = 0;
        long long curTime = 0;
        for (int i = 0; i < n; i++) {
            empty_rooms.push(i);
        }
        for (int i = 0; i < meetings.size(); i++) {

            curTime = max(curTime, (long long)meetings[i][0]);

            while (!pq.empty() && pq.top().first <= curTime) {
                empty_rooms.push(pq.top().second);
                pq.pop();
            }
            if (empty_rooms.empty()) {
                curTime = pq.top().first;
            }
            while (!pq.empty() && pq.top().first <= curTime) {
                empty_rooms.push(pq.top().second);
                pq.pop();
            }
            int room = empty_rooms.top();
            empty_rooms.pop();

            pq.push({ curTime + meetings[i][1] - meetings[i][0], room });
            cnts[room]++;
            if (cnts[room] > cnts[ans]) {
                ans = room;
            } else if (cnts[room] == cnts[ans]) {
                ans = min(ans, room);
            }
        }
        return ans;
    }
};
// @lc code=end
