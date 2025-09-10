/*
 * @lc app=leetcode id=1733 lang=cpp
 *
 * [1733] Minimum Number of People to Teach
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
    {
        int m = languages.size();
        vector<int> canNotCom;
        for (int i = 0; i < m; i++) {
            sort(languages[i].begin(), languages[i].end());
        }
        for (int i = 0; i < friendships.size(); i++) {
            bool can = false;
            for (int j : languages[friendships[i][0] - 1]) {
                if (binary_search(languages[friendships[i][1] - 1].begin(), languages[friendships[i][1] - 1].end(), j)) {
                    can = true;
                    break;
                }
            }
            if (!can) {
                canNotCom.push_back(i);
            }
        }
        int res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            set<int> s;
            for (auto j : canNotCom) {
                auto firstLangs = languages[friendships[j][0] - 1];
                auto secondLangs = languages[friendships[j][1] - 1];
                if (!binary_search(firstLangs.begin(), firstLangs.end(), i)) {
                    s.insert(friendships[j][0]);
                }
                if (!binary_search(secondLangs.begin(), secondLangs.end(), i)) {
                    s.insert(friendships[j][1]);
                }
            }
            res = min(res, (int)s.size());
        }
        return res;
    }
};
// @lc code=end
