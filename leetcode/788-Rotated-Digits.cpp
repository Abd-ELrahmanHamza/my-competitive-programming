#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rotatedDigits(int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int x = i;
      bool hasR = false, doesntHaveX = true;
      while (x) {
        int d = x % 10;
        hasR = hasR || (d == 2 || d == 5 || d == 6 || d == 9);
        doesntHaveX = doesntHaveX && !(d == 3 || d == 4 || d == 7);
        x /= 10;
      }
      if (hasR && doesntHaveX) {
        res++;
      }
    }
    return res;
  }
};
