/*
 * @lc app=leetcode id=3074 lang=cpp
 *
 * [3074] Apple Redistribution into Boxes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        int ans = 0, cap = 0;
        sort(capacity.begin(), capacity.end(), greater<int>());
        int app = accumulate(apple.begin(), apple.end(), 0);
        while (cap < app) {
            cap += capacity[ans];
            ans++;
        }
        return ans;
    }
};
// @lc code=end
