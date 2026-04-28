#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    int n = grid.size() * grid[0].size();
    vector<int> v(n);
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        v[i * grid[0].size() + j] = grid[i][j];
      }
    }
    sort(v.begin(), v.end());
    int median = v[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (abs(v[i] - median) % x != 0) {
        return -1;
      }
      ans += abs(v[i] - median) / x;
    }
    return ans;
  }
};
