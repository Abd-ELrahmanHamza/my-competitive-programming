/*
 * @lc app=leetcode id=2197 lang=cpp
 *
 * [2197] Replace Non-Coprime Numbers in Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<int> replaceNonCoprimes(vector<int>& nums)
    {
        stack<int> s;
        s.push(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            s.push(nums[i]);
            while (s.size() > 1) {
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();
                if (gcd(t1, t2) > 1) {
                    s.push(lcm(t1, t2));
                } else {
                    s.push(t2);
                    s.push(t1);
                    break;
                }
            }
        }
        vector<int> res(s.size());
        int i = s.size() - 1;
        while (!s.empty()) {
            res[i--] = s.top();
            s.pop();
        }
        return res;
    }
};
// @lc code=end
