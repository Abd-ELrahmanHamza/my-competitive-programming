/*
 * @lc app=leetcode id=1536 lang=cpp
 *
 * [1536] Minimum Swaps to Arrange a Binary Grid
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid)
    {
        vector<int> v(grid.size(), -1);

        for (int j = 0; j < grid.size(); j++) {
            for (int i = grid[j].size() - 1; i >= 0; i--) {
                if (grid[j][i]) {
                    v[j] = i;
                    break;
                }
            }
        }


        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > i) {
                int j = i;
                while (j < v.size() && v[j] > i)
                    j++;
                if (j == v.size())
                    return -1;
                int k = j;
                while (k > i) {
                    swap(v[k], v[k - 1]);
                    k--;
                }
                ans += j - i;

            }
        }

        return ans;
    }
};
// @lc code=end
