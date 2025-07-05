/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};
class BSTIterator
{
  public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        if (root)
        {
            st.push(root);
            TreeNode *root = st.top();
            while (root->left)
            {
                st.push(root->left);
                root = root->left;
            }
        }
    }

    int next()
    {
        TreeNode *root = st.top();
        st.pop();
        int ret = root->val;
        if (root->right)
        {
            st.push(root->right);
            root = root->right;
            while (root->left)
            {
                st.push(root->left);
                root = root->left;
            }
        }

        return ret;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
