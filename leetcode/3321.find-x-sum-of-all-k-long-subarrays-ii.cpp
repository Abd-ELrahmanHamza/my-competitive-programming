/*
 * @lc app=leetcode id=3321 lang=cpp
 *
 * [3321] Find X-Sum of All K-Long Subarrays II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int> occ;
    multiset<pair<int, int>, greater<>> top_x;
    multiset<pair<int, int>, greater<>> others;

    long long current_x_sum = 0;
    int x_limit;

    void rebalance()
    {
        while (top_x.size() > x_limit) {
            auto it = --top_x.end();
            current_x_sum -= (1LL * it->first * it->second);
            others.insert(*it);
            top_x.erase(it);
        }
        while (top_x.size() < x_limit && !others.empty()) {
            auto it = others.begin();
            current_x_sum += (1LL * it->first * it->second);
            top_x.insert(*it);
            others.erase(it);
        }

        if (!top_x.empty() && !others.empty() && *others.begin() > *--top_x.end()) {
            auto it_others = others.begin();
            auto it_top_x = --top_x.end();

            current_x_sum -= 1LL * it_top_x->first * it_top_x->second;
            current_x_sum += 1LL * it_others->first * it_others->second;

            others.insert(*it_top_x);
            top_x.erase(it_top_x);
            top_x.insert(*it_others);
            others.erase(it_others);
        }
    }

    void update(int val, int delta)
    {
        int old_freq = occ[val];
        int new_freq = old_freq + delta;
        occ[val] = new_freq;

        pair<int, int> old_pair = { old_freq, val };
        pair<int, int> new_pair = { new_freq, val };

        if (old_freq > 0) {
            auto it = top_x.find(old_pair);
            if (it != top_x.end()) {
                current_x_sum -= 1LL * it->first * it->second;
                top_x.erase(it);
            } else {
                auto it_others = others.find(old_pair);
                others.erase(it_others);
            }
        }

        if (new_freq > 0) {
            others.insert(new_pair);
        }

        rebalance();
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x)
    {
        x_limit = x;
        for (int i = 0; i < k; i++) {
            update(nums[i], 1);
        }
        vector<long long> res(nums.size() - k + 1);
        res[0] = current_x_sum;
        for (int i = 1; i <= nums.size() - k; i++) {
            if (nums[i - 1] == nums[i + k - 1]) {
                res[i] = current_x_sum;
                continue;
            }
            update(nums[i - 1], -1);
            update(nums[i + k - 1], 1);
            res[i] = current_x_sum;
        }
        return res;
    }
};
// @lc code=end