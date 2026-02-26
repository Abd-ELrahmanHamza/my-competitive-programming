/*
 * @lc app=leetcode id=1404 lang=cpp
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSteps(string s)
    {
        int ans = 0;
        int i = s.size() - 1;
        while (i >= 0) {
            while (i >= 0 && s[i] == '0') {
                i--;
                ans++;
            }
            if (i >= 0 && s[i] == '1') {
                if (i == 0)
                    break;
                ans++;
                int j = i;
                while (j >= 0 && s[j] == '1') {
                    s[j] = '0';
                    j--;
                }
                if (j >= 0)
                    s[j] = '1';
            }
        }
        return ans;
    }
};
// @lc code=end
