/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>& matrix)
    {
        int res = 0;
        for (int i = matrix.size() - 1; i >= 0; i--) {
            for (int j = matrix[0].size() - 1; j >= 0; j--) {
                if (i + 1 < matrix.size() && j + 1 < matrix[0].size() && matrix[i][j] && matrix[i + 1][j] && matrix[i][j + 1]) {
                    matrix[i][j] += min(matrix[i+1][j], min(matrix[i][j + 1], matrix[i + 1][j + 1]));
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
    int countSquares(vector<vector<int>>& matrix)
    {
        return solve(matrix);
    }
};
// @lc code=end
