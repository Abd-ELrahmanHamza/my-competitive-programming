#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        vector<int> taken(baskets.size());
        for (int i = 0; i < fruits.size(); i++) {
            for (int j = 0; j < baskets.size(); j++) {
                if (!taken[j] && baskets[j] >= fruits[i]) {
                    taken[j] = true;
                    break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < taken.size(); i++) {
            res += !taken[i];
        }
        return res;
    }
};