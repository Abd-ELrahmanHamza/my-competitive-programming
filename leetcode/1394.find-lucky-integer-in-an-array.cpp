/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int findLucky(vector<int> &arr)
    {
        vector<int> freq(600);
        for (int i : arr)
        {
            freq[i]++;
        }
        for (int i = 599; i > 0; i--)
        {
            if (freq[i] == i)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
