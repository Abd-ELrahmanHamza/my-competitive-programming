/*
 * @lc app=leetcode id=3440 lang=cpp
 *
 * [3440] Reschedule Meetings for Maximum Free Time II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        map<int, int> spaces;
        for (int i = 0; i < startTime.size(); i++)
        {
            int s = 0, e = eventTime;
            if (i != 0)
                s = endTime[i - 1];
            if (i != startTime.size() - 1)
                e = startTime[i + 1];
            if (s != startTime[i])
            {
                spaces[startTime[i] - s]++;
            }
            if (e != endTime[i] && i == startTime.size() - 1)
            {
                spaces[e - endTime[i]]++;
            }
        }
        if (!spaces.empty())
        {
            auto it = spaces.end();
            --it; 

            while (it != spaces.begin())
            {
                auto p = prev(it);
                p->second += it->second;
                --it;
            }
        }

        int res = 0;
        for (int i = 0; i < startTime.size(); i++)
        {
            int s = 0, e = eventTime;
            if (i != 0)
                s = endTime[i - 1];
            if (i != startTime.size() - 1)
                e = startTime[i + 1];
            int span = endTime[i] - startTime[i];
            auto it = spaces.lower_bound(span);
            int count = it->second;
            if (count - (e - endTime[i] >= span) - (startTime[i] - s >= span) > 0)
            {
                res = max(res, e - s);
            }
            else
            {
                res = max(res, e - s - span);
            }
        }
        return res;
    }
};
// @lc code=end
