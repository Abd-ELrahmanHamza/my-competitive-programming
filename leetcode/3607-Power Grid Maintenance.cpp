/*
 * @lc app=leetcode id=3321 lang=cpp
 *
 * [3607] Power Grid Maintenance
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<set<int>> sets;
    vector<int> setIdx;
    vector<bool> visited;
    vector<vector<int>> adjList;
    void dfs(int node, int idx)
    {
        visited[node] = true;
        sets[idx].insert(node);
        setIdx[node] = idx;
        for (auto child : adjList[node]) {
            if (!visited[child])
                dfs(child, idx);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {
        adjList = vector<vector<int>>(c + 1);
        visited = vector<bool>(c + 1);
        setIdx = vector<int>(c + 1);
        for (auto conn : connections) {
            adjList[conn[0]].push_back(conn[1]);
            adjList[conn[1]].push_back(conn[0]);
        }
        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                sets.push_back(set<int>());
                dfs(i, sets.size() - 1);
            }
        }
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 2) {
                sets[setIdx[queries[i][1]]].erase(queries[i][1]);
            } else {
                if (sets[setIdx[queries[i][1]]].empty()) {
                    res.push_back(-1);
                } else {
                    if (sets[setIdx[queries[i][1]]].count(queries[i][1]) != 0) {
                        res.push_back(queries[i][1]);
                    } else {
                        res.push_back(*sets[setIdx[queries[i][1]]].begin());
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end