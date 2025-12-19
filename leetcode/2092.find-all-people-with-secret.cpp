/*
 * @lc app=leetcode id=2092 lang=cpp
 *
 * [2092] Find All People With Secret
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adjList, set<int>& whoInConn, set<int>& whoKnow, int node)
    {
        bool res = whoKnow.count(node);
        whoInConn.insert(node);
        for (int child : adjList[node]) {
            if (whoInConn.count(child) == 0) {
                res = dfs(adjList, whoInConn, whoKnow, child) || res;
            }
        }
        return res;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        map<int, unordered_map<int, vector<int>>> adjLists;
        set<int> whoKnow;
        for (auto& v : meetings) {
            adjLists[v[2]][v[0]].push_back(v[1]);
            adjLists[v[2]][v[1]].push_back(v[0]);
        }
        whoKnow.insert(0), whoKnow.insert(firstPerson);
        for (auto& p : adjLists) {
            queue<int> q;
            for (auto& node : p.second) {
                if (whoKnow.count(node.first)) {
                    q.push(node.first);
                }
            }
            while (!q.empty()) {
                int t = q.front();
                whoKnow.insert(t);
                q.pop();
                for (int child : p.second[t]) {
                    if (whoKnow.count(child) == 0) {
                        q.push(child);
                    }
                }
            }
        }
        return vector<int>(whoKnow.begin(), whoKnow.end());
    }
};
// @lc code=end
