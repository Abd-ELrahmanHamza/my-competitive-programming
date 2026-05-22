#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<int> us;
    for (int x : arr1) {
      while (x) {
        us.insert(x);
        x /= 10;
      }
    }
    int ans = 0;
    for (int x : arr2) {
      while (x) {
        if (us.count(x) != 0) {
          ans = max(ans, (int)log10(x) + 1);
        }
        x /= 10;
      }
    }
    return ans;
  }
};
