/*
 * @lc app=leetcode id=110 lang=java
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    private boolean ans;

    private int solve(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = solve(root.left);
        int r = solve(root.right);
        if (Math.abs(l - r) > 1) {
            ans = false;
        }
        return Math.max(l, r) + 1;
    }

    public boolean isBalanced(TreeNode root) {
        ans = true;
        solve(root);
        return ans;
    }
}
// @lc code=end

