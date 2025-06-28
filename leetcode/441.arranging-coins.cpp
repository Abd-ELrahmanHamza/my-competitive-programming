/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int arrangeCoins(int n)
    {
        long long l = 0, r = n + 1LL;
        while (l < r - 1)
        {
            long long m = l + (r - l) / 2;
            long long cCnt = m * (m + 1) / 2LL;
            if (cCnt <= n)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
// @lc code=end
