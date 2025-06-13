#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int res = abs(nums[0] - nums[nums.size() - 1]);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            res = max(res, abs(nums[i] - nums[i + 1]));
        }
        return res;
    }
};