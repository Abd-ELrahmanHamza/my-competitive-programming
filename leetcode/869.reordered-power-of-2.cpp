/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool reorderedPowerOf2(int n)
    {
        vector<int> v(10);
        while (n) {
            int x = n % 10;
            n /= 10;
            v[x]++;
        }
        for (long long i = 0; i <= 30; i++) {
            long long powOf2 = (1LL << i);
            vector<int> v2(10);
            while (powOf2) {
                int x = powOf2 % 10;
                powOf2 /= 10;
                v2[x]++;
            }
            bool valid = true;
            for (int i = 0; i < 10; i++) {
                if (v[i] != v2[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return true;
        }
        return false;
    }
};
// @lc code=end
