/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortVowels(string s)
    {
        vector<char> v;
        for (char c : s) {
            char x = tolower(c);
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            char x = tolower(s[i]);
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                s[i] = v[j++];
            }
        }
        return s;
    }
};
// @lc code=end
