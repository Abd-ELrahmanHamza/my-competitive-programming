/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int cnt = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            cnt += flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
                   (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
            flowerbed[i] = (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
        }
        return cnt >= n;
    }
};
// @lc code=end
