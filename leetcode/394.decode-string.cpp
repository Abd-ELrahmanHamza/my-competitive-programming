/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string solve(string &s, int start, int end)
    {
        int idx = start;
        if (isdigit(s[idx]))
        {
            int cnt = 0;
            while (isdigit(s[idx]))
            {
                cnt = cnt * 10 + (s[idx] - '0');
                idx++;
            }
            int open = 1;
            idx++;
            int newStart = idx;
            while (open)
            {
                if (s[idx] == '[')
                    open++;
                else if (s[idx] == ']')
                    open--;
                idx++;
            }
            string toDup = solve(s, newStart, idx - 2);
            string res;
            for (int i = 0; i < cnt; i++)
            {
                res += toDup;
            }
            string sec = solve(s, idx, end);
            return res + sec;
        }
        else if (isalpha(s[idx]))
        {
            string res;
            while (idx <= end && isalpha(s[idx]))
            {
                res += s[idx];
                idx++;
            }
            return res + solve(s, idx, end);
        }
        else
        {
            // error
            // cout << "invalid: " << start << " end: " << end <<s[start]<<" "<<s[end]<< endl;
        }
        return "";
    }
    string decodeString(string s)
    {
        return solve(s, 0, s.size() - 1);
    }
};
// @lc code=end
