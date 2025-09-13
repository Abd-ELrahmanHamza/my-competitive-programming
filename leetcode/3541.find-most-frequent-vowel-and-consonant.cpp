/*
 * @lc app=leetcode id=3541 lang=cpp
 *
 * [3541] Find Most Frequent Vowel and Consonant
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreqSum(string s)
    {
        vector<int> v(26);
        int maxV = 0, maxC = 0;
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                maxV = max(maxV, v[s[i] - 'a']);
            } else {
                maxC = max(maxC, v[s[i] - 'a']);
            }
        }
        return maxV + maxC;
    }
};
// @lc code=end
