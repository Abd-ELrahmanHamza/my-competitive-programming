/*
 * @lc app=leetcode id=757 lang=cpp
 *
 * [757] Set Intersection Size At Least Two
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] < b[1])
                return true;
            if (b[1] < a[1])
                return false;
            return a[0] > b[0];
        });
        set<int> res;
        for (auto v : intervals) {
            auto f = lower_bound(res.begin(), res.end(), v[0]);
            auto l = upper_bound(res.begin(), res.end(), v[1]);
            int dist = distance(f, l);
            if (dist >= 2)
                continue;
            if (dist == 0) {
                res.insert(v[1]);
                res.insert(v[1] - 1);
            } else {
                if (*f == v[1]) {
                    res.insert(v[1] - 1);
                } else {
                    res.insert(v[1]);
                }
            }
        }

        return res.size();
    }
};
// @lc code=end