/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> cnt(n);
        vector<long long> availableAt(n);
        int res = 0;
        sort(meetings.begin(), meetings.end());
        for (auto meeting : meetings)
        {
            long long minAvailableTime = LONG_LONG_MAX;
            int room = -1;
            for (int i = 0; i < n; i++)
            {
                if (availableAt[i] <= meeting[0])
                {
                    room = i;
                    break;
                }
                if (availableAt[i] < minAvailableTime)
                {
                    minAvailableTime = availableAt[i];
                    room = i;
                }
            }
            cout << "use room: " << room << " for meeting : " << meeting[0] << " " << meeting[1] << endl;
            cnt[room]++;
            availableAt[room] = max(availableAt[room], (long long)meeting[0]) + meeting[1] - meeting[0];
            if (cnt[res] < cnt[room])
                res = room;
            else if (cnt[res] == cnt[room])
                res = min(res, room);
        }
        return res;
    }
};
// @lc code=end
