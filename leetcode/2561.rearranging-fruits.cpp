/*
 * @lc app=leetcode id=2561 lang=cpp
 *
 * [2561] Rearranging Fruits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2)
    {
        unordered_map<long long, long long> um1, um2;
        long long minOfTwo = LONG_LONG_MAX;

        for (long long x : basket1) {
            um1[x]++;
            minOfTwo = min(minOfTwo, x);
        }
        for (long long x : basket2) {
            um2[x]++;
            minOfTwo = min(minOfTwo, x);
        }
        priority_queue<pair<long long, long long>> pq1;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
            greater<pair<long long, long long>>>
            pq2;
        for (auto p : um1) {
            if (p.second > um2[p.first]) {
                p.second -= um2[p.first];
                if (p.second % 2 != 0) {
                    return -1;
                }
                pq1.push({ p.first, p.second / 2 });
                um2[p.first] = 0;
            } else if (p.second < um2[p.first]) {
                um2[p.first] -= p.second;
                if (um2[p.first] % 2 != 0) {
                    return -1;
                }

                pq2.push({ p.first, um2[p.first] / 2 });
                um2[p.first] = 0;
            }
        }

        for (auto p : um2) {
            if (p.second == 0)
                continue;
            if (p.second > um1[p.first]) {
                p.second -= um1[p.first];
                if (p.second % 2 != 0) {
                    return -1;
                }
                pq2.push({ p.first, p.second / 2 });
                um1[p.first] = 0;
            } else if (p.second < um1[p.first]) {
                um1[p.first] -= p.second;
                if (um1[p.first] % 2 != 0) {
                    return -1;
                }
                pq1.push({ p.first, um1[p.first] / 2 });
                um2[p.first] = 0;
            }
        }
        if (pq1.empty() && !pq2.empty() || !pq1.empty() && pq2.empty())
            return -1;
        if (pq1.empty() && pq2.empty())
            return 0;
        long long res = 0;
        auto top1 = pq1.top(), top2 = pq2.top();
        while (!pq1.empty() && !pq2.empty()) {

            if (top1.second > top2.second) {
                pq2.pop();
                if (top1.first == minOfTwo || top2.first == minOfTwo)
                    res += minOfTwo * top2.second;
                else {
                    res += min(minOfTwo * top2.second * 2, min(top1.first, top2.first) * top2.second);
                }
                top1.second -= top2.second;
                if (!pq2.empty())
                    top2 = pq2.top();
            } else if (top1.second < top2.second) {
                pq1.pop();
                if (top1.first == minOfTwo || top2.first == minOfTwo)
                    res += minOfTwo * top1.second;
                else {
                    res += min(minOfTwo * top1.second * 2, min(top1.first, top2.first) * top1.second);
                }
                top2.second -= top1.second;
                if (!pq1.empty())
                    top1 = pq1.top();
            } else {
                pq1.pop();
                pq2.pop();
                if (top1.first == minOfTwo || top2.first == minOfTwo)
                    res += minOfTwo * top1.second;
                else {
                    res += min(minOfTwo * top1.second * 2, min(top1.first, top2.first) * top1.second);
                }

                if (!pq2.empty() && !pq1.empty()) {
                    top2 = pq2.top();
                    top1 = pq1.top();
                }
            }
        }
        if (pq1.empty() && !pq2.empty() || !pq1.empty() && pq2.empty())
            return -1;
        return res;
    }
};
// @lc code=end
