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
                string cntStr = to_string(curCnt);
                res += 1 + (curCnt == 1 ? 0 : cntStr.size());

                chars[curIdx] = chars[i - 1];
                curIdx++;
                if (curCnt > 1)
                {
                    for (int j = 0; j < cntStr.size(); j++)
                    {
                        chars[curIdx++] = cntStr[j];
                    }
                }
                curCnt = 1;
            }
        }
        string cntStr = to_string(curCnt);
        chars[curIdx] = chars[chars.size() - 1];
        curIdx++;
        if (curCnt > 1)
        {
            for (int j = 0; j < cntStr.size(); j++)
            {
                chars[curIdx++] = cntStr[j];
            }
        }
        res += 1 + (curCnt == 1 ? 0 : floor(log10(curCnt)) + 1);
        return res;
    }
};
// @lc code=end
