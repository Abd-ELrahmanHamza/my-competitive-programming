#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getRev(int x)
    {
        int rev = 0;
        while (x) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n)
    {
        return abs(n - getRev(n));
    }
};