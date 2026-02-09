/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
#include <bits/stdc++.h>
using namespace std;
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
class Solution {
public:
    vector<int> vals;
    void extractValues(TreeNode* root)
    {
        if (!root)
            return;
        extractValues(root->left);
        vals.push_back(root->val);
        extractValues(root->right);
    }
    TreeNode* createTree(int l, int r)
    {
        if (l > r)
            return nullptr;
        int mid = (l + r) / 2;
        TreeNode* newNode = new TreeNode(vals[mid]);
        newNode->left = createTree(l, mid - 1);
        newNode->right = createTree(mid + 1, r);
        return newNode;
    }
    TreeNode* balanceBST(TreeNode* root)
    {
        extractValues(root);
        return createTree(0, vals.size() - 1);
    }
};
// @lc code=end
