#include "bits/stdc++.h"
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    vector<int> freq(26);
    for (char x : word)
      freq[x - 'a']++;
    sort(freq.begin(), freq.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < 8; i++) {
      ans += freq[i];
    }
    for (int i = 8; i < 16; i++) {
      ans += freq[i] * 2;
    }
    for (int i = 16; i < 24; i++) {
      ans += freq[i] * 3;
    }
    for (int i = 24; i < 26; i++) {
      ans += freq[i] * 4;
    }
    return ans;
  }
};
