/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalMoney(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            cout << i << " " << ((i - 1) / 7) << endl;
            res += (i - ((i - 1) / 7) * 7) + ((i - 1) / 7);
        }
        return res;
    }
};
// @lc code=end
