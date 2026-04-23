#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  struct element {
    long long sum;
    long long cnt;
    element() { sum = 0, cnt = 0; }
  };
  vector<long long> distance(vector<int> &nums) {
    int n = nums.size();
    vector<long long> ans(n);
    unordered_map<int, element> totalUm, um;
    for (int i = 0; i < n; i++) {
      totalUm[nums[i]].sum += i;
      totalUm[nums[i]].cnt++;
    }
    for (int i = 0; i < n; i++) {
      ans[i] = um[nums[i]].cnt * i - um[nums[i]].sum;
      um[nums[i]].sum += i;
      um[nums[i]].cnt++;
      ans[i] += totalUm[nums[i]].sum - um[nums[i]].sum -
                (totalUm[nums[i]].cnt - um[nums[i]].cnt) * i;
    }
    return ans;
  }
};
