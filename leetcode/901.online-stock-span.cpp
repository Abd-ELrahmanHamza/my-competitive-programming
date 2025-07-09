/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{

  public:
    stack<pair<int, int>> s;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int sz = 1;
        while (!s.empty() && s.top().first <= price)
        {
            sz += s.top().second;
            s.pop();
        }
        s.push({price, sz});
        return sz;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
