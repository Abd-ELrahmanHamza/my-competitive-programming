#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool isPrime(int n)
    {
        if (n == 2)
            return true;
        if (n < 2 || n % 2 == 0)
            return false;
        int s = sqrt(n);
        for (int i = 3; i <= s; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int nonSpecialCount(int l, int r)
    {
        int sl = ceil(sqrt(l)), sr = sqrt(r);
        int cnt = 0;
        for (int i = sl; i <= sr; i++)
        {
            if (isPrime(i)){
                cnt++;
            }
        }
        return r - l + 1 - cnt;
    }
};