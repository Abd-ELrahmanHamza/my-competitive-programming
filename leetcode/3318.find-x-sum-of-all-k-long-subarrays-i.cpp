/*
 * @lc app=leetcode id=3318 lang=cpp
 *
 * [3318] Find X-Sum of All K-Long Subarrays I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)
    {
        vector<int> occ(51);
        for (int i = 0; i < k; i++) {
            occ[nums[i]]++;
        }
        vector<int> res(nums.size() - k + 1);
        for (int i = 1; i <= nums.size() - k + 1; i++) {
            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < 51; i++) {
                pq.push({ occ[i], i });
            }
            int j = 0, curS = 0;
            while (!pq.empty() && j < x) {
                curS += pq.top().first * pq.top().second;
                pq.pop();
                j++;
            }
            occ[nums[i - 1]]--;
            if (i + k - 1 < nums.size())
                occ[nums[i + k - 1]]++;
            res[i - 1] = curS;
        }
        return res;
    }
};
// @lc code=end
