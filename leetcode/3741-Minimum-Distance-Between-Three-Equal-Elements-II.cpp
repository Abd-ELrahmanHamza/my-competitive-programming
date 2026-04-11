#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        vector<vector<int>> mp(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto& v : mp) {
            for (int i = 2; i < v.size(); i++) {
                ans = min(ans, 2 * v[i] - 2 * v[i - 2]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};