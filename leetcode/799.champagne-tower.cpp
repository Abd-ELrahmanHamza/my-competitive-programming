/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> v(100, vector<double>(100));
        v[0][0] = poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = 0; j <= min(i, query_glass); j++) {
                if (v[i - 1][j] > 1) {
                    v[i][j] = (v[i - 1][j] - 1) / 2;
                }
                if (j - 1 >= 0 && v[i - 1][j - 1] > 1) {
                    v[i][j] += (v[i - 1][j - 1] - 1) / 2;
                }
            }
        }
        return min(v[query_row][query_glass], 1.0);
    }
};
// @lc code=end
