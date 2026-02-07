/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        vector<int> prefixB(n + 1, 0), suffixA(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixB[i] += prefixB[i - 1] + (s[i - 1] == 'b');
        }
        for (int i = n - 1; i >= 0; i--) {
            suffixA[i] += suffixA[i + 1] + (s[i] == 'a');
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            ans = min(prefixB[i] + suffixA[i], ans);
        }

        return ans;
    }
};
// @lc code=end
