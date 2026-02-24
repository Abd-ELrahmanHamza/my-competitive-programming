/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
class Solution {
public:
    int ans;
    void solve(TreeNode* root, int cur)
    {
        if (!root)
            return;
        cur = (cur << 1) | root->val;
        
        if (!root->left && !root->right) {
            ans += cur;
            return;
        }
        solve(root->left, cur);
        solve(root->right, cur);
    }
    int sumRootToLeaf(TreeNode* root)
    {
        ans = 0;
        solve(root, 0);
        return ans;
    }
};
// @lc code=end
