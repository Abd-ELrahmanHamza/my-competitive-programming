#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<pair<int, int>> vp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            vp[i] = { nums[i], i };
        }

        sort(vp.begin(), vp.end());
        int l = 0, r = vp.size() - 1;
        while (l < r) {
            if (vp[l].first + vp[r].first == target) {
                return { vp[l].second, vp[r].second };
            } else if (vp[l].first + vp[r].first > target)
                r--;
            else
                l++;
        }
        return { -1, -1 };
    }
};