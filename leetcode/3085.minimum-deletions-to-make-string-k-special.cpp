/*
 * @lc app=leetcode id=3085 lang=cpp
 *
 * [3085] Minimum Deletions to Make String K-Special
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int minimumDeletions(string word, int k)
    {
        vector<int> freq(26);
        for (char c : word)
        {
            freq[c - 'a']++;
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            int curRes = 0;
            for (int j = 0; j < 26; j++)
            {
                if (i == j)
                    continue;
                if (freq[i] > freq[j])
                {
                    curRes += freq[j];
                }
                else if (freq[i] + k < freq[j])
                {
                    curRes += freq[j] - freq[i] - k;
                }
            }
            res = min(res, curRes);
        }
        return res;
    }
};
// @lc code=end
