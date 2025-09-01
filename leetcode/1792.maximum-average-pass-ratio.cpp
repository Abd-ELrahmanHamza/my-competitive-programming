/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        int n = classes.size();
        priority_queue<pair<double, vector<int>>> q;
        for (int i = 0; i < n; i++) {
            double change = double(classes[i][0] + 1) / (classes[i][1] + 1) - double(classes[i][0]) / classes[i][1];
            q.push({ change, classes[i] });
        }
        for (int i = 0; i < extraStudents; i++) {
            auto t = q.top();
            q.pop();
            t.second[0]++;
            t.second[1]++;
            double change = double(t.second[0] + 1) / (t.second[1] + 1) - double(t.second[0]) / t.second[1];
            q.push({ change, { t.second[0], t.second[1] } });
        }
        double res = 0;
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            res += double(t.second[0]) / t.second[1];
        }
        return res / n;
    }
};
// @lc code=end
