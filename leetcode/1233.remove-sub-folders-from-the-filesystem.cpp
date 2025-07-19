/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    unordered_map<string, Node *> children;
    bool isLeaf;
    Node()
    {
        isLeaf = false;
    }
    void insert(string &s, int idx)
    {
        if (idx == s.size())
        {
            isLeaf = true;
            return;
        }
        idx++;

        string curDir;
        while (idx < s.size() && s[idx] != '/')
            curDir += s[idx++];
        if (!children[curDir])
            children[curDir] = new Node();
        children[curDir]->insert(s, idx);
    }
};

class Solution
{
  public:
    vector<string> res;
    void solve(Node *node, string curPath)
    {
        if (node->isLeaf)
        {
            res.push_back(curPath);
            return;
        }
        for (auto childP : node->children)
        {
            solve(childP.second, curPath + "/" + childP.first);
        }
    }
    vector<string> removeSubfolders(vector<string> &folder)
    {
        Node *node = new Node();
        for (string dir : folder)
        {
            node->insert(dir, 0);
        }
        solve(node, "");
        return res;
    }
};
// @lc code=end
