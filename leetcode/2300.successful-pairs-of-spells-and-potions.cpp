/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> res(spells.size());
        for (int i = 0; i < spells.size(); i++) {
            long long lb = ceil(success / double(spells[i]));
            auto x = lower_bound(potions.begin(), potions.end(), lb);
            res[i] = potions.end() - x;
        }
        return res;
    }
};
// @lc code=end
