/*
 * @lc app=leetcode id=3516 lang=cpp
 *
 * [3516] Find Closest Person
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findClosest(int x, int y, int z)
    {
        return abs(z - x) < abs(z - y) ? 1 : abs(z - x) == abs(z - y) ? 0
                                                                      : 2;
    }
};
// @lc code=end
