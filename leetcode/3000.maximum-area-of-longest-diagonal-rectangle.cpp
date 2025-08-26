/*
 * @lc app=leetcode id=3000 lang=cpp
 *
 * [3000] Maximum Area of Longest Diagonal Rectangle
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions)
    {
        int maxArea = 0, maxDiag = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            int newDiag = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
            if (newDiag == maxDiag) {
                maxArea = max(maxArea, dimensions[i][0] * dimensions[i][1]);
            } else if (newDiag > maxDiag) {
                maxDiag = newDiag;
                maxArea = dimensions[i][0] * dimensions[i][1];
            }
        }
        return maxArea;
    }
};
// @lc code=end
