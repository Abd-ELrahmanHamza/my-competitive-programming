#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTriples(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int c = sqrt(i * i + j * j);
                if (c * c == (i * i + j * j) && c <= n) {
                    ans++;
                }
            }
        }
        return ans;
    }
};