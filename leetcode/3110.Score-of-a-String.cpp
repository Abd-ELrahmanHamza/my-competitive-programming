#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int scoreOfString(string s)
    {
        int res = 0, n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            res += abs(s[i] - s[i + 1]);
        }
        return res;
    }
};
