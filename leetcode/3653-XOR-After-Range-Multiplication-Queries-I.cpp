#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int xr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xr = xr ^ nums[i];
        }
        for (auto& q : queries) {
            for (int i = q[0]; i <= q[1]; i += q[2]) {
                xr = xr ^ nums[i];
                nums[i] = ((long long)nums[i] * q[3]) % int(1e9 + 7);
                xr = xr ^ nums[i];
            }
        }
        return xr;
    }
};