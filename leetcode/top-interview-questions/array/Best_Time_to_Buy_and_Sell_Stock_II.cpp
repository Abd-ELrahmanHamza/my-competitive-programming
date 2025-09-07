#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        int curMin = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > curMin) {
                res += prices[i] - curMin;
                curMin = prices[i];
            } else {
                curMin = prices[i];
            }
        }
        return res;
    }
};