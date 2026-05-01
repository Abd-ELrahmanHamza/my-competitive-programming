#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    int n = nums.size(), total = 0, curF = 0;
    for (int i = 0; i < n; i++) {
      total += nums[i];
      curF += i * nums[i];
    }
    int maxF = curF;
    for (int i = 1; i < n; i++) {
      curF = curF - total + n * nums[i - 1];
      maxF = max(maxF, curF);
    }
    return maxF;
  }
};
