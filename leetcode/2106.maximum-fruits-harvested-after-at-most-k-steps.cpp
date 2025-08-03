/*
 * @lc app=leetcode id=2106 lang=cpp
 *
 * [2106] Maximum Fruits Harvested After at Most K Steps
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sol(vector<vector<int>>& fruits, int startPos, int k, int startIdx) {
        int curNum = 0, res = 0;
        int l = startIdx, r = startIdx;
        int lDist = max(0, startPos - fruits[l][0]);
        int rDist = max(0, fruits[r][0] - startPos);
        int dist = lDist + rDist + min(lDist, rDist);
        if (dist > k) {
            return 0;
        }
        while (r < fruits.size()) {
            int lDist = max(0, startPos - fruits[l][0]);
            int rDist = max(0, fruits[r][0] - startPos);
            int dist = lDist + rDist + min(lDist, rDist);
            if (dist > k) {
                break;
            }
            curNum += fruits[r][1];
            res = max(res, curNum);
            r++;
        }
        r--;
        l--;
        while (l >= 0) {
            int lDist = max(0, startPos - fruits[l][0]);
            int rDist = max(0, fruits[r][0] - startPos);
            int dist = lDist + rDist + min(lDist, rDist);
            if (dist > k) {
                if (r > startIdx) {
                    curNum -= fruits[r][1];
                    r--;
                    continue;
                } else {
                    break;
                }
            }
            curNum += fruits[l][1];
            res = max(res, curNum);

            l--;
        }
        return res;
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int startIdx = lower_bound(fruits.begin(), fruits.end(),
                                   vector<int>{startPos, 0}) -
                       fruits.begin();
        if (startIdx == fruits.size())
            startIdx--;
        int res1 = sol(fruits, startPos, k, startIdx);
        int res2 = 0;
        if (startIdx > 0)
            res2 = sol(fruits, startPos, k, startIdx - 1);
        return max(res1, res2);
    }
};
// @lc code=end
