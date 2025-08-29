/*
 * @lc app=leetcode id=3021 lang=cpp
 *
 * [3021] Alice and Bob Playing Flower Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long flowerGame(int n, int m)
    {
        return (ceil(m / 2.0) * (n / 2LL)) + ((m / 2LL) * ceil(n / 2.0));
    }
};

// @lc code=end
