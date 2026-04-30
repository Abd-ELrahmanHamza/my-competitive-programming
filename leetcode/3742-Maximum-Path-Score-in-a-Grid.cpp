#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  long long solve(vector<vector<int>> &grid, vector<vector<vector<int>>> &memo,
                  int k, int i, int j) {
    if (grid[i][j] > 0) {
      k--;
    }
    if (k < 0) {
      return INT_MIN;
    }
    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
      return memo[i][j][k] = grid[i][j];
    }
    if (memo[i][j][k] != INT_MIN) {
      return memo[i][j][k];
    }
    long long down = INT_MIN;
    if (i + 1 < grid.size()) {
      down = solve(grid, memo, k, i + 1, j);
    }

    long long right = INT_MIN;
    if (j + 1 < grid[0].size()) {
      right = solve(grid, memo, k, i, j + 1);
    }
    return memo[i][j][k] = grid[i][j] + max(down, right);
  }

  int maxPathScore(vector<vector<int>> &grid, int k) {
    vector<vector<vector<int>>> memo(
        grid.size(),
        vector<vector<int>>(grid[0].size(), vector<int>(k + 1, INT_MIN)));
    long long ans = solve(grid, memo, k, 0, 0);

    return ans >= 0 ? ans : -1;
  }
};
