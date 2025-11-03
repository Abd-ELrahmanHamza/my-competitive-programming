/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int curCnt = 1, maxVal = neededTime[0], curSum = neededTime[0], res = 0;
        int r = 1;
        while (r < colors.size()) {
            curCnt = 1;
            while (r < colors.size() && colors[r] == colors[r - 1]) {
                maxVal = max(maxVal, neededTime[r]);
                curSum += neededTime[r];
                r++;
                curCnt++;
            }
            if (curCnt > 1) {
                res += (curSum - maxVal);
            }
            if (r < colors.size()) {
                maxVal = neededTime[r];
                curSum = neededTime[r];
            }
            r++;
        }
        return res;
    }
};
// @lc code=end
