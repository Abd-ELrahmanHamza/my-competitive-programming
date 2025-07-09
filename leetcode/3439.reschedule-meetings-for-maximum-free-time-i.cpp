/*
 * @lc app=leetcode id=3439 lang=cpp
 *
 * [3439] Reschedule Meetings for Maximum Free Time I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int l = 0, r = 0, sub = 0, res = 0;
        while (r < startTime.size())
        {
            while (r < startTime.size() && r - l < k)
            {
                sub += endTime[r] - startTime[r];
                r++;
            }
            int s = 0, e = eventTime;
            if (l > 0)
                s = endTime[l - 1];
            if (r <= startTime.size() - 1)
                e = startTime[r];
            res = max(res, e - s - sub);
            sub -= endTime[l] - startTime[l];
            l++;
        }
        return res;
    }
};
// @lc code=end
