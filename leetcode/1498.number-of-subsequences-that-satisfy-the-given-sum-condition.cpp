/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    const int MOD = 1e9 + 7;

    long long power_of_two_mod(long long n)
    {
        long long result = 1;
        long long base = 2;

        while (n > 0)
        {
            if (n % 2 == 1)
            {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            n /= 2;
        }

        return result;
    }
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i - 1, r = nums.size();
            while (l < r - 1)
            {
                int m = l + (r - l) / 2;
                if (nums[i] + nums[m] <= target)
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            if (l >= i)
            {
                int size = l - i + 1;
                ans += power_of_two_mod(size - 1);
            }
        }
        return ans;
    }
};
// @lc code=end
