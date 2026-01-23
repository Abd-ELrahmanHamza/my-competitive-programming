/*
* @lc app=leetcode id=2265 lang=java
*
* [2265] Count Nodes Equal to Average of Subtree
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

    int ans;

    private int[] sumNodes(TreeNode root) {
        if (root == null) {
            return new int[]{0, 0};
        }
        int[] res1 = sumNodes(root.left);
        int[] res2 = sumNodes(root.right);
        int avg = (root.val + res1[0] + res2[0]) / (1 + res1[1] + res2[1]);
        if (avg == root.val) {
            ans++;
        }
        return new int[]{root.val + res1[0] + res2[0], 1 + res1[1] + res2[1]};
    }

    public int averageOfSubtree(TreeNode root) {
        ans = 0;
        int[] res = sumNodes(root);

        return ans;
    }
}
// @lc code=end

