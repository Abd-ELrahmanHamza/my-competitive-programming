/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int candy(vector<int> &ratings)
    {
        unordered_map<int, vector<int>> um;
        int maxRating = 0;
        for (int i = 0; i < ratings.size(); i++)
        {
            maxRating = max(maxRating, ratings[i]);
            um[ratings[i]].push_back(i);
        }
        vector<int> candies(ratings.size());
        int sum = 0;
        for (int i = 0; i <= maxRating; i++)
        {
            for (int j = 0; j < um[i].size(); j++)
            {
                candies[um[i][j]] = 1;
                int left = INT_MAX, right = INT_MAX;
                if (um[i][j] != 0)
                    left = ratings[um[i][j] - 1];
                if (um[i][j] != ratings.size() - 1)
                    right = ratings[um[i][j] + 1];
                if (ratings[um[i][j]] > left)
                    candies[um[i][j]] = candies[um[i][j] - 1] + 1;
                if (ratings[um[i][j]] > right)
                    candies[um[i][j]] = max(candies[um[i][j]], candies[um[i][j] + 1] + 1);
                sum += candies[um[i][j]];
            }
        }
        return sum;
    }
};

// @lc code=end
