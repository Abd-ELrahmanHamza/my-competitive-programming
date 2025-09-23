/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1, v2;
        int i = 0;
        string s;
        while (i < version1.size()) {
            if (version1[i] != '.')
                s += version1[i];
            else {
                v1.push_back(stoi(s));
                s = "";
            }
            i++;
        }
        v1.push_back(stoi(s));
        i = 0;
        s = "";
        while (i < version2.size()) {
            if (version2[i] != '.')
                s += version2[i];
            else {
                v2.push_back(stoi(s));
                s = "";
            }
            i++;
        }
        v2.push_back(stoi(s));
        int s1 = v1.size(), s2 = v2.size();
        if (s1 < s2) {
            for (int i = 0; i < s2 - s1; i++) {
                v1.push_back(0);
            }
        }
        if (s1 > s2) {
            for (int i = 0; i < s1 - s2; i++) {
                v2.push_back(0);
            }
        }
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] < v2[i])
                return -1;
            if (v1[i] > v2[i])
                return 1;
        }
        return 0;
    }
};
// @lc code=end
