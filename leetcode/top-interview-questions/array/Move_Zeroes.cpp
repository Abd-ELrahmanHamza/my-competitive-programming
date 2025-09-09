#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int l = 0, r = 0, n = nums.size();
        while (true) {
            while (l < n && nums[l] != 0)
                l++;
            while (r < n && nums[r] == 0)
                r++;
            if (l == n || r == n)
                break;
            if (r <= l) {
                r = l;
                continue;
            }

            swap(nums[l], nums[r]);
        }
    }
};
