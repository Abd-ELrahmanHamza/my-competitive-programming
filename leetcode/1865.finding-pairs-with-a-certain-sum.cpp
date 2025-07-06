/*
 * @lc app=leetcode id=1865 lang=cpp
 *
 * [1865] Finding Pairs With a Certain Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class FindSumPairs
{
  public:
    unordered_map<int, int> freq1, freq2;
    vector<int> n2;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i : nums1)
        {
            freq1[i]++;
        }
        for (int i : nums2)
        {
            freq2[i]++;
        }
        n2 = nums2;
    }

    void add(int index, int val)
    {
        freq2[n2[index]]--;
        freq2[n2[index] + val]++;
        n2[index] += val;
    }

    int count(int tot)
    {
        int res = 0;
        for (auto p : freq1)
        {
            res += p.second * freq2[tot - p.first];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end
