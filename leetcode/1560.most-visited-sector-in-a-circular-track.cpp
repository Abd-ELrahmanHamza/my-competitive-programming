/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> freq(n + 1);
        freq[rounds[0]]++;
        for (int i = 1; i < rounds.size(); i++) {
            int j = (rounds[i - 1] + 1) %(n+1);
            while (j != rounds[i]) {
                freq[j]++;
                j = (j + 1) % (n + 1);
            }
            freq[rounds[i]]++;
        }
        int maxFreq = 0;
        for (int i = 1; i <= n; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (maxFreq == freq[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};
// @lc code=end
