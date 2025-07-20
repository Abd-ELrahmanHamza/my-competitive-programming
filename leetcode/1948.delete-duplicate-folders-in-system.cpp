/*
 * @lc app=leetcode id=1948 lang=cpp
 *
 * [1948] Delete Duplicate Folders in System
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    map<string, Node *> children;
    string serial;
    void insert(vector<string> &path, int idx)
    {
        if (idx == path.size())
        {
            return;
        }

        if (!children[path[idx]])
            children[path[idx]] = new Node();
        children[path[idx]]->insert(path, idx + 1);
    }
};
class Solution
{
  public:
    unordered_map<string, int> hashFreq;
    vector<vector<string>> res;
    string generateHashs(Node *node)
    {
        string hash;
        for (auto childP : node->children)
        {
            hash += childP.first + "(" + generateHashs(childP.second) + ")";
        }
        node->serial = hash;
        if (!hash.empty())
            hashFreq[hash]++;
        return hash;
    }
    void solve(Node *node, vector<string> path)
    {
        if (hashFreq[node->serial] > 1)
        {
            return;
        }
        if (!path.empty())
            res.push_back(path);

        for (auto childP : node->children)
        {
            path.push_back(childP.first);
            solve(childP.second, path);
            path.pop_back();
        }
        return;
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        Node *root = new Node();
        for (auto path : paths)
        {
            root->insert(path, 0);
        }
        generateHashs(root);
        solve(root, vector<string>());

        return res;
    }
};
// @lc code=end
