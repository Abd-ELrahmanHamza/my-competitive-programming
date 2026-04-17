#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getRev(int x)
    {
        int rev = 0;
        while (x) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums)
    {
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto p : um) {
            int rev = getRev(p.first);
            if (um.find(rev) == um.end())
                continue;
            for (int idx : p.second) {
                auto gIt = upper_bound(um[rev].begin(), um[rev].end(), idx);
                if (gIt == um[rev].end())
                    continue;
                if (idx != *gIt)
                    ans = min(ans, abs(idx - *gIt));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};