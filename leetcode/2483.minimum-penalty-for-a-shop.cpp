/*
 * @lc app=leetcode id=2483 lang=cpp
 *
 * [2483] Minimum Penalty for a Shop
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers)
    {
        int ans = 0, curScore = 0, maxScore = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                curScore++;
            } else {
                curScore--;
            }
            if (curScore > maxScore) {
                ans = i + 1;
                maxScore = curScore;
            }
        }
        return ans;
    }
};
// @lc code=end
