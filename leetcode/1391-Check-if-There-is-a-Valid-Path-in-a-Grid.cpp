#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
  bool hasValidPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    dfs(grid, visited, 0, 0);
    return visited[n - 1][m - 1];
  }

  void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i,
           int j) {
    int n = grid.size(), m = grid[0].size();
    visited[i][j] = true;
    switch (grid[i][j]) {
    case 1:
      if (j + 1 < m &&
          (grid[i][j + 1] == 5 || grid[i][j + 1] == 3 || grid[i][j + 1] == 1)) {
        if (!visited[i][j + 1]) {
          dfs(grid, visited, i, j + 1);
        }
      }
      if (j - 1 >= 0 &&
          (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6)) {
        if (!visited[i][j - 1]) {
          dfs(grid, visited, i, j - 1);
        }
      }
      break;
    case 2:
      if (i + 1 < n &&
          (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 || grid[i + 1][j] == 2)) {
        if (!visited[i + 1][j]) {
          dfs(grid, visited, i + 1, j);
        }
      }
      if (i - 1 >= 0 &&
          (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 || grid[i - 1][j] == 2)) {
        if (!visited[i - 1][j]) {
          dfs(grid, visited, i - 1, j);
        }
      }
      break;
    case 3:
      if (i + 1 < n &&
          (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 || grid[i + 1][j] == 2)) {
        if (!visited[i + 1][j]) {
          dfs(grid, visited, i + 1, j);
        }
      }
      if (j - 1 >= 0 &&
          (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6)) {
        if (!visited[i][j - 1]) {
          dfs(grid, visited, i, j - 1);
        }
      }
      break;
    case 4:
      if (j + 1 < m &&
          (grid[i][j + 1] == 5 || grid[i][j + 1] == 3 || grid[i][j + 1] == 1)) {
        if (!visited[i][j + 1]) {
          dfs(grid, visited, i, j + 1);
        }
      }
      if (i + 1 < n &&
          (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 || grid[i + 1][j] == 2)) {
        if (!visited[i + 1][j]) {
          dfs(grid, visited, i + 1, j);
        }
      }
      break;
    case 5:
      if (i - 1 >= 0 &&
          (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 || grid[i - 1][j] == 2)) {
        if (!visited[i - 1][j]) {
          dfs(grid, visited, i - 1, j);
        }
      }
      if (j - 1 >= 0 &&
          (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6)) {
        if (!visited[i][j - 1]) {
          dfs(grid, visited, i, j - 1);
        }
      }
      break;
    case 6:
      if (j + 1 < m &&
          (grid[i][j + 1] == 5 || grid[i][j + 1] == 3 || grid[i][j + 1] == 1)) {
        if (!visited[i][j + 1]) {
          dfs(grid, visited, i, j + 1);
        }
      }
      if (i - 1 >= 0 &&
          (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 || grid[i - 1][j] == 2)) {
        if (!visited[i - 1][j]) {
          dfs(grid, visited, i - 1, j);
        }
      }
      break;
    }
  }
};
