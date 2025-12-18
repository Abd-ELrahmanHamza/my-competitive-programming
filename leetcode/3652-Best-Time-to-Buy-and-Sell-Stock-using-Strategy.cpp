#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k)
    {
        long long ans = 0, n = prices.size();
        for (int i = 0; i < n; i++) {
            ans += prices[i] * strategy[i];
        }
        
        long long curS = ans;
        for (int i = 0; i < k / 2; i++) {
            curS -= prices[i] * strategy[i];
        }

        for (int i = k / 2; i < k; i++) {
            curS -= prices[i] * strategy[i];
            curS += prices[i];
        }
        ans = max(ans, curS);

        int i = k / 2;
        while (i + k / 2 < n) {
            int first = i - k / 2;
            int last = i + k / 2 - 1;
            int nextLast = last + 1;
            int nextMid = i;

            curS += prices[first] * strategy[first];
            curS -= prices[nextLast] * strategy[nextLast];
            curS += prices[nextLast];
            curS -= prices[nextMid];

            ans = max(ans, curS);
            i++;
        }
        return ans;
    }
};