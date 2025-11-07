/*
 * @lc app=leetcode id=2528 lang=cpp
 *
 * [2528] Maximize the Minimum Powered City
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k)
    {
        vector<pair<long long, long long>> events(stations.size());
        for (int i = 0; i < stations.size(); i++) {
            int start = max(0, i - r);
            int end = min((int)stations.size() - 1, i + r);
            events[start].first += stations[i];
            events[end].second += stations[i];
        }
        auto check = [&](long long mid) -> bool {
            auto tempEvents = events;
            int tempK = k;
            long long curSum = 0;

            for (int i = 0; i < stations.size(); i++) {
                curSum += tempEvents[i].first;

                if (curSum < mid) {

                    if (tempK - (mid - curSum) < 0)
                        return false;
                    tempK -= (mid - curSum);
                    tempEvents[min(i + 2 * r, (int)stations.size() - 1)].second += mid - curSum;
                    curSum = mid;
                }
                curSum -= tempEvents[i].second;
            }
            return true;
        };

        long long start = 0, end = accumulate(stations.begin(), stations.end(), 0LL) + k + 1;
        while (start < end - 1) {
            long long m = (end + start) / 2;
            bool c = check(m);
            if (c) {
                start = m;
            } else {
                end = m;
            }
        }

        return start;
    }
};
// @lc code=end
