#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
  bool canReach(vector<int> &arr, int start) {
    queue<int> q;
    vector<bool> visited(arr.size());
    q.push(start);
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      if (t >= arr.size() || t < 0)
        continue;
      if (arr[t] == 0)
        return true;
      if (visited[t])
        continue;

      visited[t] = true;
      q.push(t + arr[t]);
      q.push(t - arr[t]);
    }
    return false;
  }
};
