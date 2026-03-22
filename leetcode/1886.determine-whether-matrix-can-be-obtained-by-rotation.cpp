/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct PairHash {
    size_t operator()(const pair<int, int>& p) const noexcept
    {
        return (static_cast<size_t>(p.first) << 32) ^ static_cast<size_t>(p.second);
    }
};
class Solution {
public:
    pair<int, int> getIdx(int i, int j, int n, int rot)
    {
        if (rot == 0) {
            return { i, j };
        } else if (rot == 1) {
            return { n - 1 - j, i };
        } else if (rot == 2) {
            return { n - 1 - i, n - 1 - j };
        } else {
            return { j, n - 1 - i };
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        int n = mat.size();
        map<pair<int, int>, pair<int, int>> um;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2 + (n % 2 != 0); j++) {
                um[getIdx(i, j, n, 3)] = getIdx(i, j, n, 0);
                for (int rot = 1; rot < 4; rot++) {
                    um[getIdx(i, j, n, rot - 1)] = getIdx(i, j, n, rot);
                }

            }
        }
        if (n % 2 != 0) {
            um[{ n / 2, n / 2 }] = { n / 2, n / 2 };
        }
        for (int rot = 0; rot <= 3; rot++) {
            bool res = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    pair<int, int> cur = { i, j };
                    for (int r = 0; r < rot; r++) {
                        cur = um[cur];
                    }
                    if (mat[cur.first][cur.second] != target[i][j]) {
                        res = false;
                        break;
                    }
                }
                if (!res)
                    break;
            }
            if (res)
                return true;
        }
        return false;
    }
};
// @lc code=end
