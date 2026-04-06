/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int sol = 0;
        sort(obstacles.begin(), obstacles.end());
        int x = 0, y = 0, dir = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                dir = (dir + 1) % 4;
            } else if (commands[i] == -2) {
                dir = ((dir - 1) % 4 + 4) % 4;
            } else {
                bool valid = true;
                for (int j = 0; j < commands[i]; j++) {
                    int newX = x, newY = y;
                    if (dir == 0)
                        newY++;
                    else if (dir == 1)
                        newX++;
                    else if (dir == 2)
                        newY--;
                    else
                        newX--;
                    if (binary_search(obstacles.begin(), obstacles.end(), vector<int> { newX, newY })) {
                        valid = false;
                        break;
                    }
                    x = newX;
                    y = newY;
                    sol = max(sol, newX * newX + newY * newY);
                }
                if (!valid)
                    continue;
            }
        }
        return sol;
    }
};
// @lc code=end
