/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void generateNum(vector<int> &nums, int idx, int num, int cnt, vector<int> &res, int maxPossible)
    {
        if (idx >= nums.size())
        {
            if (cnt == 0 && num <= maxPossible)
            {
                res.push_back(num);
            }
            return;
        }

        generateNum(nums, idx + 1, num + nums[idx], cnt - 1, res, maxPossible);
        generateNum(nums, idx + 1, num, cnt, res, maxPossible);
    }
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<int> first = {1, 2, 4, 8}, second = {1, 2, 4, 8, 16, 32};
        vector<string> res;
        for (int i = 0; i <= 4; i++)
        {
            int other = turnedOn - i;
            if (other < 0 || other > 6)
                continue;
            vector<int> firstRes, secondRes;
            generateNum(first, 0, 0, i, firstRes, 11);
            generateNum(second, 0, 0, other, secondRes, 59);
            // firstRes.push_back(0);
            // secondRes.push_back(0);
            for (int i = 0; i < firstRes.size(); i++)
            {
                for (int j = 0; j < secondRes.size(); j++)
                {
                    string otherStr = to_string(secondRes[j]);
                    string str = to_string(firstRes[i]);
                    if (otherStr.size() == 1)
                    {
                        otherStr = "0" + otherStr;
                    }
                    res.push_back(str + ":" + otherStr);
                }
            }
        }
        return res;
    }
};
// @lc code=end
