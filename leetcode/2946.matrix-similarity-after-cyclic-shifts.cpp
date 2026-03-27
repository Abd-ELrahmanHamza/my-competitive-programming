/*
 * @lc app=leetcode id=2946 lang=cpp
 *
 * [2946] Matrix Similarity After Cyclic Shifts
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k)
    {
        int rowSize = mat[0].size();
        vector<vector<int>> newMat(mat.size(), vector<int>(mat[0].size()));
        for (int i = 0; i < mat.size(); i += 2) {
            for (int j = 0; j < mat[0].size(); j++) {
                int newIdx = (((j - k) + rowSize) % rowSize + rowSize) % rowSize;
                newMat[i][newIdx] = mat[i][j];
            }
        }
        for (int i = 1; i < mat.size(); i += 2) {
            for (int j = 0; j < mat[0].size(); j++) {
                int newIdx = ((j + k) % rowSize + rowSize) % rowSize;
                newMat[i][newIdx] = mat[i][j];
            }
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (newMat[i][j] != mat[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
