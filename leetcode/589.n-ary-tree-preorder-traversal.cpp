/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start

// Definition for a Node.
class Node
{
  public:
    int val;
    vector<Node *> children;

    Node()
    {
    }

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> trav;
    void traverse(Node *root)
    {
        if (!root)
            return;
        trav.push_back(root->val);
        for (auto node : root->children)
        {
            traverse(node);
        }
    }
    vector<int> preorder(Node *root)
    {
        traverse(root);
        return trav;
    }
};
// @lc code=end
