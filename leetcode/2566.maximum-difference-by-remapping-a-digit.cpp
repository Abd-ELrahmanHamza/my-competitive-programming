/*
 * @lc app=leetcode id=2566 lang=cpp
 *
 * [2566] Maximum Difference by Remapping a Digit
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int minMaxDifference(int num)
    {
        int minE = num, maxE = num;
        for (int i = 0; i < 10; i++)
        {
            int curNum = num;
            int resMax = 0, resMin = 0;
            int j = 0;
            while (curNum)
            {
                int digit = curNum % 10;
                curNum /= 10;
                cout << "digit= " << digit << endl;
                if (digit == i)
                {
                    cout << "oo\n";
                    resMax += pow(10, j) * 9;
                    resMin += pow(10, j) * 0;
                }
                else
                {
                    resMax += pow(10, j) * digit;
                    resMin += pow(10, j) * digit;
                }
                j++;
            }
            cout << "replace " << i << " " << resMax << " " << resMin << endl;
            minE = min(minE, resMin);
            maxE = max(maxE, resMax);
        }
        cout << maxE << " " << minE << endl;
        return maxE - minE;
    }
};

int main()
{
    Solution sol;
    auto res = sol.minMaxDifference(11891);
    cout << " res = " << res << endl;
    return 0;
}
// @lc code=end
