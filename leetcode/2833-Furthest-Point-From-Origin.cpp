#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    int x = 0, y = 0, ans = 0;
    for (int i = 0; i < moves.size(); i++) {
      if (moves[i] == 'L')
        x--;
      else if (moves[i] == 'R')
        x++;
      else
        y++;
    }
    ans = max(ans, max(abs(x - y), abs(x + y)));
    return ans;
  }
};
