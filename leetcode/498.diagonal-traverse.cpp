/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int curI = 0, curJ = 0, curS = 0, curDir = 0, resI = 0;
        int n = mat.size(), m = mat[0].size();
        vector<int> res(m * n);
        while (curS <= n + m - 2) {
            while (curI >= 0 && curI < n && curJ >= 0 && curJ < m) {
                res[resI++] = mat[curI][curJ];
                if (!curDir) {
                    curI--;
                    curJ++;
                } else {
                    curI++;
                    curJ--;
                }
            }
            if (!curDir) {
                curI++;
                curJ--;
            } else {
                curI--;
                curJ++;
            }

            if (curDir) {
                if (curI + 1 < n) {
                    curI++;
                } else {
                    curJ++;
                }
            } else {
                if (curJ + 1 < m) {
                    curJ++;
                } else {
                    curI++;
                }
            }
            curDir = !curDir;
            curS++;
        }
        return res;
    }
};
// @lc code=end
