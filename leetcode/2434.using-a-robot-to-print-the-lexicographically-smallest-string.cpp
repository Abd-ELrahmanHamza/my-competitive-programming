/*
 * @lc app=leetcode id=2434 lang=cpp
 *
 * [2434] Using a Robot to Print the Lexicographically Smallest String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct CustomCompare
{
    bool operator()(const pair<char, int> &a, const pair<char, int> &b)
    {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};

class Solution
{
  public:
    string robotWithString(string s)
    {
        stack<char> st;
        string res;
        int idx = 0;
        char minChar = 'a';
        vector<int> freq(26);
        for (char c : s)
            freq[c - 'a']++;
        while (res.size() < s.size())
        {
            while (minChar < 'z' && freq[minChar - 'a'] == 0)
                minChar++;
            if (st.empty() && idx < s.size())
            {
                st.push(s[idx]);
                freq[s[idx] - 'a']--;
                idx++;
            }
            else if (st.top() <= minChar)
            {
                res += st.top();
                st.pop();
            }
            else if (st.top() > minChar)
            {
                while (s[idx] != minChar)
                {
                    st.push(s[idx]);
                    freq[s[idx] - 'a']--;
                    idx++;
                }
                st.push(s[idx]);
                freq[s[idx] - 'a']--;
                idx++;
            }
        }
        return res;
    }
};

// @lc code=end
