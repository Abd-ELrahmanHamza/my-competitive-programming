#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int res;
    void solve(int num, vector<int>& occ, int idx, int n)
    {
        if (num > n) {
            bool valid = true;
            for (int i = 1; i <= 6; i++) {
                if (occ[i] != 0 && occ[i] != i) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res = min(res, num);
                return;
            }
        }
        if (idx == 7 || ceil(log10(num)) - ceil(log10(n)) >= 2) {
            return;
        }
        for (int i = 1; i <= 6; i++) {
            int newNum = num * 10 + i;
            occ[i]++;
            solve(newNum, occ, idx + 1, n);
            occ[i]--;
        }
    }
    int nextBeautifulNumber(int n)
    {
        res = INT_MAX;
        vector<int> occ(7);
        solve(0, occ, 0, n);
        return res;
    }
};