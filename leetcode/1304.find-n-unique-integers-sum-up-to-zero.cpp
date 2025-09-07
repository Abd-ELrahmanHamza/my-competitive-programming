/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n)
    {
        vector<int> res(n);
        int i = 1, j = 0;
        if (n & 1) {
            res[0] = 0;
            j++;
        }
        while (i <= n / 2) {
            res[j++] = i;
            res[j++] = -i;
            i++;
        }
        return res;
    }
};
// @lc code=end
