/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n)
    {
        char maxC = '0';
        for (char c : n) {
            maxC = max(maxC, c);
        }
        return maxC - '0';
    }
};
// @lc code=end
