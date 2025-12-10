#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPermutations(vector<int>& complexity)
    {
        long long res = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= complexity[0])
                return 0;
        }
        for (int i = 1; i <= complexity.size() - 1; i++) {
            res = ((res % mod) * (i)) % mod;
        }
        return res;
    }
};