/*
 * @lc app=leetcode id=3307 lang=cpp
 *
 * [3307] Find the K-th Character in String Game II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        int strOrder = ceil(log2(k));
        stack<int> ops;
        if (strOrder != 0)
        {
            ops.push(strOrder);
            k = k - (1LL << (strOrder - 1));
        }
        while (k > 1)
        {
            strOrder = ceil(log2(k));
            ops.push(strOrder);
            k = k - (1LL << (strOrder - 1));
        }
        char c = 0;
        while (!ops.empty())
        {
            int op = ops.top();
            ops.pop();
            if (operations[op - 1])
            {
                c = (c + 1) % 26;
            }
        }
        return c + 'a';
    }
};
// @lc code=end
