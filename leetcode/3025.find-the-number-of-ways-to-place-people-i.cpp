/*
 * @lc app=leetcode id=3025 lang=cpp
 *
 * [3025] Find the Number of Ways to Place People I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2)
    {
        if (v1[0] < v2[0])
            return true;
        if (v1[0] > v2[0])
            return false;
        return v1[1] > v2[1];
    }
    int numberOfPairs(vector<vector<int>>& points)
    {
        int n = points.size(), res = 0;
        sort(points.begin(), points.end(), comp);
        for (int i = 0; i < n; i++) {
            int minY = 100, minX = 100;
            for (int j = i - 1; j >= 0; j--) {
                if (points[j][1] >= points[i][1] && points[j][1] < minY && points[j][0] < minX) {
                    res++;
                }
                if (points[j][1] >= points[i][1]) {
                    minY = min(minY, points[j][1]);
                    minX = min(minX, points[j][0]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
