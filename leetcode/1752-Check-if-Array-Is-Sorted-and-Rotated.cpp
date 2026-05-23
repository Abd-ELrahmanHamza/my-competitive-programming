#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  bool check(vector<int> &nums) {
    bool foundFirst = false;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        if (nums[i] > nums[0] || foundFirst)
          return false;
        foundFirst = true;
      }
    }
    if (foundFirst) {
      return nums.front() >= nums.back();
    }
    return true;
  }
};
