#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x)
    {
        unsigned int res = 0;
        bool isSafe = false, isNeg = x < 0;
        int tempX = x;
        int cntD = 0;
        string limit = "2147483647";
        if (x == -2147483648)
            return 0;
        x = abs(x);
        if (isNeg)
            limit = "2147483648";
        while (tempX) {
            cntD++;
            tempX /= 10;
        }
        int idx = 0;
        while (x) {
            int d = x % 10;
            x /= 10;
            res = res * 10 + d;
            if (cntD == 10 && !isSafe) {
                int lD = limit[idx] - '0';
                if (lD > d) {
                    isSafe = true;
                } else if (lD < d)
                    return 0;
            }
            idx++;
        }
        return isNeg ? -1 * res : res;
    }
};