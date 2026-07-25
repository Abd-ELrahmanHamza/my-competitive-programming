#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
  int maxProduct(int n) {
    int d1 = 0, d2 = 0;
    while (n) {
      if (n % 10 > d1) {
        if (d1 > d2)
          d2 = d1;
        d1 = n % 10;
      } else if (n % 10 > d2) {
        d2 = n % 10;
      }
      n /= 10;
    }
    return d1 * d2;
  }
};
