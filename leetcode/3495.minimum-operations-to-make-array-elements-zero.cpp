/*
 * @lc app=leetcode id=3495 lang=cpp
 *
 * [3495] Minimum Operations to Make Array Elements Zero
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries)
    {
        vector<long long> starts;
        long long x = 1;
        while (x < 1e10) {
            starts.push_back(x);
            x *= 4LL;
        }
        long long res = 0;
        for (int i = 0; i < queries.size(); i++) {
            auto lStart = upper_bound(starts.begin(), starts.end(), queries[i][0]);
            auto rStart = upper_bound(starts.begin(), starts.end(), queries[i][1]);
            if (lStart != starts.begin())
                lStart = prev(lStart);
            if (rStart != starts.begin())
                rStart = prev(rStart);
            long long lStartNumDivs = lStart - starts.begin() + 1;
            long long rStartNumDivs = rStart - starts.begin() + 1;
            cout << *lStart << " " << *rStart << endl;
            if (lStart == rStart) {
                res += ceil(((queries[i][1] - queries[i][0] + 1LL) * lStartNumDivs) / 2.0);
                continue;
            }
            long long curRes = (*lStart * 4LL - queries[i][0]) * lStartNumDivs + (queries[i][1] - *rStart + 1LL) * rStartNumDivs;
            long long between = *lStart * 4LL;
            long long betweenNumberOfDivs = lStartNumDivs + 1LL;
            while (between < *rStart) {
                curRes += (between * 4 - between) * betweenNumberOfDivs;
                between *= 4;
            }
            res += ceil(curRes / 2.0);
        }

        return res;
    }
};
// @lc code=end
