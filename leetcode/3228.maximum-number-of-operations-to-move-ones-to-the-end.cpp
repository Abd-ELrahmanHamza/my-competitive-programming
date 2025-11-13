/*
 * @lc app=leetcode id=3228 lang=cpp
 *
 * [3228] Maximum Number of Operations to Move Ones to the End
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(string s)
    {
        int cnt1 = 0, i = 0, res = 0;
        while (i < s.size()) {
            while (s[i] == '1') {
                i++;
                cnt1++;
            }
            if (i < s.size()) {
                res += cnt1;
            }
            while (s[i] == '0') {
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

/**
 * 
 * 
 * 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(list<pair<int, int>>& indices)
    {
    }
    int maxOperations(string s)
    {
        list<pair<int, int>> indices;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                indices.push_back({ i, 1 });
        }
        indices.push_back({ s.size(), 1 });
        // merge(indices);
        int res = 0;
        bool changed = true;
        while (changed) {
            changed = false;
            auto it = indices.begin();
            for (++it; it != indices.end(); it++) {
                auto elem = it--;
                if (elem->first > it->first + 1) {
                    res += it->second;
                    elem->second += it->second;
                    indices.erase(it);
                    changed = true;
                    break;
                } else {
                    elem->second += it->second;
                    indices.erase(it);
                }
                it = elem;
            }
        }
        return res;
    }
};
// @lc code=end
 */