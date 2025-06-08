/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> res;
    void solve(int num, int digit, int n) {
        int newNum = num * 10 + digit;
        if (newNum > n) {
            return;
        }
        res.push_back(newNum);
        for (int i = 0; i <= 9; i++) {
            solve(newNum, i, n);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            if (i <= n) {
                solve(0, i, n);
            }
        }
        return res;
    }
};


int main()
{
    Solution sol;
    auto res = sol.lexicalOrder(13);
    cout << "res\n";
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << "res\n";

    return 0;
}
// @lc code=end
