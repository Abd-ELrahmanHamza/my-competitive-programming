/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int compress(vector<char> &chars)
    {
        int curCnt = 1;
        int res = 0;
        int curIdx = 0;
        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == chars[i - 1])
            {
                curCnt++;
            }
            else
            {
                int toAdd = (curCnt == 1 ? 0 : floor(log10(curCnt)) + 1);
                int toAdd2 = toAdd;
                res += 1 + toAdd;
                chars[curIdx] = chars[i - 1];
                curIdx++;
                if (curCnt > 1)
                {
                    while (curCnt)
                    {
                        chars[curIdx + toAdd-- - 1] = curCnt % 10 + '0';
                        curCnt /= 10;
                    }
                }
                curIdx += toAdd2;
                curCnt = 1;
            }
        }
        int toAdd = (curCnt == 1 ? 0 : floor(log10(curCnt)) + 1);
        int toAdd2 = toAdd;
        res += 1 + toAdd;
        chars[curIdx] = chars[chars.size() - 1];
        curIdx++;
        if (curCnt > 1)
        {
            while (curCnt)
            {
                chars[curIdx + toAdd-- - 1] = curCnt % 10 + '0';
                curCnt /= 10;
            }
        }
        return res;
    }
};
// @lc code=end
