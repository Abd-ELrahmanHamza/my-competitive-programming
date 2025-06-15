/*
 * @lc app=leetcode id=1432 lang=cpp
 *
 * [1432] Max Difference You Can Get From Changing an Integer
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxDiff(int num)
    {
        int minE = num, maxE = num;
        int firstDigit = num;
        while (firstDigit > 9)
        {
            firstDigit /= 10;
        }
        for (int i = 0; i < 10; i++)
        {
            int curNum = num;
            int resMax = 0, resMin = 0;
            int j = 0;
            while (curNum)
            {
                int digit = curNum % 10;
                curNum /= 10;

                if (digit == i)
                {
                    resMax += pow(10, j) * 9;
                    if (digit == firstDigit)
                    {
                        resMin += pow(10, j) * 1;
                    }
                    else
                    {
                        resMin += pow(10, j) * 0;
                    }
                }
                else
                {
                    resMax += pow(10, j) * digit;
                    resMin += pow(10, j) * digit;
                }
                j++;
            }
            minE = min(minE, resMin);
            maxE = max(maxE, resMax);
        }
        return maxE - minE;
    }
};

int main()
{
    Solution sol;
    auto res = sol.maxDiff(9);
    cout << " res = " << res << endl;
    return 0;
}
// @lc code=end
