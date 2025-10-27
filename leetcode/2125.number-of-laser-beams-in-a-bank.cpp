/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank)
    {
        vector<int> numOnes(bank.size());
        for (int i = 0; i < bank.size(); i++) {
            for (int j = 0; j < bank[i].size(); j++) {
                numOnes[i] += bank[i][j] - '0';
            }
        }
        int l = 0, r = 0, res = 0;
        while (r < bank.size()) {
            while (l < bank.size() && numOnes[l] == 0)
                l++;
            r = l + 1;
            while (r < bank.size() && numOnes[r] == 0)
                r++;
            if (l < bank.size() && r < bank.size())
                res += numOnes[l] * numOnes[r];
            l = r;
        }
        return res;
    }
};
// @lc code=end
