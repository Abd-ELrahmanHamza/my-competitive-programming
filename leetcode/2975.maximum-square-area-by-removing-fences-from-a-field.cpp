/*
 * @lc app=leetcode id=2975 lang=cpp
 *
 * [2975] Maximum Square Area by Removing Fences From a Field
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences)
    {
        vector<int> vSegments;
        hFences.push_back(1);
        vFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                vSegments.push_back(vFences[j] - vFences[i]);
            }
        }

        long long res = -1;
        sort(vSegments.begin(), vSegments.end());

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                int x = hFences[j] - hFences[i];
                if (binary_search(vSegments.begin(), vSegments.end(), x)) {
                    res = max(res, (long long)x * x);
                }
            }
        }
        if (res == -1)
            return res;
        return res % (long long)(1e9 + 7);
    }
};
// @lc code=end
