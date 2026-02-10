#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestBalanced(vector<int>& nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            set<int> evens, odds;
            for (int j = i; j <= n; j++) {
                if (nums[j - 1] % 2 == 0)
                    evens.insert(nums[j - 1]);
                else
                    odds.insert(nums[j - 1]);
                if (evens.size() == odds.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};