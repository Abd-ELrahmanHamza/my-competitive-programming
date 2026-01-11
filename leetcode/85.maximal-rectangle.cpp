/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        vector<vector<int>> hist(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        for (int i = 1; i <= matrix[0].size(); i++) {
            for (int j = 1; j <= matrix.size(); j++) {
                hist[j][i] = matrix[j - 1][i - 1] == '1' ? hist[j - 1][i] + 1: 0;
            }
        }

        int res = 0;
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                int minH = hist[i][j];
                for (int k = j; k >= 1; k--) {
                    if (hist[i][k] == 0)
                        break;
                    minH = min(minH, hist[i][k]);
                    res = max(res, minH * (j - k + 1));
                }
            }
        }
        return res;
    }
};
// @lc code=end
