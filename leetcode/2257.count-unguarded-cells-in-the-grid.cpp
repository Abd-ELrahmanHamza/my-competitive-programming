/*
 * @lc app=leetcode id=2257 lang=cpp
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        const int GUARD = 1, WALL = 2, GUARDED = 3;
        vector<vector<int>> occupied(m, vector<int>(n));
        for (auto p : walls) {
            occupied[p[0]][p[1]] = WALL;
        }

        for (auto p : guards) {
            occupied[p[0]][p[1]] = GUARD;
        }
        for (auto p : guards) {
            for (int i = p[0] - 1; i >= 0; i--) {
                if (occupied[i][p[1]] == WALL || occupied[i][p[1]] == GUARD) {
                    break;
                }
                occupied[i][p[1]] = GUARDED;
            }
            for (int i = p[0] + 1; i < m; i++) {
                if (occupied[i][p[1]] == WALL || occupied[i][p[1]] == GUARD) {
                    break;
                }
                occupied[i][p[1]] = GUARDED;
            }
            for (int i = p[1] - 1; i >= 0; i--) {
                if (occupied[p[0]][i] == WALL || occupied[p[0]][i] == GUARD) {
                    break;
                }
                occupied[p[0]][i] = GUARDED;
            }
            for (int i = p[1] + 1; i < n; i++) {
                if (occupied[p[0]][i] == WALL || occupied[p[0]][i] == GUARD) {
                    break;
                }
                occupied[p[0]][i] = GUARDED;
            }
        }
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (occupied[i][j] == 0)
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
