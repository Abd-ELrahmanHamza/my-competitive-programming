/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> memo;
    int nextIdx(vector<vector<int>> &events, int val)
    {
        int l = 0, r = events.size();
        while (l < r - 1)
        {
            int m = l + (r - l) / 2;
            if (events[m][0] <= val)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return r;
    }
    int solve(vector<vector<int>> &events, int idx, int k)
    {
        if (idx >= events.size())
        {
            return 0;
        }
        if (k == 0)
        {
            return 0;
        }
        if (memo[k][idx] != -1)
            return memo[k][idx];
        int curIdx = nextIdx(events, events[idx][1]);
        int without = solve(events, idx + 1, k);
        int with = solve(events, curIdx, k - 1) + events[idx][2];
        return memo[k][idx] = max(with, without);
    }
    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end());
        memo = vector<vector<int>>(k + 1, vector<int>(events.size(), -1));
        return solve(events, 0, k);
    }
};
// @lc code=end
