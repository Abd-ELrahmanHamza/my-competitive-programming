/*
 * @lc app=leetcode id=3212 lang=cpp
 *
 * [3212] Count Submatrices With Equal Frequency of X and Y
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid)
    {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> freqX(n, vector<int>(m)), freqY(n, vector<int>(m));
        for (int i = 0; i < freqX.size(); i++) {
            for (int j = 0; j < freqX[0].size(); j++) {
                if (i - 1 >= 0) {
                    freqX[i][j] += freqX[i - 1][j];
                }
                if (j - 1 >= 0) {
                    freqX[i][j] += freqX[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    freqX[i][j] -= freqX[i - 1][j - 1];
                }
                freqX[i][j] += grid[i][j] == 'X';
            }
        }
        for (int i = 0; i < freqY.size(); i++) {
            for (int j = 0; j < freqY[0].size(); j++) {
                if (i - 1 >= 0) {
                    freqY[i][j] += freqY[i - 1][j];
                }
                if (j - 1 >= 0) {
                    freqY[i][j] += freqY[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    freqY[i][j] -= freqY[i - 1][j - 1];
                }
                freqY[i][j] += grid[i][j] == 'Y';
            }
        }
        for (int i = 0; i < freqY.size(); i++) {
            for (int j = 0; j < freqY[0].size(); j++) {
                if (freqX[i][j] == freqY[i][j] && freqX[i][j] > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
