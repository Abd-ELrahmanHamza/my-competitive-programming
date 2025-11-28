/*
 * @lc app=leetcode id=2872 lang=cpp
 *
 * [2872] Maximum Number of K-Divisible Components
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cnt;
    vector<vector<int>> adjList;
    vector<bool> visited;
    long long dfs(int node, vector<vector<int>>& adjList, vector<int>& values, int k)
    {
        long long curS = values[node];
        visited[node] = true;
        for (int child : adjList[node]) {
            if (!visited[child]) {
                curS += dfs(child, adjList, values, k);
            }
        }
        if (curS % k == 0) {
            cnt++;
            return 0;
        }
        return curS;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
    {
        cnt = 0;
        visited = vector<bool>(n);
        adjList = vector<vector<int>>(n);
        for (auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        dfs(0, adjList, values, k);
        return cnt;
    }
};
// @lc code=end
