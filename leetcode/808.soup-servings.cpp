/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<double>> db;
    double solve(int a, int b)
    {
        if (a <= 0 && b <= 0) {
            return 0.5;
        } else if (a <= 0) {
            return 1;
        } else if (b <= 0) {
            return 0;
        }

        if (db[a][b] >= 0) {
            return db[a][b];
        }
        auto p1 = solve(a - 100, b);
        auto p2 = solve(a - 75, b - 25);
        auto p3 = solve(a - 50, b - 50);
        auto p4 = solve(a - 25, b - 75);
        return db[a][b] = (p1 + p2 + p3 + p4) / 4.0;
    }
    double soupServings(int n)
    {
        if(n>=5000)return 1;
        db = vector<vector<double>>(n + 1, vector<double>(n + 1, -1));
        auto res = solve(n, n);
        return res;
    }
};
// @lc code=end
