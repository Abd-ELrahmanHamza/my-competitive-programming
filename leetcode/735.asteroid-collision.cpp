/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s, s2;
        vector<int> res;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0)
            {
                s.push(asteroids[i]);
            }
            else
            {
                while (!s.empty() && s.top() < -1 * asteroids[i])
                {
                    s.pop();
                }
                if (!s.empty() && s.top() == -1 * asteroids[i])
                {
                    s.pop();
                }
                else if (s.empty())
                {
                    res.push_back(asteroids[i]);
                }
            }
        }
        while (!s.empty())
        {
            s2.push(s.top());
            s.pop();
        }
        while (!s2.empty())
        {
            res.push_back(s2.top());
            s2.pop();
        }
        return res;
    }
};
// @lc code=end
