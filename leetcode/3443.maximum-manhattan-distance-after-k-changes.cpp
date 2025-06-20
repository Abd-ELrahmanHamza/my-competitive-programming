/*
 * @lc app=leetcode id=3443 lang=cpp
 *
 * [3443] Maximum Manhattan Distance After K Changes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int cntN = 0, cntS = 0, cntW = 0, cntE = 0, res = 0;
        for (char c : s) {
            if (c == 'S')
                cntS++;
            else if (c == 'N')
                cntN++;
            else if (c == 'W')
                cntW++;
            else
                cntE++;
            int minX = min(cntE, cntW), maxX = max(cntE, cntW),
                minY = min(cntN, cntS), maxY = max(cntN, cntS);
            int k1 = k;
            int invX = 0, invY = 0;
            if (minY < k1) {
                invY = minY;
                k1 -= minY;
            } else {
                invY = k1;
                k1 = 0;
            }
            if (minX < k1) {
                invX = minX;
            } else {
                invX = k1;
            }

            res = max(res, maxX + maxY + invX + invY - (minX - invX) -
                               (minY - invY));
        }
        return res;
    }
};
// @lc code=end
