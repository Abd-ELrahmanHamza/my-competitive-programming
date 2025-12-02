#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points)
    {
        unordered_map<int, long long> ys;
        long long ans = 0;
        for (auto v : points) {
            ys[v[1]]++;
        }
        long long total_points = 0;
        int MOD = 1e9 + 7;
        for (auto it = ys.begin(); it != ys.end(); it++) {
            long long cur_total_points = ((it->second * (it->second - 1)) / 2) % MOD;
            ans = (ans % MOD + (cur_total_points * total_points) % MOD) % MOD;
            total_points = (total_points % MOD + cur_total_points % MOD) % MOD;
        }
        return ans;
    }
};