#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
  bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
    sort(asteroids.begin(), asteroids.end());
    long long massL = mass;
    for (const int &x : asteroids) {
      if (massL >= x)
        massL += x;
      else
        return false;
    }
    return true;
  }
};
