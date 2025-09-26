/*
 * @lc app=leetcode id=2381 lang=cpp
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts)
    {
        vector<int> shs(s.size() + 1);
        for (int i = 0; i < shifts.size(); i++) {
            if (shifts[i][2] == 1) {
                shs[shifts[i][0]]++;
                shs[shifts[i][1] + 1]--;
            } else {
                shs[shifts[i][0]]--;
                shs[shifts[i][1] + 1]++;
            }
        }
        for (int i = 1; i < shs.size(); i++) {
            shs[i] += shs[i - 1];
        }
        for (int i = 0; i < s.size(); i++) {
            s[i] -= 'a';
            s[i] = ((s[i] + shs[i]) % 26 + 26) % 26;
            s[i] += 'a';
        }
        return s;
    }
};
// @lc code=end
