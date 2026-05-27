#include "bits/stdc++.h"
#include <cctype>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfSpecialChars(string word) {
    vector<int> chars(27, 0);
    int res = 0;
    for (char c : word) {
      if (islower(c)) {
        if (chars[c - 'a'] == 0) {
          chars[c - 'a'] = 1;

        } else if (chars[c - 'a'] == 2) {
          res--;
          chars[c - 'a'] = 3;
        }
      } else {
        if (chars[tolower(c) - 'a'] == 0) {
          chars[tolower(c) - 'a'] = 3;
        } else if (chars[tolower(c) - 'a'] == 1) {
          res++;
          chars[tolower(c) - 'a'] = 2;
        }
      }
    }
    return res;
  }
};
