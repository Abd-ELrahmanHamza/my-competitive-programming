/*
 * @lc app=leetcode id=3432 lang=cpp
 *
 * [3432] Count Partitions with Even Sum Difference
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPartitions(vector<int>& nums)
    {
        int s = accumulate(nums.begin(), nums.end(), 0);
        int curS = 0, ans = -1;
        for (int x : nums) {
            curS += x;
            if ((s - 2 * curS) % 2 == 0){
                ans++;
            }
        }
        return max(ans,0);
    }
};
// @lc code=end
