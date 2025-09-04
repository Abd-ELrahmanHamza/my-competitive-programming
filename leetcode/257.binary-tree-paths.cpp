/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
    void solve(TreeNode* root, string s)
    {
        s += to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(s);
        }
        if (root->left) {
            solve(root->left, s + "->");
        }
        if (root->right) {
            solve(root->right, s + "->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        solve(root, "");
        return res;
    }
};
// @lc code=end
