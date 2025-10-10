/*
 * @lc app=leetcode id=3147 lang=cpp
 *
 * [3147] Taking Maximum Energy From the Mystic Dungeon
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k)
    {
        for (int i = energy.size() - k; i >= 0; i--) {
            if (i + k < energy.size()) {
                energy[i] += energy[i + k];
            }
        }
        return *max_element(energy.begin(), energy.end());
    }
};
// @lc code=end
