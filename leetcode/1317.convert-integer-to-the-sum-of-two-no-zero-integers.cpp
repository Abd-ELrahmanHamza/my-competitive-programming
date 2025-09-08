/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkZeros(int x)
    {
        while (x) {
            int y = x % 10;
            x /= 10;
            if (y == 0)
                return true;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        int a = 1, b = n - 1;
        while (a <= b) {
            if (!checkZeros(a) && !checkZeros(b)) {
                return { a, b };
            }
            a++;
            b--;
        }
        return { -1, -1 };
    }
};
// @lc code=end
