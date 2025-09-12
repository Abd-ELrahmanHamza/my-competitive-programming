/*
 * @lc app=leetcode id=3227 lang=cpp
 *
 * [3227] Vowels Game in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool doesAliceWin(string& s)
    {
        for (char& c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
