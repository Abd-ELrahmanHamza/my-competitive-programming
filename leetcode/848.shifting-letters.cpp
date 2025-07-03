/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }

        for (int i = 0; i < n; i++) {
            int originalPos = s[i] - 'a';
            int shiftedPos = (originalPos + shifts[i]) % 26;
            s[i] = 'a' + shiftedPos;
        }

        return s;
    }
};

// @lc code=end
