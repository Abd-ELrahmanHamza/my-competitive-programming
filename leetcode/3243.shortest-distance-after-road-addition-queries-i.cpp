/*
 * @lc app=leetcode id=3243 lang=cpp
 *
 * [3243] Shortest Distance After Road Addition Queries I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getShortestPath(vector<vector<int>>& paths, int curNode, int n)
    {
        queue<pair<int, int>> q;
        vector<bool> visited(n);
        q.push({ 0, 0 });
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.first == n - 1)
                return t.second;
            if (visited[t.first])
                continue;
            visited[t.first] = true;
            for (int p : paths[t.first]) {
                q.push({ p, t.second + 1 });
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        int m = queries.size();
        vector<vector<int>> paths(n);
        for (int i = 0; i < n - 1; i++) {
            paths[i].push_back(i + 1);
        }
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            paths[queries[i][0]].push_back(queries[i][1]);
            res[i] = getShortestPath(paths, 0, n);
        }
        return res;
    }
};
// @lc code=end
