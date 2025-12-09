#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int specialTriplets(vector<int>& nums)
    {
        unordered_map<int, int> total_cnt, curCnt;
        for (int i = 0; i < nums.size(); i++) {
            total_cnt[nums[i]]++;
        }
        long long ans = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < nums.size(); i++) {
            int el = nums[i] * 2;
            long long before = curCnt[el];
            long long after = total_cnt[el] - before;
            curCnt[nums[i]]++;
            if (el == nums[i])
                after--;
            ans = (ans % mod + (after * before) % mod) % mod;
        }
        return ans;
    }
};