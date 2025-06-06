/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> groups(26, -1);
        int maxGroup = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (groups[s1[i] - 'a'] == -1 && groups[s2[i] - 'a'] == -1) {
                groups[s1[i] - 'a'] = maxGroup;
                groups[s2[i] - 'a'] = maxGroup;
                maxGroup++;
            } else if (groups[s1[i] - 'a'] == -1 && groups[s2[i] - 'a'] != -1) {
                groups[s1[i] - 'a'] = groups[s2[i] - 'a'];
            } else if (groups[s1[i] - 'a'] != -1 && groups[s2[i] - 'a'] == -1) {
                groups[s2[i] - 'a'] = groups[s1[i] - 'a'];
            } else if (groups[s1[i] - 'a'] != groups[s2[i] - 'a']) {
                int secGroup = groups[s2[i] - 'a'];
                for (int j = 0; j < 26; j++) {
                    if (groups[j] == secGroup) {
                        groups[j] = groups[s1[i] - 'a'];
                    }
                }
            }
        }
        string res;
        for (char c : baseStr) {
            char minC = c;
            if (groups[c - 'a'] == -1) {
                res += c;
                continue;
            }
            for (int i = 'a'; i < c; i++) {
                if (groups[minC - 'a'] == groups[i - 'a']) {
                    minC = i;
                    break;
                }
            }
            res += minC;
        }
        return res;
    }
};

// @lc code=end
