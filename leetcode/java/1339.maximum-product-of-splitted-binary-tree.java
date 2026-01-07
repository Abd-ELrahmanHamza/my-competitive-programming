/*
 * @lc app=leetcode id=1339 lang=java
 *
 * [1339] Maximum Product of Splitted Binary Tree
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

    long ans = 0;
    long MOD = (long) 1e9 + 7;
    long allS = 0;

    private long allSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return root.val + solve(root.left) + solve(root.right);
    }

    private long solve(TreeNode root) {
        if (root == null) {
            return 0;
        }
        long l = solve(root.left);
        long r = solve(root.right);
        long new1 = (allS - r) * r;
        long new2 = (allS - l) * l;
        ans = Math.max(ans, Math.max(new1, new2));
        return root.val + l + r;
    }

    public int maxProduct(TreeNode root) {
        allS = allSum(root);
        solve(root);
        return (int) (ans % MOD);
    }
}
// @lc code=end

