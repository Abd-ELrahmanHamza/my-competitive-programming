/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> solve(char lastC, int idx, const int n)
    {
        if (idx >= n)
            return { "" };
        vector<string> res;
        for (char c : { 'a', 'b', 'c' }) {
            if (lastC != c) {
                auto v = solve(c, idx + 1, n);
                for (auto& s : v)
                    s = c + s;
                res.insert(res.end(), v.begin(), v.end());
            }
        }
        return res;
    }
    string getHappyString(int n, int k)
    {
        auto res = solve(-1, 0, n);
        for (auto s : res)
            cout << s << endl;
        if (k - 1 >= res.size())
            return "";
        return res[k - 1];
    }
};
// @lc code=end
