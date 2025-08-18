/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const double EPS = 1e-6;
    bool solve(vector<double>& cards)
    {
        if (cards.size() == 1) {
            return fabs(cards[0] - 24.0) < EPS;
        }
        for (int i = 0; i < cards.size(); i++) {
            for (int j = i+1; j < cards.size(); j++) {
                vector<double> res;
                for (int k = 0; k < cards.size(); k++) {
                    if (k != i && k != j)
                        res.push_back(cards[k]);
                }
                for (double x : comp(cards[i], cards[j])) {
                    res.push_back(x);
                    if (solve(res))
                        return true;
                    res.pop_back();
                }
            }
        }
        return false;
    }
    vector<double> comp(double x, double y)
    {
        vector<double> v;
        v.push_back(x + y);
        v.push_back(x - y);
        v.push_back(y - x);
        v.push_back(y * x);
        if (fabs(x) > EPS)
            v.push_back(y / x);
        if (fabs(y) > EPS)
            v.push_back(x / y);
        return v;
    }
    bool judgePoint24(vector<int>& cards)
    {
        vector<double> v = { (double)cards[0], (double)cards[1], (double)cards[2], (double)cards[3] };
        return solve(v);
    }
};
// @lc code=end
