/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximum69Number(int num)
    {
        int maxE = num;
        int p10 = 1;
        while (p10 <= num) {
            int curD = (num / p10) % 10;
            if (curD == 6) {
                maxE = max(maxE, num + p10 * 3);
                cout<<num + p10 * 3<<endl;
            }
            p10 *= 10;
        }
        return maxE;
    }
};
// @lc code=end
