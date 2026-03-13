/*
 * @lc app=leetcode id=3296 lang=cpp
 *
 * [3296] Minimum Number of Seconds to Make Mountain Height Zero
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)
        {
            double f = a.first * a.second;
            double s = b.first * b.second;
            return f / a.first > s / b.first;
            // return f > s;
        }
    };
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (int x : workerTimes)
            pq.push({ 1, x });
        long long ans = 0;
        int i = mountainHeight;
        while (i > 0) {
            auto t = pq.top();
            pq.pop();
            pq.push({ t.first + 1, t.second });
            ans = max((((long long)t.first * (t.first + 1)) / 2) * t.second, ans);
            i -= t.first;
        }
        return ans;
    }
};
// @lc code=end
