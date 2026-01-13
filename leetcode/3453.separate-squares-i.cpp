/*
 * @lc app=leetcode id=3453 lang=cpp
 *
 * [3453] Separate Squares I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>>& squares, double mid)
    {
        double left = 0, right = 0;

        for (int i = 0; i < squares.size(); i++) {
            double x = squares[i][0], y = squares[i][1], l = squares[i][2];
            if (y + l <= mid) {
                left += l * l;
            } else if (y >= mid) {
                right += l * l;
            } else {
                left += (mid - y) * l;
                right += l * l - (mid - y) * l;
            }
        }

        return left < right;
    }
    double separateSquares(vector<vector<int>>& squares)
    {
        double y = 0;
        double l = 0, r = 1e10;
        while (abs(l - r) > 0.000001) {
            double mid = l + (r - l) / 2;
            if (check(squares, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end
    