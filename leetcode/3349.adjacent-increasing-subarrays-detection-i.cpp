
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k)
    {
        vector<int> f(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                f[i] = f[i - 1] + 1;
            }
            if (f[i] >= k && i - k >= 0 && f[i - k] >= k)
                return true;
        }
        return false;
    }
};
