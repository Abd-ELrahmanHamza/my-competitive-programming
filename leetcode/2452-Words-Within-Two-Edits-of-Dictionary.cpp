#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> twoEditWords(vector<string> &queries,
                              vector<string> &dictionary) {
    vector<string> res;
    for (int i = 0; i < queries.size(); i++) {
      for (int j = 0; j < dictionary.size(); j++) {
        int cnt = 0;
        for (int k = 0; k < queries[i].size(); k++) {
          cnt += queries[i][k] == dictionary[j][k];
        }
        if (queries[i].size() - cnt <= 2) {
          res.push_back(queries[i]);
          break;
        }
      }
    }
    return res;
  }
};
