/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double sideL(vector<int>& p1, vector<int>& p2)
    {
        return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]));
    }
    double largestTriangleArea(vector<vector<int>>& points)
    {
        double res = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    double a = sideL(points[i], points[j]);
                    double b = sideL(points[i], points[k]);
                    double c = sideL(points[j], points[k]);
                    double s = (a + b + c) / 2.0;
                    double area = sqrt(s * (s - a) * (s - b) * (s - c));
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};
// @lc code=end
