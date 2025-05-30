/*
 * @lc app=leetcode id=3372 lang=cpp
 *
 * [3372] Maximize the Number of Target Nodes After Connecting Trees I
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> adj1, adj2;
    void dfs(int node, int k, int &res, vector<vector<int>> &adj, int parent)
    {
        if (k < 0)
            return;
        res++;
        for (int child : adj[node])
        {
            if (child == parent)
                continue;
            dfs(child, k - 1, res, adj, node);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        adj1 = vector<vector<int>>(edges1.size() + 1);
        adj2 = vector<vector<int>>(edges2.size() + 1);
        for (int i = 0; i < edges1.size(); i++)
        {
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for (int i = 0; i < edges2.size(); i++)
        {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }
        int maxNode2 = 0;
        for (int i = 0; i < adj2.size(); i++)
        {
            int res = 0;
            dfs(i, k - 1, res, adj2, -1);
            maxNode2 = max(maxNode2, res);
        }
        vector<int> result(adj1.size());
        for (int i = 0; i < adj1.size(); i++)
        {
            int res = 0;
            dfs(i, k, res, adj1, -1);
            result[i] = res + maxNode2;
        }
        return result;
    }
};
// @lc code=end
