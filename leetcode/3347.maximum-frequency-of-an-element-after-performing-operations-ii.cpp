
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct Operation {
        int add = 0, sub = 0;
    };
    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        int n = nums.size();
        map<int, Operation> limits;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int start = max(0, nums[i] - k);
            int end = nums[i] + k;
            freq[nums[i]]++;
            limits[start].add++;
            limits[end + 1].sub++;
            limits[nums[i]].add = limits[nums[i]].add;
        }
        int curCnt = 0;
        int res = 0;
        for (auto p : limits) {
            curCnt += p.second.add - p.second.sub;
            res = max(freq[p.first] + min(curCnt - freq[p.first], numOperations), res);
        }
        return res;
    }
};
