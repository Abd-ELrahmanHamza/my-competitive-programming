#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool rotateString(string s, string goal) {
    for (int i = 0; i < s.size(); i++) {
      if (s == goal)
        return true;
      goal.push_back(goal[0]);
      goal.erase(goal.begin());
    }
    return false;
  }
};
