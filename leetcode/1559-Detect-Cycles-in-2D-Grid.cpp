#include "bits/stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
  }
  bool detectCycle(const vector<vector<char>> &grid,
                   vector<vector<bool>> &visited, int i, int j, const char &c,
                   int prevI, int prevJ) {
    if (visited[i][j])
      return true;
    visited[i][j] = true;
    bool ans = false;
    for (int x : {1, -1}) {
      if (isValid(i + x, j, grid.size(), grid[0].size()) &&
          grid[i + x][j] == c && !(i + x == prevI && j == prevJ)) {
        ans = ans || detectCycle(grid, visited, i + x, j, c, i, j);
      }
      if (isValid(i, j + x, grid.size(), grid[0].size()) &&
          grid[i][j + x] == c && !(i == prevI && j + x == prevJ)) {
        ans = ans || detectCycle(grid, visited, i, j + x, c, i, j);
      }
    }
    return ans;
  }
  bool containsCycle(vector<vector<char>> &grid) {
    vector<vector<bool>> visited(grid.size(),
                                 vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (!visited[i][j]) {
          if (detectCycle(grid, visited, i, j, grid[i][j], -1, -1)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
